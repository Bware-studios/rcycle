//
//  TrashGenerator.cpp
//  Rcycle
//
//  Created by Mikel on 12/03/14.
//
//

#include "TrashGenerator.h"

USING_NS_CC;


bool TrashGenerator::initWithScene(GameScene *pScene)
{
    theScene = pScene;
    
    return true;
}



void TrashGenerator::start()
{
    time_passes();
}

void TrashGenerator::stop()
{
    
    
}

void TrashGenerator::time_passes()
{
    std::cout<<"tick\n";
    generateRandomTrash();
    theScene->runAction(Sequence::createWithTwoActions(DelayTime::create(1.0),CallFunc::create(CC_CALLBACK_0(TrashGenerator::time_passes, this))));
}

void TrashGenerator::generateRandomTrash()
{
    int r1,r2;
    float x,y;
    r1=rand()%2;
    r2=rand()%4;
    x=rand()%480;
    y=rand()%100+300;
    Point p(x,y);
    LOG_TRASHGEN("generated t:%d c:%d at (%.2f,%.2f)",r1,r2,x,y);
    theScene->add_trash(r1, r2, p);
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
