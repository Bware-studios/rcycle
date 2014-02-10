//
//  GameObject.h
//  Rcycle
//
//  Created by Mikel on 09/12/13.
//
//

#ifndef __Rcycle__GameObject__
#define __Rcycle__GameObject__

#include "Common.h"


class GameObject : public cocos2d::Sprite
{
public:
    static const int cat_trash = 1;
    static const int cat_wall = 2;
    static const int cat_sensor = 4;
    
    bool init();
    
    bool is_dragable;
    
};



#endif /* defined(__Rcycle__GameObject__) */
