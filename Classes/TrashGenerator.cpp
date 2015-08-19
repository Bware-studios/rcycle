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
    level=0;
    int t0=std::time(NULL);
    srand(t0);
    return true;
}



void TrashGenerator::startforlevel(int l)
{
    level=l;
    running=true;
    
    first_boost=false;
    lambda= Options::lambda0 + l*Options::lambdam ;
    p2= Options::p20 + l*Options::p2m ;

    printf("trash generator intiated for wave: %d  lambda=%f  p2=%.4f\n",l,lambda,p2);
    time_passes();
}

void TrashGenerator::stop()
{
    running=false;
}

void TrashGenerator::wait_time()
{
    float t;
    if (Options::randomtime) {
        float u = rand()*1.0/RAND_MAX;
        t=log(u)*1.0/-lambda;
        t=(t>Options::rnd_tmax)?Options::rnd_tmax:t;
        t=(t<Options::rnd_tmin)?Options::rnd_tmin:t;
//        printf("u=%f lambda=%f t=%f\n",u,lambda,t);
    } else {
        t=1.0/lambda;
    }

    
    theScene->runAction(Sequence::createWithTwoActions(DelayTime::create(t),CallFunc::create(CC_CALLBACK_0(TrashGenerator::time_passes, this))));
}

void TrashGenerator::time_passes()
{
    if (!running) return;

    if (!first_boost && Options::first_boost) {
        if (GameScene::thegamescene->getGameTime()>Options::first_boost_time) {
            printf("boooost\n");
            first_boost=true;
            lambda+=Options::first_boost_lambda;
        }
    }
    
    generate();
    wait_time();
}

void TrashGenerator::generate()
{
    //printf("generate ...");
    float u = rand()*1.0/RAND_MAX;
    if (u<p2) {
        generateRandomTrash(-1);
        generateRandomTrash(1);
        //printf("double");
        
    } else {
    //printf("\n");
        generateRandomTrash(0);
    }
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
        x=200+20*(rand()%10) -240;
    } else {
        x=150+20*(rand()%3) -240;
    }
    return Point(x,y);
}

Point TrashGenerator::randomThrowingStart(int side)
{
    float xleft = -40 -240;
    float xright = 520 +50 -240;
    float x,y;

    x=xleft;
    if (side>0) { x=xright; }
    if (side==0) {
        if (rand()%4==0) x=xright;
    }
    
    y=200;
    return Point(x,y);
}


//side -1 izquierda 1 derecha 0 random
void TrashGenerator::generateRandomTrash(int side)
{
    int rcat,rtype;
    Point ps,pe;
    rcat=randomCategory();
    rtype=randomType(rcat);
    ps=randomThrowingStart(side);
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
