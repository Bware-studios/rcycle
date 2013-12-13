//
//  Container.cpp
//  Rcycle
//
//  Created by Mikel on 13/12/13.
//
//

#include "Container.h"

USING_NS_CC;

bool Container::init(int p_trash_category)
{
    GameObject::init();
    trash_category=p_trash_category;
    
    this->setDisplayFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("trashs/t1.png"));
    PhysicsBody *body=PhysicsBody::createCircle(32);
    this->setPhysicsBody(body);
    
    return true;
}


Container* Container::create(int p_trash_category)
{
    Container *pRet = new Container();
    if (pRet && pRet->init(p_trash_category))
    {
        pRet->autorelease();
        return pRet;
    }
    else
    {
        delete pRet;
        pRet = NULL;
        return NULL;
    }
}

