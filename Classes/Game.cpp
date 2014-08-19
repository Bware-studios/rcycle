//
//  Game.cpp
//  Rcycle
//
//  Created by Mikel on 11/02/14.
//
//

#include "Game.h"

// puntos por cada tipo ok o failed
int game_score_recycled[] = { 10,10,10,10 };
int game_score_failed[] = { -10,-10,-10,-10};


Game *Game::thegame=NULL;

bool Game::init()
{
    Game::thegame=this;
    Game::thegame->retain();
    
    wave_recycled=new int[Trash::num_trash_cat];
    wave_failed=new int[Trash::num_trash_cat];
    wave_out=new int[Trash::num_trash_cat];
    total_recycled=new int[Trash::num_trash_cat];
    total_failed=new int[Trash::num_trash_cat];
    total_out=new int[Trash::num_trash_cat];
    int i;
    for (i=0; i<Trash::num_trash_cat; i++) {
        wave_recycled[i]=0;
        wave_failed[i]=0;
        wave_out[i]=0;
        total_recycled[i]=0;
        total_failed[i]=0;
        total_out[i]=0;
    }
    
    wave_score=0;
    total_score=0;
    return true;
}


void Game::trash_recycled(int category)
{
    int cat_safe=category%Trash::num_trash_cat;
    wave_recycled[cat_safe]+=1;
   // GameScene::thegamescene->set_recycled(cat_safe, wave_recycled[cat_safe]);
}


void Game::trash_failed(int category)
{
    int cat_safe=category%Trash::num_trash_cat;
    wave_failed[cat_safe]+=1;
}


void Game::trash_out(int category)
{
    int cat_safe=category%Trash::num_trash_cat;
    wave_out[cat_safe]+=1;
}


int Game::score(int *ok,int *failed) {
    int score=0;
    int i;
    for (i=0;i<Trash::num_trash_cat;i++) {
        score+=game_score_recycled[i]*wave_recycled[i];
        score+=game_score_failed[i]*wave_failed[i];
    }
    return score;
}

void Game::wave_end()
{
    int i;
    wave_score=score(wave_recycled, wave_failed);
    total_score+=wave_score;
    for (i=0; i<Trash::num_trash_cat; i++) {
        total_recycled[i]+=wave_recycled[i];
        total_failed[i]+=wave_failed[i];
        total_out[i]+=wave_out[i];
        wave_recycled[i]=0;
        wave_failed[i]=0;
        wave_out[i]=0;
    }
    
}

