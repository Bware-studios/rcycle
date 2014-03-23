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

class TrashGenerator : public cocos2d::Object
{
public:
    bool initWithScene(GameScene *pScene);
    static TrashGenerator* createWithScene(GameScene *pScene);

    void start();
    void stop();
    void time_passes();
    int randomCategory();
    int randomType(int category);
    cocos2d::Point randomThrowingTarget(cocos2d::Point &start);
    cocos2d::Point randomThrowingStart();
    void generateRandomTrash();
    bool calculateVelocityToTarget(cocos2d::Vect &v,const cocos2d::Point &start,const float htop,const cocos2d::Point &target);

    GameScene *theScene;
    
};





#endif /* defined(__Rcycle__TrashGenerator__) */
