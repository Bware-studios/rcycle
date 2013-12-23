//
//  Trash.cpp
//  Rcycle
//
//  Created by Mikel on 10/12/13.
//
//

#include "Trash.h"

USING_NS_CC;


bool Trash::init()
{
    return init(0,0);
}


bool Trash::init(int p_trash_type, int p_trash_category)
{
    GameObject::init();
    trash_type=p_trash_type;
    trash_category=p_trash_category;

    this->setDisplayFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("trashs/t1.png"));
    PhysicsBody *body=PhysicsBody::createCircle(24);

    body->setCategoryBitmask(cat_trash);
    body->setContactTestBitmask(cat_wall|cat_trash|cat_sensor);
    body->setCollisionBitmask(cat_wall|cat_trash);

    this->setPhysicsBody(body);
    
    return true;
}


Trash* Trash::create(int p_trash_type, int p_trash_category)
{
    Trash *pRet = new Trash();
    if (pRet && pRet->init(p_trash_type,p_trash_category))
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

