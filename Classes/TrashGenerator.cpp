//
//  TrashGenerator.cpp
//  Rcycle
//
//  Created by Mikel on 12/03/14.
//
//

#include "TrashGenerator.h"


bool TrashGenerator::init()
{

    return true;
}



void TrashGenerator::start()
{
    
    
}

void TrashGenerator::stop()
{
    
    
}



TrashGenerator* TrashGenerator::create(GameScene thescene)
{
    Container *pRet = new Container();
    if (pRet && pRet->init(p_trash_category))
    {
        pRet->autorelease();
        return pRet;
    }
    else
    {
        delete pRet;
        pRet = NULL;
        return NULL;
    }
}
