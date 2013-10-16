//
//  MenuScene.cpp
//  Rcycle
//
//  Created by Mikel on 16/10/13.
//
//

#include "MenuScene.h"

USING_NS_CC;
USING_NS_CC_EXT;


bool MenuScene::init(const char *ccb_filename)
{
    
    // ccb loading code
    
    
    return true;
}


bool MainMenuScene::init()
{
    MenuScene::init("MainMenuScene");
    return true;
}


bool MenuLayer::init()
{
    
    return true;
}


SEL_MenuHandler MenuLayer::onResolveCCBCCMenuItemSelector(Object * pTarget, const char* pSelectorName)
{
//    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "onPressButton", MenuLayer::click);
    return NULL;
}


SEL_CallFuncN MenuLayer::onResolveCCBCCCallFuncSelector(Object * pTarget, const char* pSelectorName)
{
    
    return NULL;
}


Control::Handler MenuLayer::onResolveCCBCCControlSelector(Object * pTarget, const char* pSelectorName)
{
    
    return NULL;
}





