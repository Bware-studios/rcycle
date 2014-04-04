//
//  GameObject.cpp
//  Rcycle
//
//  Created by Mikel on 09/12/13.
//
//

#include "GameObject.h"

USING_NS_CC;


bool GameObject::init()
{
    Sprite::init();
    
    this->is_dragable=false;
    
    return true;
}
