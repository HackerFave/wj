#include <QCoreApplication>
#include <iostream>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    CSerialPort com;

        if(!com.openSyn("COM3", CBR_115200, NOPARITY,8, ONESTOPBIT))
        {
            cout << com.getSerialLastError() << endl;
            getchar();
            return 0;
        }
        //测试发送
        if (com.writeStr("3e 30 01 00"))
        {
            cout << "send success" << endl;
        }
        else
        {
            cout << "send fail" << endl;
        }

        com.closeComm();

    return a.exec();
}
