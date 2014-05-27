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
    running=true;
    time_passes();
}

void TrashGenerator::stop()
{
    running=false;
}

void TrashGenerator::time_passes()
{
    if (!running) return;
    generateRandomTrash();
    theScene->runAction(Sequence::createWithTwoActions(DelayTime::create(1.0),CallFunc::create(CC_CALLBACK_0(TrashGenerator::time_passes, this))));
}

int TrashGenerator::randomCategory()
{
    return rand()%4;
}

int TrashGenerator::randomType(int category)
{
    if (category==Trash::CAT_ORGANICO) return rand()%4;
    return rand()%2;
}

Point TrashGenerator::randomThrowingTarget(Point &start)
{
    float x,y;
    y=10;
    if (start.x<100) {
        x=200+20*(rand()%10);
    } else {
        x=150+20*(rand()%3);
    }
    return Point(x,y);
}

Point TrashGenerator::randomThrowingStart()
{
    float x,y;
    x=-40;
    if (rand()%4==0) x=520;
    y=200;
    return Point(x,y);
}



void TrashGenerator::generateRandomTrash()
{
    int rcat,rtype;
    Point ps,pe;
    rcat=randomCategory();
    rtype=randomType(rcat);
    ps=randomThrowingStart();
    pe=randomThrowingTarget(ps);
    Vect v((ps.x<100?200:-200),50); // default velocity
    if (!calculateVelocityToTarget(v, ps, 280, pe)) {
        LOG_TRASHGEN("trayectory error");
    }
    theScene->add_trash(rtype, rcat, ps, v);
}

// Da la velocidad para alcanzar el objetivo en una parabola
//
bool TrashGenerator::calculateVelocityToTarget(Vect &v,const Point &start,const float htop,const Point &target)
{
    if (htop<start.y) return false;
    float g=Options::physics_g;
    float vy,vx;
    vy=sqrtf(2*g*(htop-start.y));
    vx=(target.x-start.x)/(vy/g + sqrtf(2*(htop-target.y)/g));
    v.x=vx;
    v.y=vy;
    return true;
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
