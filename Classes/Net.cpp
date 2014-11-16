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

#include "Preferences.h"
#include "JSONcodec.h"
#include "Scores.h"



USING_NS_CC;
using namespace std;

using namespace network;


const char *bwnet_baseurl="http://bwnet-bwmki.rhcloud.com/rcycle/api";
//const char *bwnet_baseurl="http://localhost/~mikel/bwnet/rcycle/api";




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
    LOG_NET("net init...");

    Net::thenet=this;
    Net::thenet->retain();
    
    bwnet_request_waiting=false;

    bwnet_registered=false;
    bwnet_id=Preferences::getInstance()->getBwnetId();
    if (bwnet_id.empty()) {
        LOG_NET("calling register");
        bwnet_register();
    } else {
        LOG_NET("found register id %s",bwnet_id.c_str());
        bwnet_registered=true;
        bwnet_request_scores();
    }
    
    
    return true;
}

//void Net::getURL(char *url)
//{
//    HttpRequest *request = new HttpRequest();
//    request->setUrl("https://bwnet-bwmki.rhcloud.com/api/rcycle/get_version.php");
//    request->setRequestType(HttpRequest::Type::GET);
//    request->setResponseCallback(this,httpresponse_selector(Net::http_completed));
//    //request->setResponseCallback(this,CC_CALLBACK_1(Net::http_completed, this, this));
//    
////                                 CC_CALLBACK_0 (Net::http_completed, this) );
//    
//    
//    HttpClient *http_client=HttpClient::getInstance();
//    http_client->send(request);
//    
//}


//void Net::http_completed(Ref *psender,cocos2d::network::HttpResponse *response)
//{
//    vector<char> *datav= response->getResponseData();
//    string data(datav->begin(),datav->end());
//    
//    printf("== http completado....  ==-----------------------\n");
//    printf("e: %ld \n %s ----\n",response->getResponseCode(),response->getErrorBuffer());
//    printf("d: %s ----\n",data.c_str());
//}

bool Net::waiting_for_register()
{
    return !bwnet_registered;
}

bool Net::waiting_for_request()
{
    return false;
    //return bwnet_request_waiting;
}


void Net::bwnet_register()
{
    HttpRequest *request = new HttpRequest();
    stringstream req_url;
    req_url << bwnet_baseurl << "/" << "register.php";
    request->setUrl(req_url.str().c_str());
    request->setRequestType(HttpRequest::Type::GET);
    request->setResponseCallback(this,httpresponse_selector(Net::bwnet_register_completed));
    HttpClient *http_client=HttpClient::getInstance();
    http_client->send(request);
}

void Net::bwnet_register_completed(Ref *psender,cocos2d::network::HttpResponse *response)
{
    if (!response->isSucceed() ) {
        LOG_NET("register failed");
        return;
    }
    
    vector <char>* r= response->getResponseData();
    string a(r->begin(),r->end());
    Value responsedata = read_json_string(a);
    
    if (responsedata.getType()!=Value::Type::MAP) {
        LOG_NET("not map");
        // timeout to try again...
        return;
    }
    
    bwnet_registered=true;
    
    ValueMap responsemap = responsedata.asValueMap();
    string registered_id = responsemap.at("id").asString();
    
    
    LOG_NET("data : %s",a.c_str());
    LOG_NET("status : %s",responsemap.at("status").asString().c_str());
    LOG_NET("id : %s",registered_id.c_str());

    Preferences::getInstance()->setBwnetId(registered_id);
    bwnet_request_scores();
}



void Net::bwnet_send_scores(cocos2d::ValueMap scores)
{
    HttpRequest *request = new HttpRequest();
    stringstream req_url;
    
    req_url << bwnet_baseurl << "/" << "post_scores.php";
    request->setUrl(req_url.str().c_str());
    request->setRequestType(HttpRequest::Type::POST);

    stringstream post_data;
    post_data << "id=" << bwnet_id << "&" << "scores=" << JSONcodec::valueToJSON(Value(scores));
    string post_data_str=post_data.str();
    request->setRequestData(post_data_str.c_str(),post_data_str.length());
    
    
    request->setResponseCallback(this,httpresponse_selector(Net::bwnet_send_scores_completed));
    HttpClient *http_client=HttpClient::getInstance();
    http_client->send(request);
    
    bwnet_request_waiting=true;
    
}

void Net::bwnet_send_scores_completed(Ref *psender,cocos2d::network::HttpResponse *response)
{
    bwnet_request_waiting=false;
    if (!response->isSucceed() ) {
        LOG_NET("send scores failed");
        return;
    }
    vector <char>* r= response->getResponseData();
    string a(r->begin(),r->end());
    Value responsedata = read_json_string(a);
    
    if (responsedata.getType()!=Value::Type::MAP) {
        LOG_NET("send scores received not map");
        return;
    }

    
    ValueMap responsemap = responsedata.asValueMap();

    
    LOG_NET("data : %s",a.c_str());
    LOG_NET("status : %s",responsemap.at("status").asString().c_str());

    
    Value scores = responsemap.at("scores");
    if (responsemap.at("status").asInt()<0) {
        // ha devuelto error...
        return;
    }
    Scores::getInstance()->received_scores(scores);

}

void Net::bwnet_request_scores()
{
    HttpRequest *request = new HttpRequest();
    stringstream req_url;
    
    string bwnetid = Preferences::getInstance()->getBwnetId();

    req_url << bwnet_baseurl << "/" << "get_scores.php" << "?id=" << bwnetid;
    request->setUrl(req_url.str().c_str());
    request->setRequestType(HttpRequest::Type::GET);
    
    request->setResponseCallback(this,httpresponse_selector(Net::bwnet_request_scores_completed));
    HttpClient *http_client=HttpClient::getInstance();
    http_client->send(request);
    
    bwnet_request_waiting=true;
    
}

void Net::bwnet_request_scores_completed(Ref *psender,cocos2d::network::HttpResponse *response)
{
    bwnet_request_waiting=false;
    if (!response->isSucceed() ) {
        LOG_NET("request scores failed");
        return;
    }
    vector <char>* r= response->getResponseData();
    string a(r->begin(),r->end());
    Value responsedata = read_json_string(a);
    
    if (responsedata.getType()!=Value::Type::MAP) {
        LOG_NET("send scores received not map");
        return;
    }
    
    
    ValueMap responsemap = responsedata.asValueMap();
    
    
    LOG_NET("data : %s",a.c_str());
    LOG_NET("status : %s",responsemap.at("status").asString().c_str());
    
    
    Value scores = responsemap.at("scores");
    if (responsemap.at("status").asInt()<0) {
        // ha devuelto error...
        return;
    }
    Scores::getInstance()->received_scores(scores);
    
}









