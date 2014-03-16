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

class TrashGenerator : public cocos2d::Object
{
public:
    bool initWithScene(GameScene *pScene);
    static TrashGenerator* createWithScene(GameScene *pScene);

    void start();
    void stop();
    void generateRandomTrash();
    
    GameScene *theScene;
    
};





#endif /* defined(__Rcycle__TrashGenerator__) */
