//
//  TrashGenerator.h
//  Rcycle
//
//  Created by Mikel on 12/03/14.
//
//

#ifndef __Rcycle__TrashGenerator__
#define __Rcycle__TrashGenerator__

#include "Common.h"
#include "Trash.h"
#include "GameScene.h"

class GameScene;

class TrashGenerator : public cocos2d::Ref
{
public:
    bool initWithScene(GameScene *pScene);
    static TrashGenerator* createWithScene(GameScene *pScene);

    void startforlevel(int l);
    void stop();
    void wait_time();
    void time_passes();
    void generate();
    int randomCategory();
    int randomType(int category);
    cocos2d::Point randomThrowingTarget(cocos2d::Point &start);
    cocos2d::Point randomThrowingStart();
    void generateRandomTrash();
    bool calculateVelocityToTarget(cocos2d::Vect &v,const cocos2d::Point &start,const float htop,const cocos2d::Point &target);

private:
    GameScene *theScene;
    bool running;
    
    int level;
    
    float lambda ;
    float p2 ;
    
    bool first_boost;
};





#endif /* defined(__Rcycle__TrashGenerator__) */
