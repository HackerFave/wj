#ifndef HTTPSERVER_H_
#define HTTPSERVER_H_

#ifndef QT_NETWORK_LIB
#   error("Please add network in pro file")
#endif

#ifndef QT_CONCURRENT_LIB
#   error("Please add concurrent in pro file")
#endif

// C++ lib import
#include <functional>

// Qt lib import
#include <QObject>
#include <QSharedPointer>
#include <QPointer>
#include <QVector>
#include <QMap>
#include <QSet>
#include <QMutex>
#include <QHostAddress>
#include <QUrl>

class QIODevice;
class QThreadPool;
class QHostAddress;
class QTimer;
class QImage;
class QTcpServer;
class QLocalServer;
class QSslCertificate;
class QSslKey;
class QSslConfiguration;

namespace HttpServer
{

class Session: public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY( Session )

public:
    Session( const QPointer< QIODevice > &tcpSocket );

    ~Session();

    inline void setHandleAcceptedCallback(const std::function< void(const QPointer< Session > &) > &callback)
    {
        handleAcceptedCallback_ = callback;
    }

    inline QString requestMethod() const { return requestMethod_; }

    inline QString requestUrl() const { return requestUrl_; }

    inline QString requestCrlf() const { return requestCrlf_; }

    inline QMap< QString, QString > requestHeader() const { return requestHeader_; }

    inline QByteArray requestBody() const { return requestBody_; }

    QString requestUrlPath() const;

    QStringList requestUrlPathSplitToList() const;

    QMap< QString, QString > requestUrlQuery() const;

public slots:
    void replyText(const QString &replyData, const int &httpStatusCode = 200);

    void replyRedirects(const QUrl &targetUrl, const int &httpStatusCode = 200);

    void replyJsonObject(const QJsonObject &jsonObject, const int &httpStatusCode = 200);

    void replyJsonArray(const QJsonArray &jsonArray, const int &httpStatusCode = 200);

    void replyFile(const QString &filePath, const int &httpStatusCode = 200);

    void replyImage(const QImage &image, const int &httpStatusCode = 200);

    void replyImage(const QString &imageFilePath, const int &httpStatusCode = 200);

    void replyBytes(const QByteArray &bytes, const int &httpStatusCode = 200);

    void replyOptions();

private:
    void inspectionBufferSetup1();

    void inspectionBufferSetup2();

private:
    QPointer< QIODevice > ioDevice_;
    std::function< void(const QPointer< Session > &) > handleAcceptedCallback_;
    QSharedPointer< QTimer > timerForClose_;

    QByteArray buffer_;

    QString requestMethod_;
    QString requestUrl_;
    QString requestCrlf_;

    QMap< QString, QString > requestHeader_;
    bool headerAcceptedFinish_ = false;
    qint64 contentLength_ = -1;
    bool alreadyReply_ = false;

    QByteArray requestBody_;

    qint64 waitWrittenByteCount_ = 0;
    QSharedPointer< QIODevice > ioDeviceForReply_;
};

class AbstractManage: public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY( AbstractManage )

public:
    AbstractManage(const int &handleMaxThreadCount);

    virtual ~AbstractManage();

    inline void setHttpAcceptedCallback(const std::function< void(const QPointer< Session > &session) > &httpAcceptedCallback)
    {
        httpAcceptedCallback_ = httpAcceptedCallback;
    }

    inline QSharedPointer< QThreadPool > handleThreadPool() { return handleThreadPool_; }

    inline QSharedPointer< QThreadPool > serverThreadPool() { return serverThreadPool_; }

    virtual bool isRunning() = 0;

protected Q_SLOTS:
    bool begin();

    void close();

protected:
    virtual bool onStart() = 0;

    virtual void onFinish() = 0;

    bool startServerThread();

    void stopHandleThread();

    void stopServerThread();

    void newSession(const QPointer< Session > &session);

    void handleAccepted(const QPointer< Session > &session);

signals:
    void readyToClose();

protected:
    QSharedPointer< QThreadPool > serverThreadPool_;
    QSharedPointer< QThreadPool > handleThreadPool_;

    QMutex mutex_;

    std::function< void(const QPointer< Session > &session) > httpAcceptedCallback_;

    QSet< Session * > availableSessions_;
};

class TcpServerManage: public AbstractManage
{
    Q_OBJECT
    Q_DISABLE_COPY( TcpServerManage )

public:
    TcpServerManage(const int &handleMaxThreadCount = 2);

    ~TcpServerManage();

    bool listen(const QHostAddress &address, const quint16 &port);

private:
    bool isRunning();

    bool onStart();

    void onFinish();

private:
    QPointer< QTcpServer > tcpServer_;

    QHostAddress listenAddress_ = QHostAddress::Any;
    quint16 listenPort_ = 0;
};

#ifndef QT_NO_SSL
class SslServerHelper;

class SslServerManage: public AbstractManage
{
    Q_OBJECT
    Q_DISABLE_COPY( SslServerManage )

public:
    SslServerManage(const int &handleMaxThreadCount = 2);

    ~SslServerManage();

    bool listen(
            const QHostAddress &address,
            const quint16 &port,
            const QString &crtFilePath,
            const QString &keyFilePath,
            const QList< QPair< QString, bool > > &caFileList = { } // [ { filePath, isPem } ]
        );

private:
    bool isRunning();

    bool onStart();

    void onFinish();

private:
    QPointer< SslServerHelper > tcpServer_;

    QHostAddress listenAddress_ = QHostAddress::Any;
    quint16 listenPort_ = 0;

    QSharedPointer< QSslConfiguration > sslConfiguration_;
};
#endif

class LocalServerManage: public AbstractManage
{
    Q_OBJECT
    Q_DISABLE_COPY( LocalServerManage )

public:
    LocalServerManage(const int &handleMaxThreadCount);

    ~LocalServerManage();

    bool listen(const QString &name);

private:
    bool isRunning();

    bool onStart();

    void onFinish();

private:
    QPointer< QLocalServer > localServer_;

    QString listenName_;
};

}

#endif//HTTPSERVER_H_
