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
    LayerColor *back;
    back=LayerColor::create(Color4B(100,100,100,255), 200, 150);
    addChild(back);
    
    Label *l1 = Label::create(maintext, "Marker Felt", 20);
    l1->setPosition(Point(0,0));
    back->addChild(l1);

    parent->addChild(this);
}

void Dialogo::dismiss()
{
    removeFromParent();
}





void Dialogo::try_a_dialog()
{
    Scene *s=Director::getInstance()->getRunningScene();
    Dialogo *d1 = Dialogo::create();
    d1->setParent(s);
    d1->enter();
    
}



