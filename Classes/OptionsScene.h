//
//  OptionsScene.h
//  Rcycle
//
//  Created by Mikel on 10/11/13.
//
//

#ifndef __Rcycle__OptionsScene__
#define __Rcycle__OptionsScene__

#include <iostream>
#include "cocos2d.h"
#include "cocos-ext.h"
#include "cocosbuilder/CocosBuilder.h"

#include "SceneLoadManager.h"
#include "MainMenuScene.h"


class OptionsScene : public MenuScene
//public cocosbuilder::CCBAnimationManagerDelegate
{
public:
    bool init();
    CREATE_FUNC(OptionsScene);
    
    void enter(Object *pSender);
    void back(Object *pSender);
    
};

#endif /* defined(__Rcycle__OptionsScene__) */
