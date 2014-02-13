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


//const bool debug_draw_physics = true;
//const bool debug_draw_alfa = false;


GameScene *GameScene::thegamescene=NULL;


bool GameScene::init() {
    GameScene::thegamescene = this;
    LOG("Init GameScene");
    
    if ( ! Scene::initWithPhysics() ) return false;

    backLayer = LayerColor::create(Color4B(255,255,255,Options::debug_draw_background?255:0));
    gameLayer = SceneLoadManager::getInstance()->layerFromFile("GameLayer",this);

    frontLayer = SceneLoadManager::getInstance()->layerFromFile("FrontLayer",this);
    
    
    PhysicsWorld *world;
    world=this->getPhysicsWorld();
    if (Options::debug_draw_physics) world->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
    
//    DrawPrimitives::setDrawColor4F(1.0, 0, 0, 1.0);

    
    //PhysicsBody *borde=PhysicsBody::createEdgeBox(Size(Point(200,200)));
    //world->addBody(borde);
    
    LOG("debug draw: %u",this->getPhysicsWorld()->getDebugDrawMask());
    //this->getPhysicsWorld()->setGravity(Point(0,-10));
    
    
//    auto sf=SpriteFrame::create("s1.png",Rect(0,0,64,64));
//    sf=SpriteFrameCache::getInstance()->getSpriteFrameByName("trashs/t1.png");
    //PhysicsBody::createCircle(10);
    

//    PhysicsBody *sb;
//    sb=PhysicsBody::createCircle(32);
//    sb->setCategoryBitmask(1);
//    sb->setContactTestBitmask(4);
//    sb->setCollisionBitmask(4);
//    Sprite *s2=Sprite::createWithSpriteFrame(sf);
//    s2->setPhysicsBody(sb);
//    s2->setPosition(Point(200,200));
//    s2->setRotation(10);
//    s2->setOpacity(150);
//    gameLayer->addChild(s2,20);
//    
//    s2=Sprite::createWithSpriteFrame(sf);
//    sb=PhysicsBody::createCircle(32);
//    sb->setCategoryBitmask(2);
//    sb->setContactTestBitmask(1);
//    sb->setCollisionBitmask(0);
//    sb->setDynamic(false);
//    s2->setPhysicsBody(sb);
//    s2->setPosition(Point(210,100));
//    s2->setOpacity(150);
//
//    gameLayer->addChild(s2,20);
    
//    Texture2D *t1;
//    t1=new Texture2D();
//    short texdata[]={0x0f0f,0x0f0f,0x0f0f , 0x0f0f,0x0f0f,0x0f0f , 0x0f0f,0x0f0f,0x0f0f   };
//    t1->initWithData(texdata, 18, Texture2D::PixelFormat::RGBA4444, 3, 3, Size(3,3));
//    s2=Sprite::createWithTexture(t1,Rect(0, 0, 500, 60));
//    s2->setPosition(Point(240,0));
//    Point sueloshape[]={Point(-200,0),Point(-240,30),Point(240,30),Point(200,0)};
////    sb=PhysicsBody::createPolygon(sueloshape, 4);
//    sb=PhysicsBody::createEdgeSegment(Point(-200,0), Point(200,0));
//    sb->addShape(PhysicsShapeEdgeSegment::create(Point(-200,0), Point(-240,30)));
//    sb->addShape(PhysicsShapeEdgeSegment::create(Point(200,0), Point(240,30)));
//    sb->setDynamic(false);
//    sb->setCategoryBitmask(4);
//    sb->setContactTestBitmask(UINT32_MAX);
//    sb->setCollisionBitmask(7);
//
//    s2->setPhysicsBody(sb);
//    s2->setOpacity(100);
//    gameLayer->addChild(s2,20);
    
    touch_down=false;
    touch_sprite=NULL;
    touch_joint=NULL;
    touch_cursorsprite=Sprite::create();
    touch_cursorbody=PhysicsBody::create();
    touch_cursorsprite->setPhysicsBody(touch_cursorbody);
    touch_cursorbody->setDynamic(false);
    gameLayer->addChild(touch_cursorsprite);
    
//    Texture2D *tex1;
//    tex1=new Texture2D();
//    unsigned short texdata[]={0x0f0f,0x0f0f,0x0f0f , 0x0f0f,0xf0ff,0x0f0f , 0x0f0f,0x0f0f,0x0f0f   };
//    tex1->initWithData(texdata, 18, Texture2D::PixelFormat::RGBA4444, 3, 3, Size(3,3));
//    touch_cursorsprite->setDisplayFrame(SpriteFrame::createWithTexture(tex1, Rect(0,0,10,10)));

    
  //  s2->setB2Body();
  //  PhysicsWorld *w = this->getPhysicsWorld();
    
    
    WorldFrame *wf;
    wf=WorldFrame::create();
    wf->add_to_layer(gameLayer);
    
    
    Trash *ts1;
    ts1=Trash::create(0, 3);
    ts1->setPosition(Point(150,210));
    ts1->add_to_layer(gameLayer);

    ts1=Trash::create(0, 2);
    ts1->setPosition(Point(200,200));
    ts1->add_to_layer(gameLayer);

    ts1=Trash::create(0, 1);
    ts1->setPosition(Point(260,250));
    ts1->add_to_layer(gameLayer);

    ts1=Trash::create(0, 0);
    ts1->setPosition(Point(280,240));
    ts1->add_to_layer(gameLayer);

    ts1=Trash::create(0, 3);
    ts1->setPosition(Point(320,200));
    ts1->add_to_layer(gameLayer);


    ts1=Trash::create(0, 3);
    ts1->setPosition(Point(260,250));
    ts1->add_to_layer(gameLayer);

    ts1=Trash::create(0, 3);
    ts1->setPosition(Point(280,240));
    ts1->add_to_layer(gameLayer);

    ts1=Trash::create(0, 3);
    ts1->setPosition(Point(320,200));
    ts1->add_to_layer(gameLayer);
    
    
    Container *c1;
    c1=Container::create(Trash::CAT_ORGANICO);
    c1->setPosition(Point(40,40));
    c1->add_to_layer(gameLayer);
    //gameLayer->addChild(c1);
    c1=Container::create(Trash::CAT_PAPEL);
    c1->setPosition(Point(170,35));
    c1->add_to_layer(gameLayer);
    //gameLayer->addChild(c1);
    c1=Container::create(Trash::CAT_PLASTICO);
    c1->setPosition(Point(310,40));
    c1->add_to_layer(gameLayer);
    //gameLayer->addChild(c1);
    c1=Container::create(Trash::CAT_CRISTAL);
    c1->setPosition(Point(430,100));
    c1->add_to_layer(gameLayer);
    //gameLayer->addChild(c1);

    PhysicsBody *sb1=PhysicsBody::create();
    sb1->setDynamic(false);
    //s1->setPhysicsBody(sb1);
    
    addChild(backLayer,1);
    addChild(gameLayer,2);
    addChild(frontLayer,10);
    
    
    EventListenerPhysicsContact *e = EventListenerPhysicsContact::create();
    e->onContactBegin=CC_CALLBACK_2(GameScene::contact_begin,this);
    e->onContactPreSolve=CC_CALLBACK_3(GameScene::contact_presolve,this);
    e->onContactPostSolve=CC_CALLBACK_3(GameScene::contact_postsolve,this);
    e->onContactSeperate=CC_CALLBACK_2(GameScene::contact_separate,this);
    
    
    EventDispatcher *edispatcher = this->getEventDispatcher();
    edispatcher->addEventListenerWithSceneGraphPriority(e,this);
    
    EventListenerTouchOneByOne *etouch = EventListenerTouchOneByOne::create();
    etouch->onTouchBegan=CC_CALLBACK_2(GameScene::touch_began,this);
    etouch->onTouchMoved=CC_CALLBACK_2(GameScene::touch_moved,this);
    etouch->onTouchEnded=CC_CALLBACK_2(GameScene::touch_ended,this);
    etouch->onTouchCancelled=CC_CALLBACK_2(GameScene::touch_cancelled,this);
    edispatcher->addEventListenerWithSceneGraphPriority(etouch, this);
    
    this->runAction(Sequence::createWithTwoActions(DelayTime::create(20.0),CallFunc::create(CC_CALLBACK_0(GameScene::time_passes, this))));


    //this->setScale(0.5);
    
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
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "action_resume", GameScene::action_resume);
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "action_quit", GameScene::action_quit);
    return NULL;
}

