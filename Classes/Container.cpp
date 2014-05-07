//
//  Container.cpp
//  Rcycle
//
//  Created by Mikel on 13/12/13.
//
//

#include "Container.h"

#include "Trash.h"
#include "Game.h"



USING_NS_CC;

// normal container
const int normal_semiheight = 40;
const int normal_semiwidth = 70;
const int normal_semiindent = 10;
const int normal_verticalindent =0;

//  container
const int x_semiheight = 60;
const int x_semiwidth = 50;
const int x_semiindent = 0;
const int x_verticalindent = 40;


bool Container::init()
{
    // common init for all container types
    GameObject::init();
    
    return true;
}

bool Container::init(int p_trash_category)
{
    // choose category
    trash_category=p_trash_category;
    
    if (p_trash_category==Trash::CAT_CRISTAL) {
        semiheight=x_semiheight;
        semiwidth=x_semiwidth;
        semiindent=x_semiindent;
        verticalindent=x_verticalindent;
    } else {
        semiheight=normal_semiheight;
        semiwidth=normal_semiwidth;
        semiindent=normal_semiindent;
        verticalindent=normal_verticalindent;
    }
    
    Texture2D *tex1;
    tex1=new Texture2D();
    unsigned short texdata[]={0x0f0f,0x0f0f,0x0f0f , 0x0f0f,0xf0ff,0x0f0f , 0x0f0f,0x0f0f,0x0f0f   };
    tex1->initWithData(texdata, 18, Texture2D::PixelFormat::RGBA4444, 3, 3, Size(3,3));
    if (Options::debug_draw_spritesquare) {

        this->setDisplayFrame(SpriteFrame::createWithTexture(tex1, Rect(0,0,2*semiwidth,2*semiheight)));
    } else {
        
        const char *img_name = NULL;
        if (p_trash_category==Trash::CAT_PLASTICO) {
            img_name="Contenedores/Contenedor0001.png";
        } else if (p_trash_category==Trash::CAT_PAPEL) {
            img_name="Contenedores/Contenedor0002.png";
        } else if (p_trash_category==Trash::CAT_ORGANICO) {
            img_name="Contenedores/Contenedor0003.png";
        } else if (p_trash_category==Trash::CAT_CRISTAL) {
            img_name="Contenedores/Contenedor0004.png";
        }
        if (img_name) {
            SpriteFrame *sf = SpriteFrameCache::getInstance()->getSpriteFrameByName(img_name);
            if (sf) this->setDisplayFrame(sf);
        } else {
            this->setDisplayFrame(SpriteFrame::createWithTexture(tex1, Rect(0,0,2*semiwidth,2*semiheight)));
        }
    }
    // body
    PhysicsBody *body=PhysicsBody::create();
    body->setDynamic(false);
    body->setCategoryBitmask(cat_wall);
    body->setContactTestBitmask(cat_trash);
    body->setCollisionBitmask(cat_trash);
    
    // down
    PhysicsShape *s1;
    s1=PhysicsShapeEdgeSegment::create(Point(-(semiwidth-semiindent),-semiheight), Point(semiwidth-semiindent,-semiheight));
    s1->setContactTestBitmask(cat_trash);
    s1->setCategoryBitmask(cat_wall|cat_sensor);
    LOG_COLLISION("fondo cat %d",s1->getCategoryBitmask());
    body->addShape(s1);
    
    // left
    s1=PhysicsShapeEdgeSegment::create(Point(-semiwidth,semiheight-verticalindent), Point(-(semiwidth-semiindent),-semiheight));
    s1->setCategoryBitmask(cat_wall);
    LOG_COLLISION("otro cat %d",s1->getCategoryBitmask());
    body->addShape(s1);
    // right
    s1=PhysicsShapeEdgeSegment::create(Point(semiwidth,semiheight-verticalindent), Point(semiwidth-semiindent,-semiheight));
    s1->setCategoryBitmask(cat_wall);
    LOG_COLLISION("otro cat %d",s1->getCategoryBitmask());
    body->addShape(s1);

    if (p_trash_category==Trash::CAT_CRISTAL) {
        s1=PhysicsShapeEdgeSegment::create(Point(semiwidth,semiheight-verticalindent),Point(semiwidth-verticalindent,semiheight));
        body->addShape(s1);
        s1->setCategoryBitmask(cat_wall);
        s1=PhysicsShapeEdgeSegment::create(Point(-(semiwidth-verticalindent),semiheight),Point(semiwidth-verticalindent,semiheight));
        s1->setCategoryBitmask(cat_wall);
        body->addShape(s1);
    }
    
    this->setPhysicsBody(body);
    
    over_sprite=NULL;
    if (p_trash_category==Trash::CAT_CRISTAL) {
        over_sprite=Sprite::createWithSpriteFrameName("Contenedores/Contenedor0005.png");
        if (Options::debug_draw_alfa) over_sprite->setOpacity(100);
    }
    
    if (Options::debug_draw_alfa) this->setOpacity(100);
    
    return true;
}

Container* Container::create(int p_trash_category)
{
    Container *pRet;
    if ( !Options::debug_draw_spritesquare ) {
        char ccbifilename[50];
        sprintf(ccbifilename, "Contenedor%d",p_trash_category*0+1);
        pRet=SceneLoadManager::getInstance()->containerFromFile(ccbifilename);
    } else {
        pRet=Container::create();
    }
    pRet->init(p_trash_category);
    return pRet;
}


void Container::setAnimationManager(cocosbuilder::CCBAnimationManager *p_animation_manager)
{
    animation_manager=p_animation_manager;
    animation_manager->retain();
}


void Container::add_to_layer(cocos2d::Layer *alayer)
{
    if (over_sprite) {
        over_sprite->setPosition(this->getPosition());
        alayer->addChild(over_sprite,30);
        alayer->addChild(this,10);
    } else {
        alayer->addChild(this,40);
    }
}

void Container::destroy(Trash *atrash)
{
    LOG_COLLISION("trash destroyed [c %d t %d]",atrash->trash_category,atrash->trash_type);
    if ( trash_category == atrash->trash_category ) {
        LOG_COLLISION("container MATCH");
        Game::thegame->trash_recycled(trash_category);
    } else {
        LOG_COLLISION("container FAILED");
        Game::thegame->trash_failed(atrash->trash_category);
    }
    
    if (!Options::debug_draw_spritesquare){
    if (rand()%2==0) {
        animation_manager->runAnimationsForSequenceNamed("Baja");
    } else {
        animation_manager->runAnimationsForSequenceNamed("Sube");    
    }}
    
}



