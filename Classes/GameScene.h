//
//  GameScene.h
//  Rcycle
//
//  Created by Mikel on 11/11/13.
//
//

#ifndef __Rcycle__GameScene__
#define __Rcycle__GameScene__

#include <iostream>
#include "cocos2d.h"
#include "cocos-ext.h"

#include "SceneLoadManager.h"
#include "FameScene.h"


class GameScene : public cocos2d::Scene,
public cocos2d::extension::CCBSelectorResolver
//public cocos2d::extension::CCBAnimationManagerDelegate
{
public:
    bool init();
    CREATE_FUNC(GameScene);
    
    // SelectorResolver
    virtual cocos2d::SEL_MenuHandler onResolveCCBCCMenuItemSelector(Object * pTarget, const char* pSelectorName);
    virtual cocos2d::SEL_CallFuncN onResolveCCBCCCallFuncSelector(Object * pTarget, const char* pSelectorName);
    virtual cocos2d::extension::Control::Handler onResolveCCBCCControlSelector(Object * pTarget, const char* pSelectorName);
    
    void time_passes();

    
    cocos2d::Layer *backLayer;
    cocos2d::Layer *frontLayer;
};


#endif /* defined(__Rcycle__GameScene__) */