SEL_CallFuncN GameScene::onResolveCCBCCCallFuncSelector(Object * pTarget, const char* pSelectorName)
{
    return NULL;
}

Control::Handler GameScene::onResolveCCBCCControlSelector(Object * pTarget, const char* pSelectorName)
{
    CCB_SELECTORRESOLVER_CCCONTROL_GLUE(this, "pause_button", GameScene::action_pause);
    return NULL;
}


bool GameScene::onAssignCCBMemberVariable(Object* pTarget, const char* pMemberVariableName, Node* pNode)
{
    LOG_CCB("variable [%s]",pMemberVariableName);
//    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "s1", Sprite *, this->s1);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "score1", Sprite *, this->score1);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "pause_menu", Menu *, this->pause_menu);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "score_1", LabelTTF *, this->score_1);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "score_2", LabelTTF *, this->score_2);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "score_3", LabelTTF *, this->score_3);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "score_4", LabelTTF *, this->score_4);

    return true;
}


bool GameScene::contact_begin(EventCustom* event, const PhysicsContact& contact)
{
    LOG_COLLISION("contact...");
    PhysicsShape *s1 = contact.getShapeA();
    PhysicsShape *s2 = contact.getShapeB();
    PhysicsShape *sother;
    bool s1_issensor = (s1->getCategoryBitmask() & GameObject::cat_sensor);
    bool s2_issensor = (s2->getCategoryBitmask() & GameObject::cat_sensor);

    bool destroys1=false;
    
    if ( s1_issensor && !s2_issensor ) {
        destroys1=true;
        sother=s1;
        s1=s2;
    }
    
    if ( !s1_issensor && s2_issensor ) {
        destroys1=true;
        sother=s2;
    }
    
    if (destroys1) {
        // here s1 is not a sensor and sother is a sensor
        Trash *atrash=dynamic_cast<Trash*>(s1->getBody()->getNode());
        Container *acontainer=dynamic_cast<Container*>(sother->getBody()->getNode());
        LOG_COLLISION("s vs no s %p %p",acontainer,atrash);
        if (atrash && acontainer) {
            acontainer->destroy(atrash);
            LOG_COLLISION("destroy %p",atrash);
            gameLayer->removeChild(atrash);
            add_random_trash();
        }
        
    }
    LOG_COLLISION("");
    
    return true;
}

