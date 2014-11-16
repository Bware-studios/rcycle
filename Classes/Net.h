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

#include "network/HttpClient.h"

class Net;


class Net : public cocos2d::Ref
{
public:
    bool init();
    CREATE_FUNC(Net);
    
    static Net *thenet;
    
    static Net *getInstance();

//    void getURL(char *url);

//    void http_completed(Ref *psender,cocos2d::network::HttpResponse *response);
    

    bool waiting_for_register();
    bool waiting_for_request();

    void bwnet_register();
    void bwnet_register_completed(Ref *psender,cocos2d::network::HttpResponse *response);
    
    void bwnet_send_scores(cocos2d::ValueMap scores);
    void bwnet_send_scores_completed(Ref *psender,cocos2d::network::HttpResponse *response);

    void bwnet_request_scores();
    void bwnet_request_scores_completed(Ref *psender,cocos2d::network::HttpResponse *response);

    
    std::string bwnet_id;
    bool bwnet_registered;
    
    bool bwnet_request_waiting;

    
};

#endif /* defined(__Rcycle__Net__) */
