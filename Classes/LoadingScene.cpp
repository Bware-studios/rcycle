//
//  LoadingScene.cpp
//  Rcycle
//
//  Created by Mikel on 04/11/13.
//
//

#include "LoadingScene.h"

USING_NS_CC;
USING_NS_CC_EXT;

using namespace std;
using namespace cocosbuilder;

bool LoadingScene::init() {
    if ( ! MenuScene::init("LoadingScene") ) return false;

    state=0;
    
    this->runAction(Sequence::createWithTwoActions(DelayTime::create(1.0),CallFunc::create(CC_CALLBACK_0(LoadingScene::time_passes, this))));
//    this->schedule(schedule_selector(LoadingScene::time_passes),1.0);

    do_init();
    
    return true;
}


bool LoadingScene::onAssignCCBMemberVariable(Object* pTarget, const char* pMemberVariableName, Node* pNode)
{

    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "text1", LabelTTF *, this->text1);
    
    return true;
}


void LoadingScene::time_passes()
{
    bool reschedule=true;
    cout<<"time passes\n";
 
    state+=1;
    switch (state) {
        case 1:
            text1->setString("more loading...");
            break;
        case 2:
            text1->setString("importing...");
            break;
        case 3:
            text1->setString("doing other things...");
            break;
        case 4:
            start();
            reschedule=false;
            break;
            
    }
    
    if (!reschedule) return;
    this->runAction(Sequence::createWithTwoActions(DelayTime::create(1.0),CallFunc::create(CC_CALLBACK_0(LoadingScene::time_passes, this))));
//    this->schedule(schedule_selector(LoadingScene::time_passes),1.0);
}


void LoadingScene::start()
{
    cout << "go go go";
    auto newscene = MainMenuScene::create();
    Director::getInstance()->replaceScene(newscene);
}

void LoadingScene::do_init()
{
    SpriteFrameCache *sf_cache;
    sf_cache = SpriteFrameCache::getInstance();
    sf_cache->addSpriteFramesWithFile("trashs.plist");
}




