//
//  TrashGenerator.cpp
//  Rcycle
//
//  Created by Mikel on 12/03/14.
//
//

#include "TrashGenerator.h"


bool TrashGenerator::initWithScene(GameScene *pScene)
{
    theScene = pScene;
    
    return true;
}



void TrashGenerator::start()
{
    
    
}

void TrashGenerator::stop()
{
    
    
}


void TrashGenerator::generateRandomTrash()
{
    Trash *tr;
    tr = Trash::create(0, 0);
    
}



TrashGenerator* TrashGenerator::createWithScene(GameScene *pScene)
{
    TrashGenerator *gen = new TrashGenerator();
    if (gen && gen->initWithScene(pScene)) {
        gen->autorelease();
        return gen;
    } else {
        delete gen;
        gen=NULL;
        return NULL;
    }
}
