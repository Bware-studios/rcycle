//
//  Net.h
//  rcycle
//
//  Created by Mikel on 14/10/14.
//
//

#ifndef __Rcycle__Net__
#define __Rcycle__Net__

#include "Common.h"
#include <thread>
#include <curl/curl.h>

#include "network/HttpClient.h"

class Net;

class WebRequest : public cocos2d::Ref
{
public:
    bool init();
    CREATE_FUNC(WebRequest);
    static WebRequest *createWithNet(Net *thenetmngr);
    void setNetMgr(Net *mgr);
    void getURL(const char *url);
    
private:
    void get_request();
    Net *netmgr;
    std::thread thethread;
    const char *theurl;
    int still_running;
};




class Net : public cocos2d::Ref
{
public:
    bool init();
    CREATE_FUNC(Net);
    
    static Net *thenet;
    
    static Net *getInstance();

    void getURL(char *url);

    void http_completed(Ref *psender,cocos2d::network::HttpResponse *response);
    
    void run();

    CURLM *curl_multi_handle;
    
    WebRequest *areq;
    
    
};

#endif /* defined(__Rcycle__Net__) */
