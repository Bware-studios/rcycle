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

USING_NS_CC;
USING_NS_CC_EXT;


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

    char score_s[40];
    sprintf(score_s,"Sc: %d",Game::thegame->get_last_wave_score());
    label_1->setString(score_s);

    sprintf(score_s,"%s",Game::thegame->get_last_wave_passed()?"Pasa":"No pasa" );
    label_2->setString(score_s);
    
    
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


void StatsScene::action_enter(Ref *pSender)
{
    
    SceneLoadManager::getAnimationManager()->runAnimationsForSequenceNamed("salida");

    //camion->start_exit_animation(Point(-240,160));
    this->runAction(Sequence::createWithTwoActions(DelayTime::create(1.1),CallFunc::create(CC_CALLBACK_0(StatsScene::event_camion_gone, this))));
}

void StatsScene::event_camion_gone()
{
    if (Game::thegame->get_last_wave_passed()) {
        GameScene::enter_game_scene(false);
    } else {
        auto newscene = MainMenuScene::create();
        Director::getInstance()->replaceScene(newscene);
    }
}


