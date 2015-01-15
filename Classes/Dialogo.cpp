//
//  Dialogo.cpp
//  Rcycle
//
//  Created by Mikel on 2/1/15.
//
//

#include "Dialogo.h"


const char *dialogo_font_name="Marker Felt";
const int dialogo_font_size=24;

USING_NS_CC;

bool Dialogo::init()
{
    Layer::init();
    
    printf("dialogo.. init...\n");
    return true;
}


void Dialogo::setContainer(cocos2d::Node *p)
{
    assert(p!=NULL);
    parent=p;
}


void Dialogo::setMainText(std::string text)
{
    maintext=text;
}

void Dialogo::setTextPlaceholder(std::string text)
{
    placeholder=text;
}

void Dialogo::setMainButtonName(std::string text)
{
    mainbutton=text;
}

void Dialogo::setSecondButtonName(std::string text)
{
    secondbutton=text;
}

void Dialogo::setButtonResponseListener(std::function<void(Dialogo*,int)> callback)
{
    finish_callback_buttons_listener=callback;
}

void Dialogo::setTextResponseListener(std::function<void(Dialogo*,int,std::string)> callback)
{
    finish_callback_text_listener=callback;
    showtextfield=true;
}



void Dialogo::enter()
{
    Size s=Director::getInstance()->getOpenGLView()->getDesignResolutionSize();
    //ignoreAnchorPointForPosition(false);
    //setAnchorPoint(Point(0,0));
    //setPosition(Point(0,0));
    
//    LayerColor *hide;
//    hide=LayerColor::create(Color4B(250,150,150,10), s.width,s.height );
//    hide->setAnchorPoint(Point(0.5,0.5));
//    hide->ignoreAnchorPointForPosition(false);
//    hide->setPosition(Point(0,0));
//    addChild(hide,10);
    
    LayerColor *back;
    back=LayerColor::create(Color4B(100,100,200,200), s.width*.9,s.height*.9 );
    back->setAnchorPoint(Point(0.5,0.5));
    back->ignoreAnchorPointForPosition(false);
    back->setPosition(Point(0,0));
    addChild(back,20);
    
    Label *l1 = Label::create(maintext, dialogo_font_name, dialogo_font_size);
    l1->setPosition(Point(0,s.height*0.25));
    if (showtextfield) l1->setPosition(Point(0,s.height*0.35));
    l1->setAlignment(TextHAlignment::CENTER);
    addChild(l1,30);

    
    Menu *m1 = Menu::create();
    m1->setPosition(Point(0,-s.height*.25));
    
    Label *lm1=Label::create(mainbutton,dialogo_font_name, dialogo_font_size);
    MenuItemLabel *mi1=MenuItemLabel::create(lm1,CC_CALLBACK_1(Dialogo::event_mainbutton,this));
    mi1->setPosition(Point(100,0));
    addChild(m1,30);

    m1->addChild(mi1);
    
    if ( ! secondbutton.empty() ) {
        MenuItemLabel *mi2=MenuItemLabel::create(Label::create(secondbutton,dialogo_font_name, dialogo_font_size),CC_CALLBACK_1(Dialogo::event_secondbutton,this));
        mi2->setPosition(Point(-100,0));
        m1->addChild(mi2);
    }
    
    
    if (showtextfield) {
        LayerColor *tfback;
        tfback=LayerColor::create(Color4B(255,255,255,255), s.width*.7,s.height*.15 );
        tfback->setAnchorPoint(Point(0.5,0.5));
        tfback->ignoreAnchorPointForPosition(false);
        tfback->setPosition(Point(0,s.height*.20));
        addChild(tfback,25);

        field=cocos2d::ui::TextField::create();
        field->setPosition(Point(0,s.height*.20));
        field->setAnchorPoint(Point(0.5,0.5));
        field->setMaxLength(26);
        
        field->setPlaceHolder(placeholder);
        field->setColor(Color3B(255,0,0));
        
//        field->addEventListenerTextField(this,textfieldeventselector(StatsScene::text_field_event));
        
        field->setFocused(true);
        
        this->addChild(field,35);


        
    }
    
    
    
    
//    auto ap=this->getAnchorPoint();
//    auto pap=parent->getAnchorPoint();
//    std::cout<<"anchor: "<<ap.x <<","<<ap.y<<"\n";
//    std::cout<<"p anchor: "<<pap.x <<","<<pap.y<<"\n";


    setPosition(Point(s.width/2,s.height/2));
    parent->addChild(this);
    field->attachWithIME();



    EventListenerTouchOneByOne *tl = EventListenerTouchOneByOne::create();
    tl->setSwallowTouches(true);
    tl->onTouchBegan=CC_CALLBACK_2(Dialogo::event_touchbegan, this);
    tl->onTouchEnded=CC_CALLBACK_2(Dialogo::event_touchended, this);
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(tl,this);

}

void Dialogo::dismiss()
{
    removeFromParent();
}



void Dialogo::event_mainbutton(cocos2d::Ref* psender)
{
    printf("but1\n");
    if (finish_callback_buttons_listener) {
        finish_callback_buttons_listener(this,1);
    }
    if (showtextfield && finish_callback_text_listener) {
        finish_callback_text_listener(this,1,field->getStringValue());
    }
    dismiss();
}

void Dialogo::event_secondbutton(cocos2d::Ref* psender)
{
    printf("but2\n");
    if (finish_callback_buttons_listener) {
        finish_callback_buttons_listener(this,2);
    }
    if (showtextfield && finish_callback_text_listener) {
        finish_callback_text_listener(this,2,field->getStringValue());
    }
    dismiss();
}


bool Dialogo::event_touchbegan(cocos2d::Touch* touch,cocos2d::Event *e)
{
    return true;
}

void Dialogo::event_touchended(cocos2d::Touch* touch,cocos2d::Event *e)
{
}





void Dialogo::info_dialog(std::string text,std::string b1,std::function<void(Dialogo*,int)> callback)
{
    Scene *s=Director::getInstance()->getRunningScene();
    Dialogo *d1 = Dialogo::create();
    d1->setContainer(s);
    d1->setMainText(text);
    d1->setMainButtonName(b1);
    d1->setButtonResponseListener(callback);
    d1->enter();
    
}

void Dialogo::question_dialog(std::string text,std::string placeholder,std::string b1,std::function<void(Dialogo*,int,std::string)> callback)
{
    Scene *s=Director::getInstance()->getRunningScene();
    Dialogo *d1 = Dialogo::create();
    d1->setContainer(s);
    d1->setMainText(text);
    d1->setTextPlaceholder(placeholder);
    d1->setMainButtonName(b1);
    d1->setTextResponseListener(callback);
    d1->enter();
    
}

void Dialogo::yes_no_dialog(std::string text,std::string b1,std::string b2,std::function<void(Dialogo*,int)> callback)
{
    Scene *s=Director::getInstance()->getRunningScene();
    Dialogo *d1 = Dialogo::create();
    d1->setContainer(s);
    d1->setMainText(text);
    d1->setMainButtonName(b1);
    d1->setSecondButtonName(b2);
    d1->setButtonResponseListener(callback);
    d1->enter();
    
}




void Dialogo::try_a_dialog()
{
    Scene *s=Director::getInstance()->getRunningScene();
    Dialogo *d1 = Dialogo::create();
    d1->setContainer(s);
    d1->enter();
    
}



