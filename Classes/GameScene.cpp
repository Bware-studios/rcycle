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

using namespace std;
using namespace cocosbuilder;

bool GameScene::init() {
    cout << "Init GameScene\n";
    //cout << "CC_ENABLE_CHIPMUNK_INTEGRATION: " << CC_ENABLE_CHIPMUNK_INTEGRATION << "\n";
    
    if ( ! Scene::initWithPhysics() ) return false;

    backLayer = SceneLoadManager::getInstance()->layerFromFile("GameLayer",this);

    frontLayer = SceneLoadManager::getInstance()->layerFromFile("FrontLayer",this);

    
    PhysicsWorld *world;
    world=this->getPhysicsWorld();
    world->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
    
//    DrawPrimitives::setDrawColor4F(1.0, 0, 0, 1.0);
    
    PhysicsBody *borde=PhysicsBody::createEdgeBox(Size(Point(200,200)));
    //world->addBody(borde);
    
    cout<<"debug draw: "<<this->getPhysicsWorld()->getDebugDrawMask()<<"\n";
    //this->getPhysicsWorld()->setGravity(Point(0,-10));
    
    
    auto sf=SpriteFrame::create("s1.png",Rect(0,0,64,64));
    //PhysicsBody::createCircle(10);
    

    PhysicsBody *sb;
    sb=PhysicsBody::createCircle(42);
    Sprite *s2=Sprite::createWithSpriteFrame(sf);
    s2->setPhysicsBody(sb);
    s2->setPosition(Point(200,200));
    s2->setRotation(10);
    backLayer->addChild(s2,20);
    
    s2=Sprite::createWithSpriteFrame(sf);
    sb=PhysicsBody::createCircle(42);
    sb->setDynamic(false);
    s2->setPhysicsBody(sb);
    s2->setPosition(Point(210,100));
    
    backLayer->addChild(s2,20);
    
  //  s2->setB2Body();
  //  PhysicsWorld *w = this->getPhysicsWorld();
    
    
    
    addChild(backLayer,1);
    addChild(frontLayer,10);
    
    
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

void GameScene::draw()
{
//    DrawPrimitives::setDrawColor4F(1.0, 0, 0, 1.0);
    DrawPrimitives::drawRect(Point(20,20),Point(300,40));
}


