//
//  WorldFrame.h
//  Rcycle
//
//  Created by Mikel on 29/01/14.
//
//

#ifndef __Rcycle__WorldFrame__
#define __Rcycle__WorldFrame__

#include "Common.h"

#include "Game.h"
#include "GameObject.h"
#include "Trash.h"


class WorldFrame : public GameObject
{
public:
    bool init();
    CREATE_FUNC(WorldFrame);

    void add_to_layer(cocos2d::Layer *alayer);
    void destroy(Trash *atrash);
    
};



#endif /* defined(__Rcycle__WorldFrame__) */
