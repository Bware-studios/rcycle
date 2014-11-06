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

    Scores *sc=Scores::getInstance();
    ValueVector topscores = sc->local_top_scores;
    ValueVector::iterator j;
    int i;
    
    for (i=1,j=topscores.begin() ; j!=topscores.end() ; j++,i++) {
        ValueMap ascore;
        ascore = j->asValueMap();
        scores_text<<i<<".\t" << ascore.at("name").asString() << "\t...\t" << ascore.at("score").asString() << "\n";
    }
    
//    for (int i=0; i<Scores::num_local_scores; i++) {
//        scores_text<< (i+1) << ".\t" << sc->high_scores[i].name << "\t...\t" << sc->high_scores[i].score << "\n";
//    }
    
//    printf("%s\n",scores_text.str().c_str());
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

