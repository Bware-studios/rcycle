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
//#include "cocos-ext.h"
#include "cocosbuilder/CocosBuilder.h"

#include "SceneLoadManager.h"
#include "CreditsScene.h"
#include "OptionsScene.h"
#include "FameScene.h"

#include "GameScene.h"


class MainMenuScene : public MenuScene
    //public cocosbuilder::CCBAnimationManagerDelegate
{
public:
    bool init();
    CREATE_FUNC(MainMenuScene);
    
    void enter(Object *pSender);
    void options(Object *pSender);
    void info(Object *pSender);
    void fame(Object *pSender);
    void back(Object *pSender);

};




#endif /* defined(__Rcycle__MainMenuScene__) */
