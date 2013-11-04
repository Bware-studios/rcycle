//
//  LoadingScene.h
//  Rcycle
//
//  Created by Mikel on 04/11/13.
//
//

#ifndef __Rcycle__LoadingScene__
#define __Rcycle__LoadingScene__

#include <iostream>
#include "cocos2d.h"
#include "cocos-ext.h"

#include "SceneLoadManager.h"


class LoadingScene : public MenuScene
//public cocos2d::extension::CCBAnimationManagerDelegate
{
public:
    bool init();
    CREATE_FUNC(LoadingScene);
    
};




#endif /* defined(__Rcycle__LoadingScene__) */
