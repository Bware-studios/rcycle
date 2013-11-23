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





void OptionsScene::enter(Object *pSender)
{
    cout<<"option1\n";
}


void OptionsScene::back(Object *pSender)
{
    auto newscene = MainMenuScene::create();
    Director::getInstance()->replaceScene(newscene);
}



