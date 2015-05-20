//
//  GameScene.cpp
//  Rcycle
//
//  Created by Mikel on 11/11/13.
//
//

#include "GameScene.h"

#include "FameScene.h"
#include "StatsScene.h"



USING_NS_CC;
USING_NS_CC_EXT;

using namespace std;
using namespace cocosbuilder;


// description data
// se puede hacer que se cargue de fichero para tener diferentes niveles
const int container_n = 4;
const int container_type[] = {
    Trash::CAT_ORGANICO,
    Trash::CAT_PAPEL,
    Trash::CAT_PLASTICO,
    Trash::CAT_CRISTAL
};
Point container_position[] = {
    Point(-140,20),
    Point(-40,20),
    Point(60,20),
    Point(205,50),
};
// animacion de entrada
Point container_enter_movement_position[] = {
    Point(-140,-40),
    Point(-40,-40),
    Point(60,-40),
    Point(205,-150),
};
bool container_position_calculated=false;
const float container_enter_movement_duration[] = {
    2,2,2,2
};
const float container_delay_to_animation = 1;
const float container_animation_duration = 1;


const float touch_zone_height = 360;




GameScene *GameScene::thegamescene=NULL;

GameScene::~GameScene()
{
    generator->release();
}


bool GameScene::init() {
    GameScene::thegamescene = this;
    
    GLView *glview=Director::getInstance()->getOpenGLView();
    Size dr=glview->getDesignResolutionSize();
    LOG_RESOLUTION("gs dr: %f %f",dr.width,dr.height);
    //this->setAnchorPoint(Point(0.5,0));
    //this->ignoreAnchorPointForPosition(false);
    //this->setPosition(Point(dr.width/2,0));
    //this->setRotation(40);

    if (!container_position_calculated) {
        if (dr.width>480) container_position[3].x+=0.5*(dr.width-480);
        if (dr.width>480) container_enter_movement_position[3].x+=0.5*(dr.width-480);
    }
    container_position_calculated=true;
    
    LOG("Init GameScene");
    
    if ( ! Scene::initWithPhysics() ) return false;

    gameLayer = SceneLoadManager::getInstance()->layerFromFile("GameLayer",this);
//    gameLayer->setAnchorPoint(Point(0.5,0));
//    gameLayer->ignoreAnchorPointForPosition(false);
//    gameLayer->setPosition(Point(dr.width/2,0));
//    gameLayer->setAnchorPoint(Point(0.5,0));
//    gameLayer->setRotation(-30);
    AffineTransform tr1;
    tr1.a=1;
    tr1.b=0;
    tr1.c=0;
    tr1.d=1;
    tr1.tx=dr.width/2;
    tr1.ty=0;
    gameLayer->setAdditionalTransform(tr1);
    
    frontLayer = SceneLoadManager::getInstance()->layerFromFile("FrontLayer",this);
    
    backLayer = LayerColor::create(Color4B(255,255,255,Options::debug_draw_background?255:0));
    fondo_sprite->removeFromParent();
    if (Options::debug_draw_background) {
        backLayer->addChild(fondo_sprite);
    }

    score2=Label::create("0 / 0", score1->getFontName(), score1->getFontSize());
    score2->setPosition(Point(dr.width-10,312));
    score2->setVerticalAlignment(score1->getVerticalAlignment());
    score2->setAlignment(CCTextAlignment::RIGHT);
    score2->setColor(score1->getColor());
    score2->setAnchorPoint(Point(1,1));
    frontLayer->addChild(score2);
    update_score_display();
    
    PhysicsWorld *world;
    world=this->getPhysicsWorld();
    world->setGravity(Point(0,-Options::physics_g));

    if (Options::debug_draw_physics) world->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
    
//    DrawPrimitives::setDrawColor4F(1.0, 0, 0, 1.0);

    
    //PhysicsBody *borde=PhysicsBody::createEdgeBox(Size(Point(200,200)));
    //world->addBody(borde);
    
    LOG("debug draw: %u",this->getPhysicsWorld()->getDebugDrawMask());
    
    
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
    
    
//    Trash *ts1;
//    ts1=Trash::create(0, 3);
//    ts1->setPosition(Point(150,210));
//    ts1->add_to_layer(gameLayer);
//
//    ts1=Trash::create(0, 2);
//    ts1->setPosition(Point(200,200));
//    ts1->add_to_layer(gameLayer);
//
//    ts1=Trash::create(0, 1);
//    ts1->setPosition(Point(260,250));
//    ts1->add_to_layer(gameLayer);
//
//    ts1=Trash::create(0, 0);
//    ts1->setPosition(Point(280,240));
//    ts1->add_to_layer(gameLayer);
//
//    ts1=Trash::create(0, 3);
//    ts1->setPosition(Point(320,200));
//    ts1->add_to_layer(gameLayer);
//
//
//    ts1=Trash::create(0, 3);
//    ts1->setPosition(Point(260,250));
//    ts1->add_to_layer(gameLayer);
//
//    ts1=Trash::create(0, 3);
//    ts1->setPosition(Point(280,240));
//    ts1->add_to_layer(gameLayer);
//
//    ts1=Trash::create(0, 3);
//    ts1->setPosition(Point(320,200));
//    ts1->add_to_layer(gameLayer);
    
    container_sprite=new Container*[container_n];
    int i;
    for (i=0;i<container_n;i++) {
        container_sprite[i]=Container::create(container_type[i]);
        container_sprite[i]->setPosition(container_enter_movement_position[i]);
        container_sprite[i]->add_to_layer(gameLayer);
        container_sprite[i]->start_enter_animation(container_enter_movement_position[i], container_position[i]);
    }
    this->runAction(Sequence::createWithTwoActions(DelayTime::create(container_delay_to_animation),CallFunc::create(CC_CALLBACK_0(GameScene::enter_animation_ended, this))));
    
//    c1=Container::create(Trash::CAT_ORGANICO);
//    c1->setPosition(Point(40,40));
//    c1->add_to_layer(gameLayer);
//    //gameLayer->addChild(c1);
//    c1=Container::create(Trash::CAT_PAPEL);
//    c1->setPosition(Point(170,35));
//    c1->setPosition(Point(170,150));
//    c1->add_to_layer(gameLayer);
//    //gameLayer->addChild(c1);
//    c1=Container::create(Trash::CAT_PLASTICO);
//    c1->setPosition(Point(310,40));
//    c1->add_to_layer(gameLayer);
//    //gameLayer->addChild(c1);
//    c1=Container::create(Trash::CAT_CRISTAL);
//    c1->setPosition(Point(430,100));
//    c1->add_to_layer(gameLayer);
//    //gameLayer->addChild(c1);


    
    PhysicsBody *sb1=PhysicsBody::create();
    sb1->setDynamic(false);
    //s1->setPhysicsBody(sb1);
    
    addChild(backLayer,1);
    addChild(gameLayer,2);
    addChild(frontLayer,10);
    

    EventListenerPhysicsContact *e = EventListenerPhysicsContact::create();
    e->onContactBegin=CC_CALLBACK_1(GameScene::contact_begin,this);
    e->onContactPreSolve=CC_CALLBACK_2(GameScene::contact_presolve,this);
    e->onContactPostSolve=CC_CALLBACK_2(GameScene::contact_postsolve,this);
    e->onContactSeperate=CC_CALLBACK_1(GameScene::contact_separate,this);
    
    
    EventDispatcher *edispatcher = this->getEventDispatcher();
    edispatcher->addEventListenerWithSceneGraphPriority(e,this);
    
    EventListenerTouchOneByOne *etouch = EventListenerTouchOneByOne::create();
    etouch->onTouchBegan=CC_CALLBACK_2(GameScene::touch_began,this);
    etouch->onTouchMoved=CC_CALLBACK_2(GameScene::touch_moved,this);
    etouch->onTouchEnded=CC_CALLBACK_2(GameScene::touch_ended,this);
    etouch->onTouchCancelled=CC_CALLBACK_2(GameScene::touch_cancelled,this);
    edispatcher->addEventListenerWithSceneGraphPriority(etouch, this);
    

//    Trash *debugtrash;
//    debugtrash=Trash::create();
//    debugtrash->getPhysicsBody()->setDynamic(false);
//    debugtrash->setPosition(480,160);
//    debugtrash->add_to_layer(backLayer);
    
    generator=TrashGenerator::createWithScene(this);
    generator->retain();


    score1->setString("0");
    
    if (Options::debug_draw_outside) {
        this->setScale(Options::debug_draw_outside_scale);
    }
    
    
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



SEL_MenuHandler GameScene::onResolveCCBCCMenuItemSelector(Ref * pTarget, const char* pSelectorName)
{
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "action_resume", GameScene::action_resume);
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "action_quit", GameScene::action_quit);
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "pause_button", GameScene::m_action_pause);

    return NULL;
}

