//
//  HelpScene.h
//  rcycle
//
//  Created by Mikel on 01/10/14.
//
//

#ifndef __Rcycle__HelpScene__
#define __Rcycle__HelpScene__

#include "Common.h"

//#include "cocos-ext.h"
#include "cocosbuilder/CocosBuilder.h"

#include "SceneLoadManager.h"
#include "MainMenuScene.h"


class HelpScene : public MenuScene
//public cocosbuilder::CCBAnimationManagerDelegate
{
public:
    bool init();
    CREATE_FUNC(HelpScene);
    void setStartGameAfterHelp(bool start);
    
    bool touch_began(cocos2d::Touch *t,cocos2d::Event *e);
    void touch_moved(cocos2d::Touch *t,cocos2d::Event *e);
    void touch_ended(cocos2d::Touch *t,cocos2d::Event *e);
    void touch_cancelled(cocos2d::Touch *t,cocos2d::Event *e);

    
    void back(cocos2d::Ref *pSender);
    
    
    
private:
    bool startGameAfterHelp;
    
    int state;
};


#endif /* defined(__Rcycle__HelpScene__) */
