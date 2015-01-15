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
#include "HelpScene.h"

#include "Game.h"
#include "GameScene.h"


class MainMenuScene : public MenuScene
    //public cocosbuilder::CCBAnimationManagerDelegate
{
public:
    bool init();
    CREATE_FUNC(MainMenuScene);
    
    void time_passes();
    
    void enter(cocos2d::Ref *pSender);
    void options(cocos2d::Ref *pSender);
    void help(cocos2d::Ref *pSender);
    void info(cocos2d::Ref *pSender);
    void fame(cocos2d::Ref *pSender);
    void back(cocos2d::Ref *pSender);

    void try_callback(Dialogo *sender, int b);
    void try_text_callback(Dialogo *sender, int b,std::string texto);
    
};




#endif /* defined(__Rcycle__MainMenuScene__) */
