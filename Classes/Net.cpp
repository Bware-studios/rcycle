//
//  Net.cpp
//  rcycle
//
//  Created by Mikel on 14/10/14.
//
//


#include "Net.h"
#include <stdlib.h>
#include <unistd.h>

#include "JSONcodec.h"


USING_NS_CC;
using namespace std;

using namespace network;


//const char *bwnet_baseurl="http://bwnet-rhcloud.com/rcycle/api";
const char *bwnet_baseurl="http://localhost/~mikel/bwnet/rcycle/api";


bool WebRequest::init()
{
    netmgr=NULL;
    return true;
}

WebRequest *WebRequest::createWithNet(Net *thenetmngr)
{
    WebRequest *req=WebRequest::create();
    if (req) {
        req->setNetMgr(thenetmngr);
    }
    return req;
}

void WebRequest::setNetMgr(Net *mgr)
{
    netmgr=mgr;
}

void WebRequest::getURL(const char *url)
{
    theurl=url;
    thethread=thread(&WebRequest::get_request,this);
}


void WebRequest::get_request()
{
    CURL *curl;
    CURLM *curlm = netmgr->curl_multi_handle;
    CURLcode res;
    curl = curl_easy_init();
    curl_easy_setopt(curl, CURLOPT_URL, "https://bwnet-bwmki.rhcloud.com/api/rcycle/get_version.php");
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
    curl_multi_add_handle(curlm, curl);
    curl_easy_perform(curl);
  //  res = curl_multi_perform(curl,&still_running);
    if(res != CURLE_OK) {
        printf("curl_easy_perform() failed: %s\n",
               curl_easy_strerror(res));
    }
    printf("curl ok");
    curl_easy_cleanup(curl);
}






Net *Net::thenet=NULL;

Net *Net::getInstance()
{
    if (thenet==NULL) {
        Net::create();
    }
    return thenet;
}

bool Net::init()
{
    Net::thenet=this;
    Net::thenet->retain();
    
    
    curl_global_init(CURL_GLOBAL_ALL);
    curl_multi_handle=curl_multi_init();
    
    
    printf("net init...\n");

    //netthread=thread(&Net::run,this);
    
    return true;
}

void Net::getURL(char *url)
{
    HttpRequest *request = new HttpRequest();
    request->setUrl("https://bwnet-bwmki.rhcloud.com/api/rcycle/get_version.php");
    request->setRequestType(HttpRequest::Type::GET);
    request->setResponseCallback(this,httpresponse_selector(Net::http_completed));
    //request->setResponseCallback(this,CC_CALLBACK_1(Net::http_completed, this, this));
    
//                                 CC_CALLBACK_0 (Net::http_completed, this) );
    
    
    HttpClient *http_client=HttpClient::getInstance();
    http_client->send(request);
    
    
    WebRequest *req;
    req=WebRequest::createWithNet(this);
    req->getURL(url);
    areq=req;
    req->retain();
}

void Net::run()
{
    while (1) {
        printf("running in thread...\n");
        sleep(1);
    }
}

void Net::http_completed(Ref *psender,cocos2d::network::HttpResponse *response)
{
    vector<char> *datav= response->getResponseData();
    string data(datav->begin(),datav->end());
    
    printf("== http completado....  ==-----------------------\n");
    printf("e: %d \n %s ----\n",response->getResponseCode(),response->getErrorBuffer());
    printf("d: %s ----\n",data.c_str());
}


void Net::bwnet_register()
{
    HttpRequest *request = new HttpRequest();
    stringstream req_url=string(bwnet_baseurl)+string();
    request->setUrl();
    request->setRequestType(HttpRequest::Type::GET);
    request->setResponseCallback(this,httpresponse_selector(Net::http_completed));
    
}

void Net::bwnet_register_completed()
{
    
    
}









