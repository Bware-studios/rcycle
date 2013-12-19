//
//  Container.h
//  Rcycle
//
//  Created by Mikel on 13/12/13.
//
//

#ifndef __Rcycle__Container__
#define __Rcycle__Container__

#include <iostream>
#include <cocos2d.h>
#include "GameObject.h"


class Container : public GameObject
{
public:
    bool init(int p_trash_category);
    static Container* create(int p_trash_category);
    
    int trash_category;
    
private:
    int semiheight;
    int semiwidth;
    int semiindent;
    int verticalindent;

};

#endif /* defined(__Rcycle__Container__) */