SEL_CallFuncN GameScene::onResolveCCBCCCallFuncSelector(Ref * pTarget, const char* pSelectorName)
{
    return NULL;
}

Control::Handler GameScene::onResolveCCBCCControlSelector(Ref * pTarget, const char* pSelectorName)
{
    CCB_SELECTORRESOLVER_CCCONTROL_GLUE(this, "pause_button", GameScene::action_pause);
    return NULL;
}


bool GameScene::onAssignCCBMemberVariable(Ref* pTarget, const char* pMemberVariableName, Node* pNode)
{
    LOG_CCB("variable [%s]",pMemberVariableName);

    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "score1", Label *, this->score1);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "pause_menu", Menu *, this->pause_menu);
//    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "score_1", Label *, this->score_1);
//    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "score_2", Label *, this->score_2);
//    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "score_3", Label *, this->score_3);
//    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "score_4", Label *, this->score_4);

    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "fondo", Sprite  *, this->fondo_sprite);

    
    return true;
}


bool GameScene::contact_begin(const PhysicsContact& contact)
{
    LOG_COLLISION("contact...");
    PhysicsShape *s1 = contact.getShapeA();
    PhysicsShape *s2 = contact.getShapeB();
    PhysicsShape *sother;
    bool s1_issensor = (s1->getCategoryBitmask() & GameObject::cat_sensor);
    bool s2_issensor = (s2->getCategoryBitmask() & GameObject::cat_sensor);

    LOG_COLLISION("sensors s1 %d : %d s2 %d : %d",s1->getCategoryBitmask(),s1_issensor,s2->getCategoryBitmask(),s2_issensor);
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
        Container *acontainer;
        WorldFrame *aborder;
        
        if (atrash) {
            acontainer=dynamic_cast<Container*>(sother->getBody()->getNode());
            if (acontainer) {
                acontainer->destroy(atrash);
                LOG_COLLISION("destroy in container %p",atrash);
                //gameLayer->removeChild(atrash);
                //add_random_trash();
                //sound_play_effect(sound_botella1);
            } else {
                aborder=dynamic_cast<WorldFrame*>(sother->getBody()->getNode());
                if (aborder) {
                    aborder->destroy(atrash);
                    LOG_COLLISION("destroy in border %p",atrash);
                    //gameLayer->removeChild(atrash);
                    //add_random_trash();
                }
            }
        }
    }
    LOG_COLLISION("");
    
    return true;
}

