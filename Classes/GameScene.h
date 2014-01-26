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
//#include "cocos-ext.h"
#include "cocosbuilder/CocosBuilder.h"

#include "SceneLoadManager.h"
#include "FameScene.h"
#include "Trash.h"
#include "Container.h"

extern const bool debug_draw_physics;
extern const bool debug_draw_alfa;


class GameScene : public cocos2d::Scene,
public cocosbuilder::CCBSelectorResolver,
public cocosbuilder::CCBMemberVariableAssigner
//public cocosbuilder::CCBAnimationManagerDelegate
{
public:
    bool init();
    static GameScene *create();
    
    // SelectorResolver
    virtual cocos2d::SEL_MenuHandler onResolveCCBCCMenuItemSelector(Object * pTarget, const char* pSelectorName);
    virtual cocos2d::SEL_CallFuncN onResolveCCBCCCallFuncSelector(Object * pTarget, const char* pSelectorName);
    virtual cocos2d::extension::Control::Handler onResolveCCBCCControlSelector(Object * pTarget, const char* pSelectorName);

    // VariableAsigner
    virtual bool onAssignCCBMemberVariable(Object* target, const char* memberVariableName, Node* node);

    // contactlistener
    bool contact_begin(cocos2d::EventCustom* event, const cocos2d::PhysicsContact& contact);
    bool contact_presolve(cocos2d::EventCustom* event, const cocos2d::PhysicsContact& contact,const cocos2d::PhysicsContactPreSolve& solve);
    void contact_postsolve(cocos2d::EventCustom* event, const cocos2d::PhysicsContact& contact,const cocos2d::PhysicsContactPostSolve& solve);
    void contact_separate(cocos2d::EventCustom* event, const cocos2d::PhysicsContact& contact);
    
    // touchlistener
    bool touch_began(cocos2d::Touch *t,cocos2d::Event *e);
    void touch_moved(cocos2d::Touch *t,cocos2d::Event *e);
    void touch_ended(cocos2d::Touch *t,cocos2d::Event *e);
    void touch_cancelled(cocos2d::Touch *t,cocos2d::Event *e);
    
    void time_passes();
    void draw();
    void pause_pressed(cocos2d::Object *o,cocos2d::extension::Control::EventType e);
    
    cocos2d::Layer *backLayer;
    cocos2d::Layer *frontLayer;
    
    
    bool touch_down;
    cocos2d::Sprite *touch_sprite;
    cocos2d::Point touch_pos;
    cocos2d::PhysicsJointPin *touch_joint;
    cocos2d::Sprite *touch_cursorsprite;
    cocos2d::PhysicsBody *touch_cursorbody;
    
    cocos2d::Sprite *s1;
    cocos2d::Sprite *score1;
    
    cocos2d::Menu *pause_menu;
    
    
};


#endif /* defined(__Rcycle__GameScene__) */
