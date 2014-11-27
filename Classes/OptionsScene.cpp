//
//  OptionsScene.cpp
//  Rcycle
//
//  Created by Mikel on 10/11/13.
//
//

#include "OptionsScene.h"

USING_NS_CC;
USING_NS_CC_EXT;

using namespace std;
using namespace cocosbuilder;

bool OptionsScene::init() {
    if ( ! MenuScene::init("OptionsScene") ) return false;

    
    auto *l1=Label::create("prueba", "Marker Felt", 23);
    MenuItemLabel *m1=MenuItemLabel::create(l1,CC_CALLBACK_1(OptionsScene::selected_prueba, this));
    m1->setPosition(Point(0,0));
    m1->setColor(Color3B(0, 0, 0));
    menu->addChild(m1);
    
    MenuItemLabel *m_t_1,*m_t_2;
    MenuItemToggle *mtog;
    
    m_t_1=MenuItemLabel::create(Label::create("trash collision: on", "Marker Felt", 23),CC_CALLBACK_1(OptionsScene::selected_no_trash_collision,this));
    m_t_2=MenuItemLabel::create(Label::create("trash collision: off", "Marker Felt", 23),CC_CALLBACK_1(OptionsScene::selected_trash_collision,this));
    m_t_1->setColor(Color3B(0, 0, 0));
    m_t_2->setColor(Color3B(0, 0, 0));
    mtog=MenuItemToggle::createWithCallback(CC_CALLBACK_1(OptionsScene::selected_tog, this),m_t_1,m_t_2, NULL);
    
    mtog->setPosition(Point(0,30));
    menu->addChild(mtog);

    
    MenuItemLabel *mback=MenuItemLabel::create(Label::create("back to menu", "Marker Felt", 23),CC_CALLBACK_1(OptionsScene::back, this));
    mback->setPosition(Point(0,-50));
    mback->setColor(Color3B(0, 0, 0));
    menu->addChild(mback);

    
    
    return true;
}





void OptionsScene::enter(Ref *pSender)
{
    LOG("option1");
}


void OptionsScene::back(Ref *pSender)
{
    auto newscene = MainMenuScene::create();
    Director::getInstance()->replaceScene(newscene);
}




void OptionsScene::selected_prueba(Ref *pSender)
{
    cout << "prueba clicked\n";
}

void OptionsScene::selected_tog(Ref *pSender)
{
    cout << "tog clicked\n";
}

void OptionsScene::selected_tog1(Ref *pSender)
{
    cout << "tog1 clicked\n";
}

void OptionsScene::selected_tog2(Ref *pSender)
{
    cout << "tog2 clicked\n";
}

void OptionsScene::selected_trash_collision(Ref *pSender)
{
    cout << "trash col clicked\n";
    Options::physics_intertrash_collision=true;
}

void OptionsScene::selected_no_trash_collision(Ref *pSender)
{
    cout << "trash no col clicked\n";
    Options::physics_intertrash_collision=false;
}



