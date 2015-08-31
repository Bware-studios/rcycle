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
    if ( ! MenuScene::init("Instructions-2") ) return false;
    
    startGameAfterHelp=false;
    
    state=0;
    SceneLoadManager::getAnimationManager()->runAnimationsForSequenceNamed("Organico");
    
    return true;
}

void HelpScene::setStartGameAfterHelp(bool start)
{
    startGameAfterHelp=start;
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



