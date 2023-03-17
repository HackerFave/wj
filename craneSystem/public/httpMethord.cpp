#include "httpMethord.h"
using namespace std;

httpMethord::httpMethord()
{

}
size_t httpMethord::receive_data(void *contents, size_t size, size_t nmemb, void *stream){
    string *str = (string*)stream;
    (*str).append((char*)contents, size*nmemb);
    return size * nmemb;
}

CURLcode httpMethord::HttpGet(const std::string & strUrl, std::string & strResponse,int nTimeout){
    CURLcode res;
    CURL* pCURL = curl_easy_init();

    if (pCURL == NULL) {
        return CURLE_FAILED_INIT;
    }

    curl_easy_setopt(pCURL, CURLOPT_URL, strUrl.c_str());
    //curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);
    curl_easy_setopt(pCURL, CURLOPT_NOSIGNAL, 1L);
    curl_easy_setopt(pCURL, CURLOPT_TIMEOUT, nTimeout);
    curl_easy_setopt(pCURL, CURLOPT_NOPROGRESS, 1L);
    curl_easy_setopt(pCURL, CURLOPT_WRITEFUNCTION, httpMethord::receive_data);
    curl_easy_setopt(pCURL, CURLOPT_WRITEDATA, (void*)&strResponse);
    res = curl_easy_perform(pCURL);

        if (res != CURLE_OK)
        {
            switch (res)
            {
            case CURLE_UNSUPPORTED_PROTOCOL:
                fprintf(stderr, "不支持的协议,由URL的头部指定\n");
            case CURLE_COULDNT_CONNECT:
                fprintf(stderr, "不能连接到remote主机或者代理\n");
            case CURLE_HTTP_RETURNED_ERROR:
                fprintf(stderr, "http返回错误\n");
            case CURLE_READ_ERROR:
                fprintf(stderr, "读本地文件错误\n");
            default:
                fprintf(stderr, "返回值:%d\n", res);
            }
        }
    curl_easy_cleanup(pCURL);
    return res;
}

CURLcode httpMethord::HttpPost(const std::string & strUrl, std::string szJson,std::string & strResponse,int nTimeout){
    CURLcode res;
    char szJsonData[1024];
    memset(szJsonData, 0, sizeof(szJsonData));
    strcpy(szJsonData, szJson.c_str());
    CURL* pCURL = curl_easy_init();
    struct curl_slist* headers = NULL;
    if (pCURL == NULL) {
        return CURLE_FAILED_INIT;
    }

    CURLcode ret;
    ret = curl_easy_setopt(pCURL, CURLOPT_URL, strUrl.c_str());
//    std::cout << ret << std::endl;

    ret = curl_easy_setopt(pCURL, CURLOPT_POST, 1L);
    headers = curl_slist_append(headers,"content-type:application/json");

    ret = curl_easy_setopt(pCURL, CURLOPT_HTTPHEADER, headers);

    ret = curl_easy_setopt(pCURL, CURLOPT_POSTFIELDS, szJsonData);
    //curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);
    ret = curl_easy_setopt(pCURL, CURLOPT_TIMEOUT, nTimeout);

    ret = curl_easy_setopt(pCURL, CURLOPT_WRITEFUNCTION, httpMethord::receive_data);

    ret = curl_easy_setopt(pCURL, CURLOPT_WRITEDATA, (void*)&strResponse);

    res = curl_easy_perform(pCURL);

        if (res != CURLE_OK)
        {
            switch (res)
            {
            case CURLE_UNSUPPORTED_PROTOCOL:
                fprintf(stderr, "不支持的协议,由URL的头部指定\n");
            case CURLE_COULDNT_CONNECT:
                fprintf(stderr, "不能连接到remote主机或者代理\n");
            case CURLE_HTTP_RETURNED_ERROR:
                fprintf(stderr, "http返回错误\n");
            case CURLE_READ_ERROR:
                fprintf(stderr, "读本地文件错误\n");
            default:
                fprintf(stderr, "返回值:%d\n", res);
            }
        }
    curl_easy_cleanup(pCURL);
    return res;
}
int httpMethord::Posts(const std::string & strUrl, const std::string & strPost, std::string & strResponse, const char * pCaPath)
{
    CURLcode res;
    CURL* curl = curl_easy_init();
    if (NULL == curl)
    {
        return CURLE_FAILED_INIT;
    }
//    if (m_bDebug)
    {
        curl_easy_setopt(curl, CURLOPT_VERBOSE, 1);
//        curl_easy_setopt(curl, CURLOPT_DEBUGFUNCTION, OnDebug);
    }
    curl_easy_setopt(curl, CURLOPT_URL, strUrl.c_str());
    curl_easy_setopt(curl, CURLOPT_POST, 1);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, strPost.c_str());
    curl_easy_setopt(curl, CURLOPT_READFUNCTION, NULL);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, receive_data);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&strResponse);
    curl_easy_setopt(curl, CURLOPT_NOSIGNAL, 1);
    if (NULL == pCaPath)
    {
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, false);
    }
    else
    {
        //缺省情况就是PEM，所以无需设置，另外支持DER
        //curl_easy_setopt(curl,CURLOPT_SSLCERTTYPE,"PEM");
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, true);
        curl_easy_setopt(curl, CURLOPT_CAINFO, pCaPath);
    }
    curl_easy_setopt(curl, CURLOPT_CONNECTTIMEOUT, 3);
    curl_easy_setopt(curl, CURLOPT_TIMEOUT, 3);
    res = curl_easy_perform(curl);
    curl_easy_cleanup(curl);
    return res;
}
