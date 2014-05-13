//
//  StatsScene.h
//  rcycle
//
//  Created by Mikel on 13/05/14.
//
//

#ifndef __rcycle__StatsScene__
#define __rcycle__StatsScene__

#include "Common.h"

//#include "cocos-ext.h"
#include "cocosbuilder/CocosBuilder.h"

#include "Options.h"


class StatsScene : public cocos2d::Scene,
public cocosbuilder::CCBSelectorResolver,
public cocosbuilder::CCBMemberVariableAssigner
{
public:
    ~StatsScene();
    
    bool init();
    static StatsScene *create();
    
    
    // SelectorResolver
    virtual cocos2d::SEL_MenuHandler onResolveCCBCCMenuItemSelector(cocos2d::Ref * pTarget, const char* pSelectorName);
    virtual cocos2d::SEL_CallFuncN onResolveCCBCCCallFuncSelector(cocos2d::Ref * pTarget, const char* pSelectorName);
    virtual cocos2d::extension::Control::Handler onResolveCCBCCControlSelector(cocos2d::Ref * pTarget, const char* pSelectorName);
    
    // VariableAsigner
    virtual bool onAssignCCBMemberVariable(cocos2d::Ref* target, const char* memberVariableName, Node* node);
    
    cocos2d::Layer *statsLayer;



};


#endif /* defined(__rcycle__StatsScene__) */
