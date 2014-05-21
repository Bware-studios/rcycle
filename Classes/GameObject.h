//
//  GameObject.h
//  Rcycle
//
//  Created by Mikel on 09/12/13.
//
//

#ifndef __Rcycle__GameObject__
#define __Rcycle__GameObject__

#include "Common.h"
#include "cocosbuilder/CocosBuilder.h"


class GameObject : public cocos2d::Sprite
{
public:
    static const int cat_trash = 1;
    static const int cat_wall = 2;
    static const int cat_sensor = 4;
    
    bool init();
    
    bool is_dragable;
    
};



// Base for GameObject with animations loaded from CCB
//
class AnimatedGameObject : public GameObject
{
public:
    bool init();
    CREATE_FUNC(AnimatedGameObject);
    AnimatedGameObject *create(char *filename);
    
    void setAnimationManager(cocosbuilder::CCBAnimationManager *p_animation_manager);


protected:
    cocosbuilder::CCBAnimationManager *animation_manager;

};





#endif /* defined(__Rcycle__GameObject__) */
