#ifndef PUBLICCLASS_H
#define PUBLICCLASS_H

#include <QObject>
#include <mutex>
#include <QApplication>
class publicClass : public QObject
{
    Q_OBJECT
private:
    explicit publicClass(QObject *parent = nullptr);
    publicClass & operator=(const publicClass & ) = delete;
    publicClass(const publicClass &) = delete;
public:
    enum C_DirMode{
        dir = 0,
        dirpath
    };
    ~publicClass();
    static publicClass* getInstance(){
        if (P_publicClass == nullptr)
        {
            std::lock_guard<std::mutex> lgd(_mutex);
            if (P_publicClass == nullptr)
            {
                P_publicClass = new publicClass;
            }
        }
        return P_publicClass;
    }
    static void delInstance()
    {
        std::lock_guard<std::mutex> lgd(_mutex);
        if (P_publicClass)
        {
            delete P_publicClass;
            P_publicClass = nullptr;
        }
    }
public:
    QString getExePath();
    bool createFile(const QString &filename);//创建文件
    bool createFileDir(const QString &dirName,C_DirMode flag);//创建文件夹
    bool writeIntoFile(const QString &filename,const QByteArray& data);//写入文件
    QByteArray readFileData(QString filename);//读取文件数据
signals:

private:
    static publicClass *P_publicClass;
    static std::mutex _mutex;
};

#endif // PUBLICCLASS_H
