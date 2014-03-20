//
//  GameScene.h
//  Rcycle
//
//  Created by Mikel on 11/11/13.
//
//

#ifndef __Rcycle__GameScene__
#define __Rcycle__GameScene__

#include "Common.h"

//#include "cocos-ext.h"
#include "cocosbuilder/CocosBuilder.h"

#include "Options.h"

#include "SceneLoadManager.h"
#include "FameScene.h"
#include "Trash.h"
#include "Container.h"
#include "WorldFrame.h"

#include "TrashGenerator.h"


//extern const bool debug_draw_physics;
//extern const bool debug_draw_alfa;

class TrashGenerator;


class GameScene : public cocos2d::Scene,
public cocosbuilder::CCBSelectorResolver,
public cocosbuilder::CCBMemberVariableAssigner
//public cocosbuilder::CCBAnimationManagerDelegate
{
public:
    bool init();
    static GameScene *create();
    
    static GameScene *thegamescene;

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
    
    // queryrect callback for touch search
    bool touch_began_found_object(cocos2d::PhysicsWorld&world ,cocos2d::PhysicsShape& shape,void *data);
    
    // add trhashes interface
    void add_trash(int trash_type,int trash_category, cocos2d::Point &position);
    
    // counter manipulation
    void set_recycled(int category, int value);
    void set_failed(int category, int value);
    
    void time_passes();
    void update(float deltat);
    void draw();

    void action_pause(cocos2d::Object *o,cocos2d::extension::Control::EventType e);
    void action_resume(cocos2d::Object *o);
    void action_quit(cocos2d::Object *o);

    
    void game_end();
    
    void add_random_trash();
    
    
    
    cocos2d::Layer *backLayer;
    cocos2d::Layer *gameLayer;
    cocos2d::Layer *frontLayer;
    
    TrashGenerator *generator;
    
    
    bool touch_down;
    GameObject *touch_sprite;
    cocos2d::Point touch_pos;
    cocos2d::PhysicsJointPin *touch_joint;
    cocos2d::Sprite *touch_cursorsprite;
    cocos2d::PhysicsBody *touch_cursorbody;
    
    cocos2d::LabelTTF *score1;

    cocos2d::LabelTTF *score_1;
    cocos2d::LabelTTF *score_2;
    cocos2d::LabelTTF *score_3;
    cocos2d::LabelTTF *score_4;

    cocos2d::Menu *pause_menu;
    
    float gameTime=0.0;
    float gameEndTime;
};


#endif /* defined(__Rcycle__GameScene__) */
