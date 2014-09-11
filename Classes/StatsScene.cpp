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

    char score_s[40];
    sprintf(score_s,"Sc: %d",Game::thegame->get_last_wave_score());
    label_1->setString(score_s);

    sprintf(score_s,"%s",Game::thegame->get_last_wave_passed()?"Pasa":"No pasa" );
    label_2->setString(score_s);
    
    sprintf(score_s,"total: %d",Game::thegame->get_total_score());
    label_3->setString(score_s);

    
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


void StatsScene::start_exit_animation()
{
    SceneLoadManager::getAnimationManager()->runAnimationsForSequenceNamed("salida");
    //camion->start_exit_animation(Point(-240,160));
    this->runAction(Sequence::createWithTwoActions(DelayTime::create(1.1),CallFunc::create(CC_CALLBACK_0(StatsScene::event_camion_gone, this))));

}


void StatsScene::action_enter(Ref *pSender)
{
    if (!first_exit_pressed) {  // primera vez del boton   vuelta al juego o saca el record
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
    } else {
        start_exit_animation();
    }
}

void StatsScene::event_camion_gone()
{
    if (going_back_to_game) {
        GameScene::enter_game_scene(false);
    } else {
        auto newscene = MainMenuScene::create();
        Director::getInstance()->replaceScene(newscene);
    }
}


bool StatsScene::enter_player_name_for_record_if_needed() {
    int thescore=Game::thegame->get_last_wave_passed();
    if ( Scores::getInstance()->would_achieve_high_score(thescore) ) {
        std::string playername;
        playername=Scores::getInstance()->predicted_player_name();

        Size s=Director::getInstance()->getOpenGLView()->getDesignResolutionSize();
        field=cocos2d::ui::TextField::create();
        field->setPosition(Point(s.width/2,s.height*.8));
        field->setAnchorPoint(Point(0.5,0));
        field->setMaxLength(20);
        
        field->setPlaceHolder("write your name");
        field->setText(playername);
        field->setColor(Color3B(255,0,0));
        
        field->addEventListenerTextField(this,textfieldeventselector(StatsScene::text_field_event));
        
        this->addChild(field,100);
        
        
        
        Label *l1=Label::create("Your name?", "Helvetica", 20);
        l1->setPosition(Point(s.width/2,s.height*.95));
        l1->setColor(Color3B(0,0,0));
        this->addChild(l1,100);
        
        field->attachWithIME();

        
        
        return true;
    } else {
        // no pedimos nombre porque no ha hecho record
        return false;
    }
}


void StatsScene::text_field_event(cocos2d::Ref*sender,cocos2d::ui::TextFiledEventType event)
{
    printf("textfield event\n");
    if (event==ui::TextFiledEventType::TEXTFIELD_EVENT_INSERT_TEXT) {
        printf("insert %d\n",event);
    } else if (event==ui::TextFiledEventType::TEXTFIELD_EVENT_DETACH_WITH_IME) {
        printf("detach %d\n",event);
    } else {
        printf("e: %d\n",event);
    }
    
}



