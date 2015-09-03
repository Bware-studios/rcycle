//
//  Trash.cpp
//  Rcycle
//
//  Created by Mikel on 10/12/13.
//
//

#include "Trash.h"

#include "Audio.h"
#include "GameScene.h"


USING_NS_CC;


const int Trash::num_trash_cat=4;
const int Trash::max_trash_type_per_cat=5;
const char *Trash::trash_cat_names[]={"cristal","plastico","organico","papel"};
const int Trash::CAT_CRISTAL=0;
const int Trash::CAT_PLASTICO=1;
const int Trash::CAT_ORGANICO=2;
const int Trash::CAT_PAPEL=3;


Vector<Trash*> *Trash::trashes = new Vector<Trash*>(30);

//Trash::~Trash() {
//    trashes->eraseObject(this);
//}


bool Trash::init()
{
    return init(0,0);
}


bool Trash::init(int p_trash_type, int p_trash_category)
{
    GameObject::init();
    trash_type=p_trash_type;
    trash_category=p_trash_category;

    char img_name[50];
    sprintf(img_name,"trashs/basura_%s%d.png",trash_cat_names[trash_category],p_trash_type+1);
    
    this->setDisplayFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(img_name));
    PhysicsBody *body=PhysicsBody::createCircle(30,PhysicsMaterial(0,0.1,0.5));
    
    body->setCategoryBitmask(cat_trash);
    if (Options::physics_intertrash_collision) {
        body->setCollisionBitmask(cat_wall|cat_trash);
        body->setContactTestBitmask(cat_wall|cat_trash|cat_sensor);
    } else {
        body->setCollisionBitmask(cat_wall);
        body->setContactTestBitmask(cat_wall|cat_sensor);
    }
    
    this->setPhysicsBody(body);

    this->is_dragable=true;
    
    player_touching=false;

    // para probar las labels
//    Label *debug_label=Label::create("X","Marker Felt",30);
//    debug_label->setAlignment(TextHAlignment::CENTER);
//    debug_label->setVerticalAlignment(TextVAlignment::CENTER);
//    debug_label->setPosition(32,32);
//    debug_label->setColor(Color3B(255, 0, 0));
//    this->addChild(debug_label);
    
    float u = rand()*1.0/RAND_MAX;

    setRotation(u*360.0);
    
    return true;
}


Trash* Trash::create(int p_trash_type, int p_trash_category)
{
    Trash *pRet = new Trash();
    if (pRet && pRet->init(p_trash_type,p_trash_category))
    {
        pRet->autorelease();
        trashes->pushBack(pRet);
        return pRet;
    }
    else
    {
        delete pRet;
        pRet = NULL;
        return NULL;
    }
}



void Trash::add_to_layer(cocos2d::Layer *alayer)
{
    alayer->addChild(this,15);
}

void Trash::play_destroyed_sound()
{
    sound_play_effect_from_trash(trash_category, trash_type);
//    if (trash_category==Trash::CAT_CRISTAL) {
//        sound_play_effect_from_group(id_sound_group_botella);
//    } else if (trash_category==Trash::CAT_PLASTICO) {
//        sound_play_effect_from_group(id_sound_group_plasticoligero);
//    } else if (trash_category==Trash::CAT_ORGANICO) {
//    
//    } else if (trash_category==Trash::CAT_PAPEL) {
//        sound_play_effect_from_group(id_sound_group_carton);
//    }
}


void Trash::setPlayerTouch(bool t)
{
    player_touching=t;
}


void Trash::destroy() {
    if (player_touching) {
        GameScene::thegamescene->touch_destroy();
    }
    this->removeFromParent();
    trashes->eraseObject(this);
}

void Trash::delete_all_trashes() {
    Vector<Trash*>::reverse_iterator i = trashes->rbegin();
    Trash *atrash;
    while (i != trashes->rend()) {
        atrash=*i;
        atrash->destroy();
        i++;
    }
}

