//
//  OptionsScene.cpp
//  Rcycle
//
//  Created by Mikel on 10/11/13.
//
//

#include "OptionsScene.h"

USING_NS_CC;
USING_NS_CC_EXT;

using namespace std;
using namespace cocosbuilder;

bool OptionsScene::init() {
    if ( ! MenuScene::init("OptionsScene") ) return false;
    return true;
}





void OptionsScene::enter(Ref *pSender)
{
    LOG("option1");
}


void OptionsScene::back(Ref *pSender)
{
    auto newscene = MainMenuScene::create();
    Director::getInstance()->replaceScene(newscene);
}



