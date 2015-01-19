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

#include "CocosGUI.h"
//#include "cocos-ext.h"
#include "cocosbuilder/CocosBuilder.h"

#include "Options.h"
#include "Camion.h"


class StatsScene : public cocos2d::Scene,
public cocosbuilder::CCBSelectorResolver,
public cocosbuilder::CCBMemberVariableAssigner
{
public:
    bool init();
    //static StatsScene *create();
    CREATE_FUNC(StatsScene);
    
    // SelectorResolver
    virtual cocos2d::SEL_MenuHandler onResolveCCBCCMenuItemSelector(cocos2d::Ref * pTarget, const char* pSelectorName);
    virtual cocos2d::SEL_CallFuncN onResolveCCBCCCallFuncSelector(cocos2d::Ref * pTarget, const char* pSelectorName);
    virtual cocos2d::extension::Control::Handler onResolveCCBCCControlSelector(cocos2d::Ref * pTarget, const char* pSelectorName);
    
    // VariableAsigner
    virtual bool onAssignCCBMemberVariable(cocos2d::Ref* target, const char* memberVariableName, Node* node);
    
    
    void start_exit_animation();
    void save_hisg_score_and_exit();
    void action_enter(cocos2d::Ref *pSender);
    void event_camion_gone();
    void event_exit_from_name_dialog(Dialogo* d, int b,std::string name);
    
    bool enter_player_name_for_record_if_needed();

    // listen to textfield
    //void text_field_event(cocos2d::Ref*sender,cocos2d::ui::TextFiledEventType event);
    
    
    cocos2d::Label *label_1;
    cocos2d::Label *label_2;
    cocos2d::Label *label_3;
    

    cocos2d::Layer *backLayer;
    cocos2d::Layer *statsLayer;
    
    Camion *camion;

    cocos2d::ui::TextField *field;
    
    bool going_back_to_game;
    bool first_exit_pressed;

};


#endif /* defined(__rcycle__StatsScene__) */
