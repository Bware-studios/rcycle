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

    Scores *sc=Scores::create();
    
    for (int i=0; i<Scores::num_local_scores; i++) {
        scores_text<< (i+1) << ".\t" << sc->high_scores[i].name << "\t...\t" << sc->high_scores[i].score << "\n";
    }
    
    text1->setString(scores_text.str().c_str());
    
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

