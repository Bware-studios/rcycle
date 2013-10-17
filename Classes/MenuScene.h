//
//  MenuScene.h
//  Rcycle
//
//  Created by Mikel on 16/10/13.
//
//

//
// Base class for menu scenes
// derived classes for each menu scene
// common behavior to load from ccb
//

#ifndef __Rcycle__MenuScene__
#define __Rcycle__MenuScene__

#include <iostream>
#include "cocos2d.h"
#include "cocos-ext.h"

class MenuScene : public cocos2d::Scene
{
public:
    bool init(const char *ccb_filename);
};


class MainMenuScene : public MenuScene, public cocos2d::extension::CCBSelectorResolver
{
public:
    bool init();
    CREATE_FUNC(MainMenuScene);

    cocos2d::SEL_MenuHandler onResolveCCBCCMenuItemSelector(Object * pTarget, const char* pSelectorName);
    cocos2d::SEL_CallFuncN onResolveCCBCCCallFuncSelector(Object * pTarget, const char* pSelectorName);
    cocos2d::extension::Control::Handler onResolveCCBCCControlSelector(Object * pTarget, const char* pSelectorName);

    void click(Object *pSender);
};


class FinishScene : public MenuScene, public cocos2d::extension::CCBSelectorResolver
{
public:
    bool init();
    CREATE_FUNC(FinishScene);
    
    cocos2d::SEL_MenuHandler onResolveCCBCCMenuItemSelector(Object * pTarget, const char* pSelectorName);
    cocos2d::SEL_CallFuncN onResolveCCBCCCallFuncSelector(Object * pTarget, const char* pSelectorName);
    cocos2d::extension::Control::Handler onResolveCCBCCControlSelector(Object * pTarget, const char* pSelectorName);
    
    void click(Object *pSender);
};



class MenuLayer : public cocos2d::Layer, public cocos2d::extension::CCBSelectorResolver
{
public:
    bool init();
    cocos2d::SEL_MenuHandler onResolveCCBCCMenuItemSelector(Object * pTarget, const char* pSelectorName);
    cocos2d::SEL_CallFuncN onResolveCCBCCCallFuncSelector(Object * pTarget, const char* pSelectorName);
    cocos2d::extension::Control::Handler onResolveCCBCCControlSelector(Object * pTarget, const char* pSelectorName);
    CREATE_FUNC(MenuLayer);
};


class MenuLayerLoader : public cocos2d::extension::LayerLoader {
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(MenuLayerLoader, loader);
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(MenuLayer);
};









#endif /* defined(__Rcycle__MenuScene__) */
