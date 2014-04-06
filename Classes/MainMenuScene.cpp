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
        //quit_button->setVisible(false);
    }
    
    SceneLoadManager::getAnimationManager()->runAnimationsForSequenceNamed("menu");

    this->runAction(Sequence::createWithTwoActions(DelayTime::create(2.0),CallFunc::create(CC_CALLBACK_0(MainMenuScene::time_passes, this))));

    sound_play_music(menu_theme_name);

    return true;
}




void MainMenuScene::time_passes()
{
    int r = 1+(rand()%3);
    char aname[30];
    sprintf(aname,"animation_%d",r);
    SceneLoadManager::getAnimationManager()->runAnimationsForSequenceNamed(aname);

    this->runAction(Sequence::createWithTwoActions(DelayTime::create(5.0),CallFunc::create(CC_CALLBACK_0(MainMenuScene::time_passes, this))));

}



void MainMenuScene::enter(Ref *pSender)
{
    LOG("juego");
    Game::create();
    auto newscene = GameScene::create();
    Director::getInstance()->replaceScene(newscene);
}



void MainMenuScene::options(Ref *pSender)
{
    auto newscene = OptionsScene::create();
    Director::getInstance()->replaceScene(newscene);
}


void MainMenuScene::info(Ref *pSender)
{
    auto newscene = CreditsScene::create();
    Director::getInstance()->replaceScene(newscene);
}


void MainMenuScene::fame(Ref *pSender)
{
    auto newscene = FameScene::create();
    Director::getInstance()->replaceScene(newscene);
}


void MainMenuScene::back(Ref *pSender)
{
    Director::getInstance()->end();
}
