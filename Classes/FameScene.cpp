//
//  FameScene.cpp
//  Rcycle
//
//  Created by Mikel on 10/11/13.
//
//

#include "FameScene.h"

#include "Scores.h"


USING_NS_CC;
USING_NS_CC_EXT;

using namespace std;
using namespace cocosbuilder;


bool FameScene::init() {
    if ( ! MenuScene::init("FameScene") ) return false;

    Scores::create();
    return true;
}


void FameScene::back(Ref *pSender)
{


    SceneLoadManager::getAnimationManager()->runAnimationsForSequenceNamed("salida");
    
    this->runAction(Sequence::createWithTwoActions(DelayTime::create(1.1),CallFunc::create(CC_CALLBACK_0(FameScene::exit_animation_finished, this))));

}

void FameScene::exit_animation_finished()
{
    auto newscene = MainMenuScene::create();
    Director::getInstance()->replaceScene(newscene);
}

