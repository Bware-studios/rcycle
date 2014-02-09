//
//  Log.cpp
//  rcycle
//
//  Created by Mikel on 08/02/14.
//
//

#include "Log.h"


void Log_msg(const char *type,const char *msg, ... )
{
    va_list vargs;
    char *buf;
    va_start(vargs, msg);
    std::cout << type << ": ";
    if (vasprintf(&buf, msg, vargs)>0) {
        std::cout << buf;
    }
    std::cout<<"\n";
    va_end(vargs);
}

