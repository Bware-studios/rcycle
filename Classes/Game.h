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

class GameScene;

class Game : public cocos2d::Ref
{
public:
    bool init();
    CREATE_FUNC(Game);
    
    void setScene(GameScene *scene);
    
    static Game *thegame;
    
    void trash_recycled(int category);
    void trash_failed(int category);
    void trash_out(int category);
    void one_wave_fail();
    void update_partial_score();

    int unbound_score(int *ok,int *failed,int *outs);
    int score(int *ok,int *failed,int *outs);
    int score_topass_level(int level);
    
    void wave_end();

    int get_last_wave_score();
    int get_total_score();
    int get_last_wave_recycled(int cat);
    int get_last_wave_failed(int cat);
    int get_last_wave_passed();
    bool get_high_score_achieved();

    // scene to notify
    GameScene *thescene;
    
    // stats
    int *wave_recycled;
    int *wave_failed;
    int *wave_out;
    
    int *total_recycled;
    int *total_failed;
    int *total_out;

    int wave_n_fails = 0;
    
    int wave_score = 0;
    int partial_score = 0;
    int total_score = 0;
    int wave_completed = 0;
    bool wave_passed = false;
    
    int score_target;
    
    bool high_score_achieved = false;
    
};


#endif /* defined(__Rcycle__Game__) */
