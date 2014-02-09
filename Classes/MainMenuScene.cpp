//
//  MainMenuScene.cpp
//  Rcycle
//
//  Created by Mikel on 31/10/13.
//
//

#include "MainMenuScene.h"

USING_NS_CC;
USING_NS_CC_EXT;

using namespace std;
using namespace cocosbuilder;

bool MainMenuScene::init() {
    if ( ! MenuScene::init("MainMenuScene") ) return false;
    
    Application::Platform platform = Application::getInstance()->getTargetPlatform();
    if ( platform == Application::Platform::OS_IPAD ||
         platform == Application::Platform::OS_IPHONE
       // || platform == Application::Platform::OS_MAC
        ) {
        quit_button->setVisible(false);
    }
    
    return true;
}





void MainMenuScene::enter(Object *pSender)
{
    LOG("juego");
    auto newscene = GameScene::create();
    Director::getInstance()->replaceScene(newscene);
}



void MainMenuScene::options(Object *pSender)
{
    auto newscene = OptionsScene::create();
    Director::getInstance()->replaceScene(newscene);
}


void MainMenuScene::info(Object *pSender)
{
    auto newscene = CreditsScene::create();
    Director::getInstance()->replaceScene(newscene);
}


void MainMenuScene::fame(Object *pSender)
{
    auto newscene = FameScene::create();
    Director::getInstance()->replaceScene(newscene);
}


void MainMenuScene::back(Object *pSender)
{
    Director::getInstance()->end();
}
