//
//  SceneLoadManager.h
//  Rcycle
//
//  Created by Mikel on 29/10/13.
//
//

#ifndef __Rcycle__SceneLoadManager__
#define __Rcycle__SceneLoadManager__

#include "Common.h"


//#include "cocos-ext.h"
#include "cocosbuilder/CocosBuilder.h"

#include "Container.h"



class SceneLoadManager
{
public:
    SceneLoadManager();
    ~SceneLoadManager();
    static SceneLoadManager *getInstance();
    static cocosbuilder::CCBAnimationManager *getAnimationManager();
    
    cocos2d::Layer *layerFromFile(const char *pFileName,cocosbuilder::CCBSelectorResolver *pOwner=NULL);

    Container *containerFromFile(const char *pFileName,cocosbuilder::CCBSelectorResolver *pOwner=NULL);

    
private:
    static SceneLoadManager *theInstance;
    cocosbuilder::CCBReader *ccbReader;
};






class MenuLayer : public cocos2d::Layer
//, public cocos2d::extension::CCBSelectorResolver
//, public cocos2d::extension::CCBMemberVariableAssigner
{
public:
    bool init();
   // cocos2d::SEL_MenuHandler onResolveCCBCCMenuItemSelector(Object * pTarget, const char* pSelectorName);
   // cocos2d::SEL_CallFuncN onResolveCCBCCCallFuncSelector(Object * pTarget, const char* pSelectorName);
   // cocos2d::extension::Control::Handler onResolveCCBCCControlSelector(Object * pTarget, const char* pSelectorName);
    
   // bool onAssignCCBMemberVariable(Object* target, const char* memberVariableName, Node* node);
    
    CREATE_FUNC(MenuLayer);
    
//public:
//    cocos2d::LabelTTF *label1;
    
};





class MenuLayerLoader : public cocosbuilder::LayerLoader {
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(MenuLayerLoader, loader);
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(MenuLayer);
};



class MenuScene : public cocos2d::Scene, public cocosbuilder::CCBSelectorResolver
// no necesario pero para acordarme de sobreescribirlo
    , public cocosbuilder::CCBMemberVariableAssigner
    , public cocosbuilder::CCBAnimationManagerDelegate
{
public:
    bool init(const char *ccb_filename);

    // SelectorResolver
    virtual cocos2d::SEL_MenuHandler onResolveCCBCCMenuItemSelector(cocos2d::Ref * pTarget, const char* pSelectorName);
    virtual cocos2d::SEL_CallFuncN onResolveCCBCCCallFuncSelector(cocos2d::Ref * pTarget, const char* pSelectorName);
    virtual cocos2d::extension::Control::Handler onResolveCCBCCControlSelector(cocos2d::Ref * pTarget, const char* pSelectorName);

    // VariableAsigner
    virtual bool onAssignCCBMemberVariable(cocos2d::Ref* pTarget, const char* pMemberVariableName, Node* pNode);

    // AnimationDelegate
    virtual void completedAnimationSequenceNamed(const char *name);
    
    virtual void enter(cocos2d::Ref *pSender);
    virtual void back(cocos2d::Ref *pSender);
    virtual void info(cocos2d::Ref *pSender);
    virtual void options(cocos2d::Ref *pSender);
    virtual void fame(cocos2d::Ref *pSender);
    
    cocos2d::MenuItem *quit_button;
    
    MenuLayer *layer;
};


class GameLayer : public cocos2d::Layer
{
public:
    bool init();
    
    CREATE_FUNC(GameLayer);
    
};

class GameLayerLoader : public cocosbuilder::LayerLoader {
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(GameLayerLoader, loader);
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(GameLayer);
};


class StatsLayer : public cocos2d::Layer
{
public:
    bool init();
    
    CREATE_FUNC(StatsLayer);
    
};

class StatsLayerLoader : public cocosbuilder::LayerLoader {
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(StatsLayerLoader, loader);
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(StatsLayer);
};




class ContainerLoader : public cocosbuilder::SpriteLoader {
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(ContainerLoader, loader);
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(Container);
};




#endif /* defined(__Rcycle__SceneLoadManager__) */
