//
//  MainMenuScene.h
//  Rcycle
//
//  Created by Mikel on 31/10/13.
//
//

#ifndef __Rcycle__MainMenuScene__
#define __Rcycle__MainMenuScene__

#include <iostream>
#include "cocos2d.h"
#include "cocos-ext.h"

#include "SceneLoadManager.h"
#include "CreditsScene.h"


class MainMenuScene : public MenuScene
    //public cocos2d::extension::CCBAnimationManagerDelegate
{
public:
    bool init();
    CREATE_FUNC(MainMenuScene);
    
    void enter(Object *pSender);
    void info(Object *pSender);

};




#endif /* defined(__Rcycle__MainMenuScene__) */
