//
//  StatsScene.cpp
//  rcycle
//
//  Created by Mikel on 13/05/14.
//
//

#include "StatsScene.h"

#include "MainMenuScene.h"
#include "SceneLoadManager.h"

#include "Scores.h"
#include "Preferences.h"

#include "Dialogo.h"

USING_NS_CC;
USING_NS_CC_EXT;
using namespace cocos2d::ui;

bool StatsScene::init() {
    if ( ! Scene::init() ) return false;
    
    statsLayer=SceneLoadManager::getInstance()->layerFromFile("StatsScene",this);
    this->addChild(statsLayer,100);
    
    backLayer = LayerColor::create(Color4B(255,255,255,Options::debug_draw_background?255:0));
    this->addChild(backLayer,10);


    
// animations in scene
//    camion=Camion::createFromFile();
//    camion->add_to_layer(statsLayer);
//    camion->start_enter_animation(Point(600,160), Point(240,160));

    label_1->setString("...");
    label_2->setString("...");
    label_3->setString("...");

    label_1->setFontSize(10);
    label_1->setAlignment(CCTextAlignment::CENTER);
    label_2->setFontSize(10);
    label_2->setAlignment(CCTextAlignment::CENTER);
    label_3->setFontSize(10);
    label_3->setAlignment(CCTextAlignment::CENTER);
    
    bool passed = Game::thegame->get_last_wave_passed();
    char target_s[30];
    char score_s[40];
    if (!passed) {
        sprintf(target_s,"need %d",Game::thegame->score_target);
    }
    //sprintf(score_s,"Score: %d\n%s",Game::thegame->get_last_wave_score(),passed?"":target_s);
    sprintf(score_s,"Score: %d",Game::thegame->get_last_wave_score()/*,passed?"":target_s*/);
    label_1->setString(score_s);

    sprintf(score_s,"Lvl %d %s",Game::thegame->wave_completed+(passed?0:1),passed?"ok":"failed" );
    label_2->setColor(passed?Color3B(0, 255, 0):Color3B(255, 0, 0));
    label_2->setString(score_s);
    
    sprintf(score_s,"Total: %d",Game::thegame->get_total_score());
    label_3->setString(score_s);

    
    Dialogo *d=Dialogo::create();
    addChild(d);
    
    first_exit_pressed=false;
    
    return true;
}




SEL_MenuHandler StatsScene::onResolveCCBCCMenuItemSelector(Ref * pTarget, const char* pSelectorName)
{
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "enter", StatsScene::action_enter);
    //CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "action_quit", GameScene::action_quit);
    return NULL;
}

SEL_CallFuncN StatsScene::onResolveCCBCCCallFuncSelector(Ref * pTarget, const char* pSelectorName)
{
    return NULL;
}

Control::Handler StatsScene::onResolveCCBCCControlSelector(Ref * pTarget, const char* pSelectorName)
{
    //CCB_SELECTORRESOLVER_CCCONTROL_GLUE(this, "pause_button", GameScene::action_pause);
    return NULL;
}


bool StatsScene::onAssignCCBMemberVariable(Ref* pTarget, const char* pMemberVariableName, Node* pNode)
{
    //LOG_CCB("variable [%s]",pMemberVariableName);
    
    //CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "score1", Label *, this->score1);
    //CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "pause_menu", Menu *, this->pause_menu);
    //CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "score_1", Label *, this->score_1);
    //CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "score_2", Label *, this->score_2);
    //CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "score_3", Label *, this->score_3);
    //CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "score_4", Label *, this->score_4);

    
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "t1", Label *, this->label_1);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "t2", Label *, this->label_2);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "t3", Label *, this->label_3);

    
    return true;
}


void StatsScene::save_high_score_and_exit() {
    Scores *thescores=Scores::getInstance();
    thescores->save_score();
    start_exit_animation();
}


void StatsScene::start_exit_animation()
{
    SceneLoadManager::getAnimationManager()->runAnimationsForSequenceNamed("salida");
    //camion->start_exit_animation(Point(-240,160));
    this->runAction(Sequence::createWithTwoActions(DelayTime::create(1.1),CallFunc::create(CC_CALLBACK_0(StatsScene::event_camion_gone, this))));

}


void StatsScene::action_enter(Ref *pSender)
{
    //printf("action enter \n");
    if (Game::thegame->get_last_wave_passed()) {
        going_back_to_game=true;
        start_exit_animation();
    } else {
        bool record_achieved;
        record_achieved=enter_player_name_for_record_if_needed();
        if (!record_achieved) {
            start_exit_animation();
        }
    }
}

void StatsScene::event_camion_gone()
{
    if (going_back_to_game) {
        GameScene::enter_game_scene(false);
    } else {
        //auto newscene = MainMenuScene::create();
        //Director::getInstance()->replaceScene(newscene);
        GameScene::enter_game_scene(true);
    }
}

void StatsScene::event_exit_from_name_dialog(Dialogo* d, int b,std::string name)
{
    Preferences::getInstance()->setPlayerName(name);
    save_high_score_and_exit();
}

// return true if entered dialog
bool StatsScene::enter_player_name_for_record_if_needed() {
    bool high_score_achieved=Game::thegame->get_high_score_achieved();
    
    if ( high_score_achieved ) {
        std::string playername;
        //playername=Scores::getInstance()->get_player_name();
        playername=Preferences::getInstance()->getPlayerName();

        Dialogo::question_dialog("High score achieved","write your name",playername, "OK",CC_CALLBACK_3(StatsScene::event_exit_from_name_dialog,this));
        return true;
    } else {
        return false;
    }
}



