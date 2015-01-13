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


class Dialogo : public cocos2d::Layer
{
public:
    bool init();
    CREATE_FUNC(Dialogo);
    
    void setParent(cocos2d::Node *p);
    
    void enter();
    void dismiss();
    
    
    bool event_touchbegan(cocos2d::Touch* touch,cocos2d::Event *e);
    void event_touchended(cocos2d::Touch* touch,cocos2d::Event *e);

    
    static void try_a_dialog();
    
private:
    cocos2d::Node *parent = NULL;
    std::string maintext = "Dialogo";
    
};

#endif /* defined(__Rcycle__Dialogo__) */
