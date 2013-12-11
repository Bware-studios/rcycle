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
    bool init(int trash_type, int trash_category);
    CREATE_FUNC(Trash);
    static Trash* create(int p_trash_type, int p_trash_category);
    
    int trash_type;
    int trash_category;
    
};


#endif /* defined(__Rcycle__Trash__) */
