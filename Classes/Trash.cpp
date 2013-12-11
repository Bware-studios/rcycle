//
//  Trash.cpp
//  Rcycle
//
//  Created by Mikel on 10/12/13.
//
//

#include "Trash.h"



bool Trash::init()
{
    return init(0,0);
}


bool Trash::init(int p_trash_type, int p_trash_category)
{
    trash_type=p_trash_type;
    trash_category=p_trash_category;
    return true;
}


Trash* Trash::create(int trash_type, int trash_category)
{
    Trash *pRet = new Trash();
    if (pRet && pRet->init())
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

