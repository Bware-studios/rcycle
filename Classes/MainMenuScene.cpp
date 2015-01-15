//
//  MainMenuScene.cpp
//  Rcycle
//
//  Created by Mikel on 31/10/13.
//
//

#include "MainMenuScene.h"
#include "Preferences.h"

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
        quit_button->removeFromParent();
    }
    
    if ( Options::settings_button_show==false ) {
        settings_button->removeFromParent();
    }
    
    SceneLoadManager::getAnimationManager()->runAnimationsForSequenceNamed("menu");

    this->runAction(Sequence::createWithTwoActions(DelayTime::create(2.0),CallFunc::create(CC_CALLBACK_0(MainMenuScene::time_passes, this))));

    sound_play_music(menu_theme_name);

    return true;
}




void MainMenuScene::time_passes()
{
    return;
    
    
    int r = 1+(rand()%3);
    char aname[30];
    sprintf(aname,"animation_%d",r);
    SceneLoadManager::getAnimationManager()->runAnimationsForSequenceNamed(aname);

    this->runAction(Sequence::createWithTwoActions(DelayTime::create(5.0),CallFunc::create(CC_CALLBACK_0(MainMenuScene::time_passes, this))));

}



void MainMenuScene::enter(Ref *pSender)
{
    LOG("juego");
    int n = Preferences::getInstance()->setOneMoreGameStarted();
    if (n<Options::autohelp_n_firsttimes_show+1) {
        auto newscene = HelpScene::create();
        newscene->setStartGameAfterHelp(true);
        Director::getInstance()->replaceScene(newscene);
    } else {
        GameScene::enter_game_scene(true);
    }
}



void MainMenuScene::options(Ref *pSender)
{
    auto newscene = OptionsScene::create();
    Director::getInstance()->replaceScene(newscene);
}

void MainMenuScene::help(Ref *pSender)
{
    auto newscene = HelpScene::create();
    Director::getInstance()->replaceScene(newscene);
    
}


void MainMenuScene::info(Ref *pSender)
{
    // Dialogo::info_dialog("Important information here\nbe warned\nand think about it", "OK",CC_CALLBACK_2(MainMenuScene::try_callback,this));
     Dialogo::question_dialog("di algo", "OK",CC_CALLBACK_3(MainMenuScene::try_text_callback,this));
    // Dialogo::yes_no_dialog("Decide\nser o no ser?", "Ser", "No ser",CC_CALLBACK_2(MainMenuScene::try_callback,this));

    //    auto newscene = CreditsScene::create();
//    Director::getInstance()->replaceScene(newscene);
}

void MainMenuScene::try_callback(Dialogo *sender, int b)
{
    printf("has salido con el boton %d\n",b);
}


void MainMenuScene::try_text_callback(Dialogo *sender, int b,std::string texto)
{
    printf("has salido con el boton %d respuests %s\n",b,texto.c_str());
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
