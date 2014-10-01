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
    
    return true;
}


void HelpScene::back(Ref *pSender)
{
    auto newscene = MainMenuScene::create();
    Director::getInstance()->replaceScene(newscene);
}



