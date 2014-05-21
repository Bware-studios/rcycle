//
//  Camion.cpp
//  rcycle
//
//  Created by Mikel on 21/05/14.
//
//

#include "Camion.h"

#include "SceneLoadManager.h"

USING_NS_CC;

 

bool Camion::init()
{
    AnimatedGameObject::init();
    
    return true;
}


Camion* Camion::createFromFile()
{
    AnimatedGameObject  *aux=SceneLoadManager::getInstance()->gameObjectFromFile("camion");
    Camion *pRet;
    pRet=dynamic_cast<Camion*>(aux);
    pRet->init();
    return pRet;
}


void Camion::add_to_layer(cocos2d::Layer *alayer)
{
    alayer->addChild(this,-1);
}


void Camion::start_enter_animation(Point start_postion,Point end_position)
{
    this->setPosition(start_postion);
    animation_manager->runAnimationsForSequenceNamed("llega");
    this->runAction(MoveTo::create(1, end_position));
}


void Camion::start_exit_animation(Point end_position)
{
    animation_manager->runAnimationsForSequenceNamed("se_va");
    this->runAction(MoveTo::create(1, end_position));
}
