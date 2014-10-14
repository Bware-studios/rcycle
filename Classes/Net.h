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



class Net : public cocos2d::Ref
{
public:
    bool init();
    CREATE_FUNC(Net);
    
    static Net *thenet;
    
    static Net *getInstance();

};

#endif /* defined(__Rcycle__Net__) */