bool GameScene::contact_presolve(const PhysicsContact& contact,const PhysicsContactPreSolve& solve)
{
//    LOG("pre solve...");
    return true;
}

void GameScene::contact_postsolve(const PhysicsContact& contact,const PhysicsContactPostSolve& solve)
{
//    LOG("post solve...");
}


void GameScene::contact_separate(const PhysicsContact& contact)
{
    LOG_COLLISION("separate... [%d]",5);
 //   Log_msg("COL", "separate %d o",5);
}


bool GameScene::touch_began(Touch *t,Event *e)
{
    LOG_UI("began");
    if (touch_down) return false;
    touch_sprite=NULL;
    touch_down=true;
//    touch_pos=t->getLocation();
    touch_pos=this->convertTouchToNodeSpace(t);
//    PhysicsShape *selectedshape;
//    selectedshape=getPhysicsWorld()->getShape(touch_pos);
    
    if (touch_pos.y<320-touch_zone_height) {
        touch_down=false;
        return false;
    }
    
    PhysicsQueryRectCallbackFunc f;
    f=std::bind(&GameScene::touch_began_found_object,this,std::placeholders::_1,std::placeholders::_2,std::placeholders::_3);
    
    getPhysicsWorld()->queryRect(f,Rect(touch_pos.x-10,touch_pos.y-10,20,20), NULL);

//    if (selectedshape) {
//        touch_sprite=dynamic_cast<GameObject *>(selectedshape->getBody()->getNode());
//        LOG_UI("is_dragable: %s",touch_sprite->is_dragable?"yes":"no");
//        
////        touch_sprite->getPhysicsBody()->setDynamic(false);
//        if (touch_sprite->is_dragable) {
//            touch_cursorsprite->setPosition(touch_pos);
//            touch_joint=PhysicsJointPin::construct(touch_sprite->getPhysicsBody(),touch_cursorbody,touch_pos);
//            getPhysicsWorld()->addJoint(touch_joint);
//            touch_sprite->getPhysicsBody()->setRotationEnable(false);
//        } else {
//            touch_sprite=NULL;
//        }
//    }
    if (!touch_sprite) {
        touch_down=false;
        return false;
    }
    return true;
}


