//
//  GameScene.cpp
//  Rcycle
//
//  Created by Mikel on 11/11/13.
//
//

#include "GameScene.h"

USING_NS_CC;
USING_NS_CC_EXT;

bool GameScene::init() {
    cout << "Init GameScene\n";
    //cout << "CC_ENABLE_CHIPMUNK_INTEGRATION: " << CC_ENABLE_CHIPMUNK_INTEGRATION << "\n";
    cout << "CC_ENABLE_BOX2D_INTEGRATION: " << CC_ENABLE_BOX2D_INTEGRATION << "\n";
    
    if ( ! Scene::initWithPhysics() ) return false;

    backLayer = SceneLoadManager::getInstance()->layerFromFile("GameLayer",this);

    frontLayer = SceneLoadManager::getInstance()->layerFromFile("FrontLayer",this);

    auto sf=SpriteFrame::create("s1.png",Rect(0,0,128,128));
    PhysicsBody::createCircle(10);
    
    
    PhysicsSprite *s2=PhysicsSprite::createWithSpriteFrame(sf);
  //  s2->setB2Body(<#b2Body *pBody#>);
  //  PhysicsWorld *w = this->getPhysicsWorld();
    
    
    
    addChild(backLayer,1);
    addChild(frontLayer,10);
    
    backLayer->addChild(s2);
    
    this->runAction(Sequence::createWithTwoActions(DelayTime::create(20.0),CallFunc::create(CC_CALLBACK_0(GameScene::time_passes, this))));
    
    return true;
}



GameScene *GameScene::create()
{
    GameScene *pRet = new GameScene();
    if (pRet && pRet->init())
    {
        pRet->autorelease();
        return pRet;
    }
    else
    {
        CC_SAFE_DELETE(pRet);
        return NULL;
    }
}



SEL_MenuHandler GameScene::onResolveCCBCCMenuItemSelector(Object * pTarget, const char* pSelectorName)
{
    return NULL;
}

SEL_CallFuncN GameScene::onResolveCCBCCCallFuncSelector(Object * pTarget, const char* pSelectorName)
{
    return NULL;
}

Control::Handler GameScene::onResolveCCBCCControlSelector(Object * pTarget, const char* pSelectorName)
{
    return NULL;
}


bool GameScene::onAssignCCBMemberVariable(Object* pTarget, const char* pMemberVariableName, Node* pNode)
{
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "s1", Sprite *, this->s1);
    return true;
}



void GameScene::time_passes()
{
    auto newscene = FameScene::create();
    Director::getInstance()->replaceScene(newscene);
}

