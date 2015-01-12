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
    
    
    static void try_a_dialog();
    
private:
    cocos2d::Node *parent = NULL;
    std::string maintext = "Dialogo";
    
};

#endif /* defined(__Rcycle__Dialogo__) */
