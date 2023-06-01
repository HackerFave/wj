#include "Widget.h"

#include <QApplication>
#include "QtHttpForC.h"
#include "HttpClient.h"
#include <iostream>
#include <curl/curl.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QtHttpForC w;
    w.show();
    //    HttpClient *http = new HttpClient();
    //        http->getRequest("127.0.0.1", "/login", "id=liukang&pw=123");
    //        http->postRequest("127.0.0.1", "/login", "id=liukang&pw=123");

    //        getchar();

    //    CURL* curl = nullptr;
    //    CURLcode res;

    //    curl = curl_easy_init();
    //    if (curl != nullptr) {

    //      curl_easy_setopt(curl, CURLOPT_URL, "https://baidu.com/");

    //      /* example.com is redirected, so we tell libcurl to follow redirection */
    //      curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

    //      /* Perform the request, res will get the return code */
    //      res = curl_easy_perform(curl);

    //      /* Check for errors */
    //    if (res != CURLE_OK) {
    //      fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
    //      }
    //      /* always cleanup */
    //      curl_easy_cleanup(curl);
    //    }

    //    system("pause");
    //    string strResponse;
    //    std::string host = "http://127.0.0.1:8080";
    //    std::string json = "{-----------------------}}";
    //    CURLcode nRes = httpMethord::HttpPost(host, json,strResponse,300);

    //    std::string host = "http://127.0.0.1:8080?----------------------";
    //    std::string json = "{-----------------------}}";
    //    CURLcode nRes = httpMethord::HttpGet(host, strResponse,300);
    return a.exec();
}



