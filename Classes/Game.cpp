//
//  Game.cpp
//  Rcycle
//
//  Created by Mikel on 11/02/14.
//
//

#include "Game.h"
#include "Scores.h"

// puntos por cada tipo ok o failed
int game_score_recycled[] = { 10,10,10,10 };
int game_score_failed[] = { -1,-1,-1,-1 };
int game_score_out[] = { 0,0,0,0 };


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
    
    score_target=score_topass_level(wave_completed+1);
    wave_passed=false;
    wave_score=0;
    partial_score=0;
    total_score=0;
    return true;
}


void Game::trash_recycled(int category)
{
    int cat_safe=category%Trash::num_trash_cat;
    wave_recycled[cat_safe]+=1;
    update_partial_score();
   // GameScene::thegamescene->set_recycled(cat_safe, wave_recycled[cat_safe]);
}


void Game::trash_failed(int category)
{
    int cat_safe=category%Trash::num_trash_cat;
    wave_failed[cat_safe]+=1;
    update_partial_score();
}


void Game::trash_out(int category)
{
    int cat_safe=category%Trash::num_trash_cat;
    wave_out[cat_safe]+=1;
    update_partial_score();
}

void Game::update_partial_score()
{
    partial_score=unbound_score(wave_recycled, wave_failed, wave_out);
    // cambia el dibujo ?
    GameScene::thegamescene->update_score_display();
}

int Game::unbound_score(int *ok,int *failed,int *outs)
{
    int score=0;
    int i;
    for (i=0;i<Trash::num_trash_cat;i++) {
        score+=game_score_recycled[i]*ok[i];
        score+=game_score_failed[i]*failed[i];
        score+=game_score_out[i]*outs[i];
    }
    return score;
}

int Game::score(int *ok,int *failed,int *outs)
{
    int score=unbound_score(ok, failed, outs);
    if (score<0) score=0;
    return score;
}

int Game::score_topass_level(int level)
{
    return level*10;
}

void Game::wave_end()
{
    int i;
    wave_score=score(wave_recycled, wave_failed, wave_out);
    total_score+=wave_score;
    for (i=0; i<Trash::num_trash_cat; i++) {
        total_recycled[i]+=wave_recycled[i];
        total_failed[i]+=wave_failed[i];
        total_out[i]+=wave_out[i];
        wave_recycled[i]=0;
        wave_failed[i]=0;
        wave_out[i]=0;
    }
    if (wave_score >= score_target /*score_topass_level(wave_completed+1)*/ ) {
        wave_passed=true;
        wave_completed+=1;

        score_target=score_topass_level(wave_completed+1);
        partial_score=0;

    } else {
        wave_passed=false;
        if (Scores::getInstance()->would_achieve_high_score(total_score)) {
            high_score_achieved=true;
        }
     //   Scores::getInstance()->save_score_if("xxxxx", total_score);
    }
}

int Game::get_last_wave_score()
{
    return wave_score;
}

int Game::get_total_score()
{
    return total_score;
}

int Game::get_last_wave_recycled(int cat)
{
    return wave_recycled[cat];
}

int Game::get_last_wave_failed(int cat)
{
    return wave_failed[cat];
}

int Game::get_last_wave_passed()
{
    return wave_passed;
}

bool Game::get_high_score_achieved()
{
    return high_score_achieved;
}



