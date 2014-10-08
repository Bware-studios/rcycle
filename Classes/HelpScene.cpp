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
    
    return true;
}

void HelpScene::setStartGameAfterHelp(bool start)
{
    startGameAfterHelp=start;
}



void HelpScene::back(Ref *pSender)
{
    if (startGameAfterHelp) {
        GameScene::enter_game_scene(true);
    } else {
        auto newscene = MainMenuScene::create();
        Director::getInstance()->replaceScene(newscene);
    }
}



