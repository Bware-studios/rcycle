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
//int game_score_recycled[] = { 10,10,10,10 };
//int game_score_failed[] = { -5,-5,-5,-5 };
//int game_score_out[] = { -1,-1,-1,-1 };
int game_score_recycled[] = { 1,1,1,1 };
int game_score_failed[] = { 0,0,0,0 };
int game_score_out[] = { 0,0,0,0 };


int game_score_needed_for_level[] = {50,100,150,200,250,300};
int game_score_needed_for_level_size = 5;

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
    wave_n_fails=0;
    total_score=0;
    return true;
}

void Game::setScene(GameScene *scene)
{
    thescene=scene;
}


void Game::trash_recycled(int category)
{
    if (wave_n_fails >= Options::num_fails_to_end) return;
        
    int cat_safe=category%Trash::num_trash_cat;
    wave_recycled[cat_safe]+=1;
    update_partial_score();
   // GameScene::thegamescene->set_recycled(cat_safe, wave_recycled[cat_safe]);
}


void Game::trash_failed(int category)
{
    if (wave_n_fails >= Options::num_fails_to_end) return;

    sound_play_effect(sound_botella2);
    
    int cat_safe=category%Trash::num_trash_cat;
    wave_failed[cat_safe]+=1;
    update_partial_score();
    one_wave_fail();
}


void Game::trash_out(int category)
{
    if (wave_n_fails >= Options::num_fails_to_end) return;

    int cat_safe=category%Trash::num_trash_cat;
    wave_out[cat_safe]+=1;
    update_partial_score();
    one_wave_fail();
}

void Game::one_wave_fail()
{
    wave_n_fails+=1;
    thescene->update_score_fails(wave_n_fails);
    LOG_SCORE("%d fails !!!!!!",wave_n_fails);
    if (wave_n_fails >= Options::num_fails_to_end) {
        thescene->game_has_ended_by_fails();
    }
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
        if (Options::easy_game_for_debug) {
            score+=-1*failed[i];
            score+=-1*outs[i];
        } else {
            score+=game_score_failed[i]*failed[i];
            score+=game_score_out[i]*outs[i];
        }
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
    int levelpos=level-1;
    if (levelpos>=game_score_needed_for_level_size) {
        levelpos=game_score_needed_for_level_size-1;
    }
    int scoretarget = game_score_needed_for_level[levelpos];
    if ( Options::easy_game_for_debug) {
        scoretarget/=10;
    }
    return scoretarget;
}

int Game::get_current_wave()
{
    return wave_completed;
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
    if ( wave_n_fails < Options::num_fails_to_end  /*wave_score >= score_target */ ) {
        wave_passed=true;
        wave_completed+=1;

        //score_target=score_topass_level(wave_completed+1);
        partial_score=0;

    } else {
        wave_passed=false;
//        if (Scores::getInstance()->would_achieve_high_score(total_score)) {
//            high_score_achieved=true;
//        }
     //   Scores::getInstance()->save_score_if("xxxxx", total_score);
    }
    if (!Options::fails_persist) {
        wave_n_fails=0;
    } else if (Options::one_fail_bonus_per_level) {
        wave_n_fails-=1;
        wave_n_fails=(wave_n_fails<0)?0:wave_n_fails;
    }
    
}

int Game::get_last_wave_score()
{
    return wave_score;
}

int Game::get_last_wave_reached()
{
    return wave_completed;
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



