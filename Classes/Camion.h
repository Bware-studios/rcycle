//
//  Camion.h
//  rcycle
//
//  Created by Mikel on 21/05/14.
//
//

#ifndef __rcycle__Camion__
#define __rcycle__Camion__

#include "Common.h"

#include "cocosbuilder/CocosBuilder.h"

#include "GameObject.h"

class Camion : public AnimatedGameObject
{
public:
    bool init();
    CREATE_FUNC(Camion);
    static Camion* createFromFile();
    void add_to_layer(cocos2d::Layer *alayer);
    
    void start_enter_animation(cocos2d::Point start_postion,cocos2d::Point end_position);
    void start_exit_animation(cocos2d::Point end_position);
    
};


#endif /* defined(__rcycle__Camion__) */
