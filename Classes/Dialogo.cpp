//
//  Dialogo.cpp
//  Rcycle
//
//  Created by Mikel on 2/1/15.
//
//

#include "Dialogo.h"

USING_NS_CC;

bool Dialogo::init()
{
    Layer::init();
    
    printf("dialogo.. init...\n");
    return true;
}


void Dialogo::setParent(cocos2d::Node *p)
{
    assert(p!=NULL);
    parent=p;
}


void Dialogo::enter()
{
    Size s=Director::getInstance()->getOpenGLView()->getDesignResolutionSize();
    //ignoreAnchorPointForPosition(false);
    //setAnchorPoint(Point(0,0));
    //setPosition(Point(0,0));
    
//    LayerColor *hide;
//    hide=LayerColor::create(Color4B(250,150,150,10), s.width,s.height );
//    hide->setAnchorPoint(Point(0.5,0.5));
//    hide->ignoreAnchorPointForPosition(false);
//    hide->setPosition(Point(0,0));
//    addChild(hide,10);
    
    LayerColor *back;
    back=LayerColor::create(Color4B(100,100,200,200), s.width*.9,s.height*.9 );
    back->setAnchorPoint(Point(0.5,0.5));
    back->ignoreAnchorPointForPosition(false);
    back->setPosition(Point(0,0));
    addChild(back,20);
    
    Label *l1 = Label::create(maintext, "Marker Felt", 20);
    l1->setPosition(Point(0,0));
    addChild(l1,30);

    auto ap=this->getAnchorPoint();
    auto pap=parent->getAnchorPoint();
    std::cout<<"anchor: "<<ap.x <<","<<ap.y<<"\n";
    std::cout<<"p anchor: "<<pap.x <<","<<pap.y<<"\n";


    setPosition(Point(s.width/2,s.height/2));
    parent->addChild(this);



    EventListenerTouchOneByOne *tl = EventListenerTouchOneByOne::create();
    tl->setSwallowTouches(true);
    tl->onTouchBegan=CC_CALLBACK_2(Dialogo::event_touchbegan, this);
    tl->onTouchEnded=CC_CALLBACK_2(Dialogo::event_touchended, this);
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(tl,this);


}

void Dialogo::dismiss()
{
    removeFromParent();
}



bool Dialogo::event_touchbegan(cocos2d::Touch* touch,cocos2d::Event *e)
{
    return true;
}

void Dialogo::event_touchended(cocos2d::Touch* touch,cocos2d::Event *e)
{
}





void Dialogo::try_a_dialog()
{
    Scene *s=Director::getInstance()->getRunningScene();
    Dialogo *d1 = Dialogo::create();
    d1->setParent(s);
    d1->enter();
    
}



