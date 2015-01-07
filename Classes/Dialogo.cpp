//
//  Dialogo.cpp
//  Rcycle
//
//  Created by Mikel on 2/1/15.
//
//

#include "Dialogo.h"

USING_NS_CC;

bool Dialogo::init()
{
    Layer::init();
    LayerColor *back;
    back=LayerColor::create(Color4B(100,100,100,255), 200, 150);
    addChild(back);
    
    printf("dialogo.. init...\n");
    return true;
}