void GameScene::touch_moved(Touch *t,Event *e)
{
    LOG_UI("moved");
    touch_pos=this->convertTouchToNodeSpace(t);
    if (touch_pos.y<320-touch_zone_height) {
        touch_down=false;
        touch_destroy();
    }
    if (!touch_sprite) return;
//    touch_sprite->setPosition(Point(old_sprite_pos.x+(touch_pos.x-old_pos.x),old_sprite_pos.y+(touch_pos.y-old_pos.y)));
    touch_cursorsprite->setPosition(touch_pos);
}


void GameScene::touch_ended(Touch *t,Event *e)
{
    LOG_UI("ended");
    touch_destroy();
}


void GameScene::touch_cancelled(Touch *t,Event *e)
{
    LOG_UI("cancelled");
    touch_destroy();
}


void GameScene::touch_destroy()
{
    touch_down=false;
    if (touch_sprite) {
        //      touch_sprite->getPhysicsBody()->setDynamic(true);
        touch_joint->removeFormWorld();
        touch_sprite->getPhysicsBody()->setRotationEnable(true);
    }
    touch_sprite=NULL;
    touch_joint=NULL;
}


bool GameScene::touch_began_found_object(cocos2d::PhysicsWorld& world ,cocos2d::PhysicsShape& shape,void *data)
{
    LOG_UI("found_object %x\n",&shape);
    touch_sprite=dynamic_cast<GameObject *>(shape.getBody()->getNode());
    LOG_UI("is_dragable: %s",touch_sprite->is_dragable?"yes":"no");
    //        touch_sprite->getPhysicsBody()->setDynamic(false);
    if (touch_sprite->is_dragable) {
        touch_cursorsprite->setPosition(touch_pos);
        touch_joint=PhysicsJointPin::construct(touch_sprite->getPhysicsBody(),touch_cursorbody,touch_pos);
        touch_joint->setMaxForce(10000000);
        LOG_UI("joint created max force %f",touch_joint->getMaxForce());
        getPhysicsWorld()->addJoint(touch_joint);
        touch_sprite->getPhysicsBody()->setRotationEnable(false);
    } else {
       touch_sprite=NULL;
    }
    
    return false;
}


void GameScene::add_trash(int trash_type,int trash_category, Point &position, Vect &v)
{
    Trash *ts1;
    ts1=Trash::create(trash_type, trash_category);
    ts1->setPosition(position.x,position.y);
    ts1->getPhysicsBody()->setVelocity(v);
    ts1->add_to_layer(gameLayer);
}



void GameScene::update_score_display()
{
    int partial=Game::thegame->partial_score;
    int target=Game::thegame->score_target;
    char sstr[100];
    sprintf(sstr,"%d / %d",partial,target);
    score2->setString(sstr);
    if (partial>=target) {
        score2->setColor(Color3B(0,255,0));
    } else {
        score2->setColor(Color3B(255,0,0));
    }
}



//void GameScene::set_recycled(int category, int value)
//{
//    Label *thelabel;
//    char labelstring[10];
//    if (category==Trash::CAT_ORGANICO) thelabel=score_1;
//    if (category==Trash::CAT_PAPEL) thelabel=score_2;
//    if (category==Trash::CAT_PLASTICO) thelabel=score_3;
//    if (category==Trash::CAT_CRISTAL) thelabel=score_4;
//
//    sprintf(labelstring, "%d",value);
//    // para evitar problemas de añadir stl en la compilacion de android
//    //    thelabel->setString(std::to_string(value));
//    thelabel->setString(labelstring);
//}
//
//
//void GameScene::set_failed(int category, int value)
//{
// 
//}

