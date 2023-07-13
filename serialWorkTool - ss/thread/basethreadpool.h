#ifndef BASETHREADPOOL_H
#define BASETHREADPOOL_H

#include <QObject>
#include <QRunnable>
#include <QDebug>
#include <QThread>
class baseThreadPool : public QObject ,public QRunnable
{
    Q_OBJECT
public:
    explicit baseThreadPool(QObject *parent = nullptr);

    virtual Q_INVOKABLE void startWork()=0;
    virtual Q_INVOKABLE void stopWork()=0;
public slots:
    virtual Q_INVOKABLE void slotWork()=0;
signals:
    Q_INVOKABLE void signalStartWork();

signals:

};

#endif // BASETHREADPOOL_H
