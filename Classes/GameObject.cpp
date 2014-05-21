//
//  GameObject.cpp
//  Rcycle
//
//  Created by Mikel on 09/12/13.
//
//

#include "GameObject.h"

#include "SceneLoadManager.h"


USING_NS_CC;


bool GameObject::init()
{
    Sprite::init();
    
    this->is_dragable=false;
    
    return true;
}











/// AnimatedGameObject

bool AnimatedGameObject::init()
{
    GameObject::init();
    
    return true;
}


AnimatedGameObject* AnimatedGameObject::create(char *filename)
{
    AnimatedGameObject *pRet;
    if ( !Options::debug_draw_spritesquare ) {
        pRet=SceneLoadManager::getInstance()->gameObjectFromFile(filename);
    } else {
        pRet=AnimatedGameObject::create();
    }
    return pRet;
}


void AnimatedGameObject::setAnimationManager(cocosbuilder::CCBAnimationManager *p_animation_manager)
{
    animation_manager=p_animation_manager;
    animation_manager->retain();
}


