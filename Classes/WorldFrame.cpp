//
//  WorldFrame.cpp
//  Rcycle
//
//  Created by Mikel on 29/01/14.
//
//

#include "WorldFrame.h"


USING_NS_CC;


bool WorldFrame::init()
{
    GameObject::init();

    
    Texture2D *tex1;
    tex1=new Texture2D();
    unsigned short texdata[]={0x0f0f,0x0f0f,0x0f0f , 0x0f0f,0xf0ff,0x0f0f , 0x0f0f,0x0f0f,0x0f0f   };
    tex1->initWithData(texdata, 18, Texture2D::PixelFormat::RGBA4444, 3, 3, Size(3,3));
    //    this->setDisplayFrame(SpriteFrame::createWithTexture(tex1, Rect(0,0,2*semiwidth,2*semiheight)));
    

    PhysicsBody *body=PhysicsBody::create();
    body->setDynamic(false);
    body->setCategoryBitmask(cat_wall);
    body->setContactTestBitmask(cat_trash);
    body->setCollisionBitmask(cat_trash);
    
    // down
    PhysicsShape *s1;
    s1=PhysicsShapeEdgeSegment::create(Point(-(semiwidth-semiindent),-semiheight), Point(semiwidth-semiindent,-semiheight));
    s1->setCategoryBitmask(cat_wall|cat_sensor);
    body->addShape(s1);
    
    // left
    s1=PhysicsShapeEdgeSegment::create(Point(-semiwidth,semiheight-verticalindent), Point(-(semiwidth-semiindent),-semiheight));
    s1->setCategoryBitmask(cat_wall);
    body->addShape(s1);
    // right
    s1=PhysicsShapeEdgeSegment::create(Point(semiwidth,semiheight-verticalindent), Point(semiwidth-semiindent,-semiheight));
    s1->setCategoryBitmask(cat_wall);
    body->addShape(s1);
    
    if (p_trash_category==Trash::CAT_CRISTAL) {
        s1=PhysicsShapeEdgeSegment::create(Point(semiwidth,semiheight-verticalindent),Point(semiwidth-verticalindent,semiheight));
        body->addShape(s1);
        s1->setCategoryBitmask(cat_wall);
        s1=PhysicsShapeEdgeSegment::create(Point(-(semiwidth-verticalindent),semiheight),Point(semiwidth-verticalindent,semiheight));
        s1->setCategoryBitmask(cat_wall);
        body->addShape(s1);
    }
    
    this->setPhysicsBody(body);
    
    over_sprite=NULL;
    if (p_trash_category==Trash::CAT_CRISTAL) {
        over_sprite=Sprite::createWithSpriteFrameName("Contenedores/Contenedor0005.png");
        if (debug_draw_alfa) over_sprite->setOpacity(100);
    }
    
    if (debug_draw_alfa) this->setOpacity(100);
    
    return true;
}








void WorldFrame::add_to_layer(cocos2d::Layer *alayer)
{
    alayer->addChild(this,0);
}
