//
//  MainMenuScene.h
//  Rcycle
//
//  Created by Mikel on 31/10/13.
//
//

#ifndef __Rcycle__MainMenuScene__
#define __Rcycle__MainMenuScene__

#include "Common.h"

//#include "cocos-ext.h"
#include "cocosbuilder/CocosBuilder.h"

#include "SceneLoadManager.h"
#include "CreditsScene.h"
#include "OptionsScene.h"
#include "FameScene.h"

#include "Game.h"
#include "GameScene.h"


class MainMenuScene : public MenuScene
    //public cocosbuilder::CCBAnimationManagerDelegate
{
public:
    bool init();
    CREATE_FUNC(MainMenuScene);
    
    void enter(cocos2d::Object *pSender);
    void options(cocos2d::Object *pSender);
    void info(cocos2d::Object *pSender);
    void fame(cocos2d::Object *pSender);
    void back(cocos2d::Object *pSender);

};




#endif /* defined(__Rcycle__MainMenuScene__) */
