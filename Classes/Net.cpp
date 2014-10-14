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

#include <curl/curl.h>

USING_NS_CC;
using namespace std;


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
    
    
    printf("net init...\n");
    CURL *curl;
    CURLcode res;
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    curl_easy_setopt(curl, CURLOPT_URL, "https://bwnet-bwmki.rhcloud.com/api/rcycle/get_version.php");
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
    res = curl_easy_perform(curl);
    if(res != CURLE_OK) {
        printf("curl_easy_perform() failed: %s\n",
               curl_easy_strerror(res));
    }
    printf("curl ok");
    curl_easy_cleanup(curl);

    netthread=thread(&Net::run,this);
    
    return true;
}


void Net::run()
{
    while (1) {
        printf("running in thread...\n");
        sleep(1);
    }
}

