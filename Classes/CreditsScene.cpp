//
//  CreditsScene.cpp
//  Rcycle
//
//  Created by Mikel on 06/11/13.
//
//

#include "CreditsScene.h"

USING_NS_CC;
USING_NS_CC_EXT;

using namespace std;
using namespace cocosbuilder;

bool CreditsScene::init() {
    if ( ! MenuScene::init("CreditsScene") ) return false;
    return true;
}


void CreditsScene::back(Object *pSender)
{
    auto newscene = MainMenuScene::create();
    Director::getInstance()->replaceScene(newscene);
}



