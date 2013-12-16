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
    
    
    Texture2D *tex1;
    tex1=new Texture2D();
    unsigned short texdata[]={0x0f0f,0x0f0f,0x0f0f , 0x0f0f,0xf0ff,0x0f0f , 0x0f0f,0x0f0f,0x0f0f   };
    tex1->initWithData(texdata, 18, Texture2D::PixelFormat::RGBA4444, 3, 3, Size(30,30));
    this->setDisplayFrame(SpriteFrame::createWithTexture(tex1, Rect(0,0,100,60)));
    
    PhysicsBody *body=PhysicsBody::createBox(Size(100,60));
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

