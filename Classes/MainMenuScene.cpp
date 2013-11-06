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

bool MainMenuScene::init() {
    if ( ! MenuScene::init("MainMenuScene") ) return false;
    return true;
}





void MainMenuScene::enter(Object *pSender)
{
    cout<<"juego\n";
}


void MainMenuScene::info(Object *pSender)
{
    auto newscene = CreditsScene::create();
    Director::getInstance()->replaceScene(newscene);
}