bool GameScene::contact_presolve(EventCustom* event, const PhysicsContact& contact,const PhysicsContactPreSolve& solve)
{
//    LOG("pre solve...");
    return true;
}

void GameScene::contact_postsolve(EventCustom* event, const PhysicsContact& contact,const PhysicsContactPostSolve& solve)
{
//    LOG("post solve...");
}


void GameScene::contact_separate(EventCustom* event, const PhysicsContact& contact)
{
    LOG_COLLISION("separate... [%d]",5);
 //   Log_msg("COL", "separate %d o",5);
}


bool GameScene::touch_began(Touch *t,Event *e)
{
    LOG_UI("began");
    if (touch_down) return false;
    touch_down=true;
//    touch_pos=t->getLocation();
    touch_pos=this->convertTouchToNodeSpace(t);
    PhysicsShape *selectedshape;
    selectedshape=getPhysicsWorld()->getShape(touch_pos);
    if (selectedshape) {
        touch_sprite=dynamic_cast<GameObject *>(selectedshape->getBody()->getNode());
        LOG_UI("is_dragable: %s",touch_sprite->is_dragable?"yes":"no");
        
//        touch_sprite->getPhysicsBody()->setDynamic(false);
        if (touch_sprite->is_dragable) {
            touch_cursorsprite->setPosition(touch_pos);
            touch_joint=PhysicsJointPin::construct(touch_sprite->getPhysicsBody(),touch_cursorbody,touch_pos);
            getPhysicsWorld()->addJoint(touch_joint);
            touch_sprite->getPhysicsBody()->setRotationEnable(false);
        } else {
            touch_sprite=NULL;
        }
    }
    
    return true;
}


