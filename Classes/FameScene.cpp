//
//  FameScene.cpp
//  Rcycle
//
//  Created by Mikel on 10/11/13.
//
//

#include "FameScene.h"

USING_NS_CC;
USING_NS_CC_EXT;

bool FameScene::init() {
    if ( ! MenuScene::init("FameScene") ) return false;
    return true;
}


void FameScene::back(Object *pSender)
{
    auto newscene = MainMenuScene::create();
    Director::getInstance()->replaceScene(newscene);
}


