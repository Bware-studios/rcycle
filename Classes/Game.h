//
//  Game.h
//  Rcycle
//
//  Created by Mikel on 11/02/14.
//
//

#ifndef __Rcycle__Game__
#define __Rcycle__Game__

#include "Common.h"
#include "Trash.h"
#include "GameScene.h"

class Game : public cocos2d::Ref
{
public:
    bool init();
    CREATE_FUNC(Game);
    
    static Game *thegame;
    
    void trash_recycled(int category);
    void trash_failed(int category);
    void trash_out(int category);

    int score(int *ok,int *failed);

    void wave_end();
    
    
    // stats
    int *wave_recycled;
    int *wave_failed;
    int *wave_out;
    
    int *total_recycled;
    int *total_failed;
    int *total_out;

    int wave_score = 0;
    int total_score = 0;
    int wave_completed = 0;
    
};


#endif /* defined(__Rcycle__Game__) */
