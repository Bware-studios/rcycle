//
//  Container.cpp
//  Rcycle
//
//  Created by Mikel on 13/12/13.
//
//

#include "Container.h"

USING_NS_CC;

const int semiheight = 40;
const int semiwidth = 70;
const int semiindent = 10;


bool Container::init(int p_trash_category)
{
    GameObject::init();
    trash_category=p_trash_category;
    
    
    Texture2D *tex1;
    tex1=new Texture2D();
    unsigned short texdata[]={0x0f0f,0x0f0f,0x0f0f , 0x0f0f,0xf0ff,0x0f0f , 0x0f0f,0x0f0f,0x0f0f   };
    tex1->initWithData(texdata, 18, Texture2D::PixelFormat::RGBA4444, 3, 3, Size(3,3));
    this->setDisplayFrame(SpriteFrame::createWithTexture(tex1, Rect(0,0,2*semiwidth,2*semiheight)));
    
    PhysicsBody *body=PhysicsBody::createEdgeSegment(Point(-(semiwidth-semiindent),-semiheight), Point(semiwidth-semiindent,-semiheight));
    body->addShape(PhysicsShapeEdgeSegment::create(Point(-semiwidth,semiheight), Point(-(semiwidth-semiindent),-semiheight)));
    body->addShape(PhysicsShapeEdgeSegment::create(Point(semiwidth,semiheight), Point(semiwidth-semiindent,-semiheight)));
    
    body->setDynamic(false);
    
    this->setPhysicsBody(body);
    this->setOpacity(100);
    
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

