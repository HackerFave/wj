#ifndef HTTPCLIENT_H
#define HTTPCLIENT_H
#include <WinSock2.h>
#include <WS2tcpip.h>
#include <iostream>
using namespace std;

#pragma comment(lib, "ws2_32.lib")
class HttpClient
{
public:
    HttpClient();
    ~HttpClient();

    void socketHttp(std::string host, std::string request);

    void postRequest(std::string host, std::string path, std::string post_content);
    void getRequest(std::string host, std::string path, std::string get_content);


private:
    unsigned short _port = 8080; //端口
    char _revcbuf[1024 * 3];
};

#endif // HTTPCLIENT_H


