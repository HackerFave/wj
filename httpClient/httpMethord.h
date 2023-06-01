#ifndef HTTPMETHORD_H
#define HTTPMETHORD_H

#include <iostream>
#include <curl/curl.h>
//#include "zlib.h"
#include <vector>
#include <string>
//#include <unistd.h>
#include <stdint.h>
#include <stdio.h>
#include <io.h>
#include <process.h>
#include <memory.h>
#include <Windows.h>
#include <sstream>

class httpMethord
{
public:
    httpMethord();
    static size_t receive_data(void *contents, size_t size, size_t nmemb, void *stream);
    // HTTP 下载文件的回掉函数
//    static size_t writedata2file(void *ptr, size_t size, size_t nmemb, FILE *stream);
    // 文件下载接口
//    static int download_file(const char* url, const char outfilename[FILENAME_MAX]);
    // http get 请求
    static CURLcode HttpGet(const std::string & strUrl, std::string & strResponse,int nTimeout);
    // htpp post 请求
    static CURLcode HttpPost(const std::string & strUrl, std::string szJson,std::string & strResponse,int nTimeout);
    //HTTPS POST
    static int Posts(const std::string & strUrl, const std::string & strPost, std::string & strResponse, const char * pCaPath);
};

#endif // HTTPMETHORD_H
