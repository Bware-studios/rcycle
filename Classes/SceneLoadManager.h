//
//  SceneLoadManager.h
//  Rcycle
//
//  Created by Mikel on 29/10/13.
//
//

#ifndef __Rcycle__SceneLoadManager__
#define __Rcycle__SceneLoadManager__

#include <iostream>
#include "cocos2d.h"
#include "cocos-ext.h"

class SceneLoadManager
{
public:
    SceneLoadManager();
    ~SceneLoadManager();
    static SceneLoadManager *getInstance();
    
    cocos2d::Layer *layerFromFile(const char *pFileName,cocos2d::extension::CCBSelectorResolver *pOwner=NULL);
    
private:
    static SceneLoadManager *theInstance;
    cocos2d::extension::CCBReader *ccbReader;
};






class MenuLayer : public cocos2d::Layer
//, public cocos2d::extension::CCBSelectorResolver, public cocos2d::extension::CCBMemberVariableAssigner
{
public:
    bool init();
   // cocos2d::SEL_MenuHandler onResolveCCBCCMenuItemSelector(Object * pTarget, const char* pSelectorName);
   // cocos2d::SEL_CallFuncN onResolveCCBCCCallFuncSelector(Object * pTarget, const char* pSelectorName);
   // cocos2d::extension::Control::Handler onResolveCCBCCControlSelector(Object * pTarget, const char* pSelectorName);
    
   // bool onAssignCCBMemberVariable(Object* target, const char* memberVariableName, Node* node);
    
    CREATE_FUNC(MenuLayer);
    
public:
    cocos2d::LabelTTF *label1;
    
};





class MenuLayerLoader : public cocos2d::extension::LayerLoader {
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(MenuLayerLoader, loader);
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(MenuLayer);
};



class MenuScene : public cocos2d::Scene, public cocos2d::extension::CCBSelectorResolver
// no necesario pero para acordarme de sobreescribirlo
    , public cocos2d::extension::CCBMemberVariableAssigner
    , public cocos2d::extension::CCBAnimationManagerDelegate
{
public:
    bool init(const char *ccb_filename);

    // SelectorResolver
    virtual cocos2d::SEL_MenuHandler onResolveCCBCCMenuItemSelector(Object * pTarget, const char* pSelectorName);
    virtual cocos2d::SEL_CallFuncN onResolveCCBCCCallFuncSelector(Object * pTarget, const char* pSelectorName);
    virtual cocos2d::extension::Control::Handler onResolveCCBCCControlSelector(Object * pTarget, const char* pSelectorName);

    // VariableAsigner
    bool onAssignCCBMemberVariable(Object* target, const char* memberVariableName, Node* node);

    // AnimationDelegate
    void completedAnimationSequenceNamed(const char *name);
    
    void enter(Object *pSender);
    void back(Object *pSender);
    void info(Object *pSender);
    
    MenuLayer *layer;
};





#endif /* defined(__Rcycle__SceneLoadManager__) */