void GameScene::touch_moved(Touch *t,Event *e)
{
    LOG_UI("moved");
    touch_pos=this->convertTouchToNodeSpace(t);
    if (!touch_sprite) return;
//    touch_sprite->setPosition(Point(old_sprite_pos.x+(touch_pos.x-old_pos.x),old_sprite_pos.y+(touch_pos.y-old_pos.y)));
    touch_cursorsprite->setPosition(touch_pos);
}


void GameScene::touch_ended(Touch *t,Event *e)
{
    LOG_UI("ended");
    touch_down=false;
    if (touch_sprite) {
  //      touch_sprite->getPhysicsBody()->setDynamic(true);
        touch_joint->removeFormWorld();
        touch_sprite->getPhysicsBody()->setRotationEnable(true);
    }
    touch_sprite=NULL;
    touch_joint=NULL;
}


void GameScene::touch_cancelled(Touch *t,Event *e)
{
    LOG_UI("cancelled");
    touch_down=false;
    if (touch_sprite) {
//        touch_sprite->getPhysicsBody()->setDynamic(true);
        touch_joint->removeFormWorld();
    }
    touch_sprite=NULL;
    touch_joint=NULL;
}


void GameScene::set_recycled(int category, int value)
{
    LabelTTF *thelabel;
    if (category==Trash::CAT_ORGANICO) thelabel=score_1;
    if (category==Trash::CAT_PLASTICO) thelabel=score_2;
    if (category==Trash::CAT_PAPEL) thelabel=score_3;
    if (category==Trash::CAT_CRISTAL) thelabel=score_4;

    thelabel->setString(std::to_string(value));

}


void GameScene::set_failed(int category, int value)
{
    
}


void GameScene::time_passes()
{
   // game_end();
}


void GameScene::draw()
{
//    DrawPrimitives::setDrawColor4F(1.0, 0, 0, 1.0);
//    DrawPrimitives::drawRect(Point(20,20),Point(300,40));
    if (touch_down) {
        DrawPrimitives::setDrawColor4F(0.0, 1.0, 0, 1.0);
        DrawPrimitives::drawLine(Point(0,touch_pos.y), Point(480,touch_pos.y));
        DrawPrimitives::drawLine(Point(touch_pos.x,0), Point(touch_pos.x,320));
    }
}

void GameScene::action_pause(Object *o,Control::EventType e)
{
    LOG_UI("click pause...");
    pause_menu->setVisible(true);
    pause();
}

void GameScene::action_resume(Object *o)
{
    LOG_UI("click resume...");
    pause_menu->setVisible(false);
    resume();
}

void GameScene::action_quit(Object *o)
{
    game_end();
}

void GameScene::game_end()
{
    auto newscene = FameScene::create();
    Director::getInstance()->replaceScene(newscene);
}

void GameScene::add_random_trash()
{
    Trash *ts1;
    int r1,r2;
    r1=rand()%2;
    r2=rand()%4;
    ts1=Trash::create(r1, r2);
    ts1->setPosition(Point(rand()%480,rand()%100+300));
    ts1->add_to_layer(gameLayer);
}



