//
//  Dialogo.h
//  Rcycle
//
//  Created by Mikel on 2/1/15.
//
//

#ifndef __Rcycle__Dialogo__
#define __Rcycle__Dialogo__

#include "Common.h"

#include "CocosGUI.h"

class Dialogo : public cocos2d::Layer
{
public:
    bool init();
    CREATE_FUNC(Dialogo);
    
    void setContainer(cocos2d::Node *p);
    void setMainText(std::string text);
    void setMainButtonName(std::string text);
    void setSecondButtonName(std::string text);
    
    //void setButtonResponseListener();
    void setTextResponseListener();
    
    void enter();
    void dismiss();
    
    void event_mainbutton(cocos2d::Ref* psender);
    void event_secondbutton(cocos2d::Ref* psender);

    bool event_touchbegan(cocos2d::Touch* touch,cocos2d::Event *e);
    void event_touchended(cocos2d::Touch* touch,cocos2d::Event *e);

    
    static void info_dialog(std::string text,std::string b1);
    static void question_dialog(std::string text,std::string b1);
    static void yes_no_dialog(std::string text,std::string b1,std::string b2);
    static void try_a_dialog();
    
private:
    cocos2d::Node *parent = NULL;
    std::string maintext = "Dialogo";
    std::string mainbutton = "OK";
    std::string secondbutton = "";
    
    cocos2d::ui::TextField *field = NULL;
    bool showtextfield = false;
    
};

#endif /* defined(__Rcycle__Dialogo__) */
