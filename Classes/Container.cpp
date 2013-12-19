//
//  Container.cpp
//  Rcycle
//
//  Created by Mikel on 13/12/13.
//
//

#include "Container.h"

USING_NS_CC;

// normal container
const int normal_semiheight = 40;
const int normal_semiwidth = 70;
const int normal_semiindent = 10;
const int normal_verticalindent =0;

//  container
const int x_semiheight = 60;
const int x_semiwidth = 50;
const int x_semiindent = 0;
const int x_verticalindent = 40;


bool Container::init(int p_trash_category)
{
    GameObject::init();
    trash_category=p_trash_category;
    
    if (p_trash_category==3) {
        semiheight=x_semiheight;
        semiwidth=x_semiwidth;
        semiindent=x_semiindent;
        verticalindent=x_verticalindent;
    } else {
        semiheight=normal_semiheight;
        semiwidth=normal_semiwidth;
        semiindent=normal_semiindent;
        verticalindent=normal_verticalindent;
    }
    
    Texture2D *tex1;
    tex1=new Texture2D();
    unsigned short texdata[]={0x0f0f,0x0f0f,0x0f0f , 0x0f0f,0xf0ff,0x0f0f , 0x0f0f,0x0f0f,0x0f0f   };
    tex1->initWithData(texdata, 18, Texture2D::PixelFormat::RGBA4444, 3, 3, Size(3,3));
    this->setDisplayFrame(SpriteFrame::createWithTexture(tex1, Rect(0,0,2*semiwidth,2*semiheight)));
    
    // down
    PhysicsBody *body=PhysicsBody::createEdgeSegment(Point(-(semiwidth-semiindent),-semiheight), Point(semiwidth-semiindent,-semiheight));
    // left
    body->addShape(PhysicsShapeEdgeSegment::create(Point(-semiwidth,semiheight-verticalindent), Point(-(semiwidth-semiindent),-semiheight)));
    // right
    body->addShape(PhysicsShapeEdgeSegment::create(Point(semiwidth,semiheight-verticalindent), Point(semiwidth-semiindent,-semiheight)));

    if (p_trash_category==3) {
        body->addShape(PhysicsShapeEdgeSegment::create(Point(semiwidth,semiheight-verticalindent),Point(semiwidth-verticalindent,semiheight)));
        body->addShape(PhysicsShapeEdgeSegment::create(Point(-(semiwidth-verticalindent),semiheight),Point(semiwidth-verticalindent,semiheight)));
    }
    
    
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

