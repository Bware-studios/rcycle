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

    
    void bwnet_register();
    void bwnet_register_completed(Ref *psender,cocos2d::network::HttpResponse *response);
    
    
    std::string bwnet_id;
    bool bwnet_registered;
    
    
};

#endif /* defined(__Rcycle__Net__) */