void GameScene::enter_movement_ended()
{
//    for (int i=0 ; i<container_n ; i++) {
//        container_sprite[i]->play_enter_animation();
//    }
//    this->runAction(Sequence::createWithTwoActions(DelayTime::create(container_animation_duration),CallFunc::create(CC_CALLBACK_0(GameScene::enter_animation_ended, this))));

}


void GameScene::enter_animation_ended()
{
    generator->start();
    ingame=true;
    gameEndTime=gameTime+32.0;

    //this->runAction(Sequence::createWithTwoActions(DelayTime::create(20.0),CallFunc::create(CC_CALLBACK_0(GameScene::time_passes, this))));

    sound_play_music(game_theme_name);

}

void GameScene::finish_animation_ended()
{
    game_end();
}

void GameScene::time_passes()
{
   // game_end();
}

void GameScene::update(float deltat)
{
    gameTime+=deltat;
    
    if (ingame) {
        int secondsLeftToEnd=(int)(gameEndTime-gameTime);
        if (secondsLeftToEnd<0) secondsLeftToEnd=0;
        if (secondsLeftToEnd!=(int)(gameEndTime-gameTime+deltat)) {
            char labelstring[10];
            sprintf(labelstring, "%d",secondsLeftToEnd);
            // para evitar problemas de añadir stl en la compilacion de android
            //    score1->setString(std::to_string(secondsLeftToEnd));
            score1->setString(labelstring);

        }
        if (gameTime>gameEndTime) {
            //game_end();
            generator->stop();
            start_finish_animation();
        }
    }
    Scene::update(deltat);
}


//void GameScene::draw()
//{
////    DrawPrimitives::setDrawColor4F(1.0, 0, 0, 1.0);
////    DrawPrimitives::drawRect(Point(20,20),Point(300,40));
//    if (touch_down) {
//        DrawPrimitives::setDrawColor4F(0.0, 1.0, 0, 1.0);
//        DrawPrimitives::drawLine(Point(0,touch_pos.y), Point(480,touch_pos.y));
//        DrawPrimitives::drawLine(Point(touch_pos.x,0), Point(touch_pos.x,320));
//    }
//}

void GameScene::action_pause(Ref *o,Control::EventType e)
{
    LOG_UI("click pause...");
    pause_menu->setVisible(true);
    pause();
}

void GameScene::m_action_pause(Ref *o)
{
    LOG_UI("click pause...");
    pause_menu->setVisible(true);
    pause();
}


void GameScene::action_resume(Ref *o)
{
    LOG_UI("click resume...");
    pause_menu->setVisible(false);
    resume();
}

void GameScene::action_quit(Ref *o)
{
    game_end();
//    game_aborted();
}

void GameScene::start_finish_animation()
{
    ingame=false;
    touch_destroy();
    Trash::delete_all_trashes();
    int i;
    for (i=0;i<container_n;i++) {
        container_sprite[i]->start_exit_animation(container_enter_movement_position[i]);
//        ->runAction(MoveTo::create(container_enter_movement_duration[i], container_enter_movement_position[i]));
    }
    this->runAction(Sequence::createWithTwoActions(DelayTime::create(1.0),CallFunc::create(CC_CALLBACK_0(GameScene::finish_animation_ended, this))));
    
    
}


void GameScene::game_end()
{
    Game::thegame->wave_end();
    auto newscene = StatsScene::create();
    Director::getInstance()->replaceScene(newscene);
}

void GameScene::game_aborted()
{
    auto newscene = MainMenuScene::create();
    Director::getInstance()->replaceScene(newscene);
}

//void GameScene::add_random_trash()
//{
//    Trash *ts1;
//    int r1,r2;
//    r1=rand()%2;
//    r2=rand()%4;
//    ts1=Trash::create(r1, r2);
//    ts1->setPosition(Point(rand()%480,rand()%100+300));
//    ts1->add_to_layer(gameLayer);
//}



void GameScene::enter_game_scene(bool newgame)
{
    if (newgame) {
        if (Game::thegame) {Game::thegame->release();}
        Game::create();
    }
    auto newscene = GameScene::create();
    Director::getInstance()->replaceScene(newscene);
}

