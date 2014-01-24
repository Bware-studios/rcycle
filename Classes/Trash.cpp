//
//  Trash.cpp
//  Rcycle
//
//  Created by Mikel on 10/12/13.
//
//

#include "Trash.h"

USING_NS_CC;


const int num_trash_cat=4;
const char *Trash::trash_cat_names[]={"cristal","plastico","organico","papel"};
const int Trash::CAT_CRISTAL=0;
const int Trash::CAT_PLASTICO=1;
const int Trash::CAT_ORGANICO=2;
const int Trash::CAT_PAPEL=3;

bool Trash::init()
{
    return init(0,0);
}


bool Trash::init(int p_trash_type, int p_trash_category)
{
    GameObject::init();
    trash_type=p_trash_type;
    trash_category=p_trash_category;

    char img_name[50];
    sprintf(img_name,"trashs/basura_%s%d.png",trash_cat_names[trash_category],p_trash_type+1);
    
    this->setDisplayFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(img_name));
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



void Trash::add_to_layer(cocos2d::Layer *alayer)
{
    alayer->addChild(this,15);
}



