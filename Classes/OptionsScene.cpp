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
    menu->addChild(m1);
    
    MenuItemLabel *m_t_1=MenuItemLabel::create(Label::create("opcion1", "Marker Felt", 23),CC_CALLBACK_1(OptionsScene::selected_tog1,this));
    MenuItemLabel *m_t_2=MenuItemLabel::create(Label::create("dos", "Marker Felt", 23),CC_CALLBACK_1(OptionsScene::selected_tog2,this));
    MenuItemToggle *mtog=MenuItemToggle::createWithCallback(CC_CALLBACK_1(OptionsScene::selected_tog, this),m_t_1,m_t_2, NULL);
    
    mtog->setPosition(Point(0,30));
    menu->addChild(mtog);
    
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



