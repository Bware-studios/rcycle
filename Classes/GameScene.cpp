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
    sb=PhysicsBody::createCircle(32);
    sb->setCategoryBitmask(1);
    sb->setContactTestBitmask(4);
    sb->setCollisionBitmask(4);
    Sprite *s2=Sprite::createWithSpriteFrame(sf);
    s2->setPhysicsBody(sb);
    s2->setPosition(Point(200,200));
    s2->setRotation(10);
    s2->setOpacity(150);
    backLayer->addChild(s2,20);
    
    s2=Sprite::createWithSpriteFrame(sf);
    sb=PhysicsBody::createCircle(32);
    sb->setCategoryBitmask(2);
    sb->setContactTestBitmask(1);
    sb->setCollisionBitmask(0);
    sb->setDynamic(false);
    s2->setPhysicsBody(sb);
    s2->setPosition(Point(210,100));
    s2->setOpacity(150);
    
    backLayer->addChild(s2,20);
    
    Texture2D *t1;
    t1=new Texture2D();
    short texdata[]={0x0f0f,0x0f0f,0x0f0f , 0x0f0f,0x0f0f,0x0f0f , 0x0f0f,0x0f0f,0x0f0f   };
    t1->initWithData(texdata, 18, Texture2D::PixelFormat::RGBA4444, 3, 3, Size(3,3));
    s2=Sprite::createWithTexture(t1,Rect(0, 0, 500, 60));
    s2->setPosition(Point(240,0));
    Point sueloshape[]={Point(-200,0),Point(-240,30),Point(240,30),Point(200,0)};
//    sb=PhysicsBody::createPolygon(sueloshape, 4);
    sb=PhysicsBody::createEdgeSegment(Point(-200,0), Point(200,0));
    sb->addShape(PhysicsShapeEdgeSegment::create(Point(-200,0), Point(-240,30)));
    sb->addShape(PhysicsShapeEdgeSegment::create(Point(200,0), Point(240,30)));
    sb->setDynamic(false);
    sb->setCategoryBitmask(4);
    sb->setContactTestBitmask(UINT32_MAX);
    sb->setCollisionBitmask(7);

    s2->setPhysicsBody(sb);
    s2->setOpacity(100);
    backLayer->addChild(s2,20);
    
    
  //  s2->setB2Body();
  //  PhysicsWorld *w = this->getPhysicsWorld();
    
    
    
    addChild(backLayer,1);
    addChild(frontLayer,10);
    
    
    EventListenerPhysicsContact *e = EventListenerPhysicsContact::create();
    e->onContactBegin=CC_CALLBACK_2(GameScene::contact_begin,this);
    e->onContactPreSolve=CC_CALLBACK_3(GameScene::contact_presolve,this);
    e->onContactPostSolve=CC_CALLBACK_3(GameScene::contact_postsolve,this);
    e->onContactSeperate=CC_CALLBACK_2(GameScene::contact_separate,this);
    
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(e,this);
    
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


bool GameScene::contact_begin(EventCustom* event, const PhysicsContact& contact)
{
    printf("contact...\n");
    return true;
}

bool GameScene::contact_presolve(EventCustom* event, const PhysicsContact& contact,const PhysicsContactPreSolve& solve)
{
    printf("pre solve...\n");
    return true;
}

void GameScene::contact_postsolve(EventCustom* event, const PhysicsContact& contact,const PhysicsContactPostSolve& solve)
{
    printf("post solve...\n");
}


void GameScene::contact_separate(EventCustom* event, const PhysicsContact& contact)
{
    printf("separate...\n");
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


