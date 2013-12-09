//
//  Trash.h
//  Rcycle
//
//  Created by Mikel on 10/12/13.
//
//

#ifndef __Rcycle__Trash__
#define __Rcycle__Trash__

#include <iostream>
#include <cocos2d.h>
#include "GameObject.h"


class Trash : public GameObject
{
public:
    bool init();
    CREATE_FUNC(Trash);
    
};


#endif /* defined(__Rcycle__Trash__) */
