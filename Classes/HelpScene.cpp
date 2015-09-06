//
//  HelpScene.cpp
//  rcycle
//
//  Created by Mikel on 01/10/14.
//
//

#include "HelpScene.h"

USING_NS_CC;
USING_NS_CC_EXT;

using namespace std;
using namespace cocosbuilder;

bool HelpScene::init() {
    if ( ! MenuScene::init("Instructions") ) return false;
    
    startGameAfterHelp=false;
    
    state=0;
    SceneLoadManager::getAnimationManager()->runAnimationsForSequenceNamed("Organico");

    
    EventListenerTouchOneByOne *etouch = EventListenerTouchOneByOne::create();
    etouch->onTouchBegan=CC_CALLBACK_2(HelpScene::touch_began,this);
    etouch->onTouchMoved=CC_CALLBACK_2(HelpScene::touch_moved,this);
    etouch->onTouchEnded=CC_CALLBACK_2(HelpScene::touch_ended,this);
    etouch->onTouchCancelled=CC_CALLBACK_2(HelpScene::touch_cancelled,this);
    EventDispatcher *edispatcher = this->getEventDispatcher();
    edispatcher->addEventListenerWithSceneGraphPriority(etouch, this);

    
    return true;
}

void HelpScene::setStartGameAfterHelp(bool start)
{
    startGameAfterHelp=start;
}


bool HelpScene::touch_began(cocos2d::Touch *t,cocos2d::Event *e)
{
    return true;
}

void HelpScene::touch_moved(cocos2d::Touch *t,cocos2d::Event *e)
{
}

void HelpScene::touch_ended(cocos2d::Touch *t,cocos2d::Event *e)
{
    back(NULL);
}

void HelpScene::touch_cancelled(cocos2d::Touch *t,cocos2d::Event *e)
{
}



void HelpScene::back(Ref *pSender)
{
    state+=1;
    if (state==1) {
        SceneLoadManager::getAnimationManager()->runAnimationsForSequenceNamed("Papel");
    } else if (state==2) {
        SceneLoadManager::getAnimationManager()->runAnimationsForSequenceNamed("Plastico");
    } else if (state==3) {
        SceneLoadManager::getAnimationManager()->runAnimationsForSequenceNamed("Vidrio");
    } else {
        if (startGameAfterHelp) {
            GameScene::enter_game_scene(true);
        } else {
            auto newscene = MainMenuScene::create();
            Director::getInstance()->replaceScene(newscene);
        }
    }
}



