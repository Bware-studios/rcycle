//
//  OptionsScene.h
//  Rcycle
//
//  Created by Mikel on 10/11/13.
//
//

#ifndef __Rcycle__OptionsScene__
#define __Rcycle__OptionsScene__

#include "Common.h"

#include "cocosbuilder/CocosBuilder.h"

#include "SceneLoadManager.h"
#include "MainMenuScene.h"


class OptionsScene : public MenuScene
//public cocosbuilder::CCBAnimationManagerDelegate
{
public:
    bool init();
    CREATE_FUNC(OptionsScene);
    
    void enter(cocos2d::Ref *pSender);
    void back(cocos2d::Ref *pSender);
    
    void selected_prueba(cocos2d::Ref *pSender);
    void selected_tog(cocos2d::Ref *pSender);
    void selected_tog1(cocos2d::Ref *pSender);
    void selected_tog2(cocos2d::Ref *pSender);

    void selected_trash_collision(cocos2d::Ref *pSender);
    void selected_no_trash_collision(cocos2d::Ref *pSender);

    
};

#endif /* defined(__Rcycle__OptionsScene__) */
