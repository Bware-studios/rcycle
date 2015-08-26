//
//  Options.cpp
//  rcycle
//
//  Created by Mikel on 08/02/14.
//
//

#include "Options.h"



bool Options::debug_draw_physics = false;
bool Options::debug_draw_alfa = false;
bool Options::debug_draw_background = true;
bool Options::debug_draw_outside = false;
float Options::debug_draw_outside_scale = 0.5;
bool Options::debug_draw_spritesquare = false;

// g en pixeles/s^2
float Options::physics_g = 100.0;
bool Options::physics_intertrash_collision = false;

// resolution
bool Options::resolution_mac_res_as_android = false;

// UI
int Options::autohelp_n_firsttimes_show = 5;
int Options::settings_button_show = false;
bool Options::quit_is_valid_end = false;
bool Options::container_show_score = false;

bool Options::online_scores = true;

// game
bool Options::easy_game_for_debug = false;
int Options::num_fails_to_end = 3;
bool Options::fails_persist = false;
bool Options::one_fail_bonus_per_level = false;

// generator
float Options::lambda0 = .8 ;
float Options::lambdam = .2 ;
float Options::rnd_tmax = 4.0;
float Options::rnd_tmin = .2;
float Options::p20 = .05 ;
float Options::p2m = .1 ;
bool Options::randomtime = false ;

bool Options::first_boost = true ;
float Options::first_boost_time = 20.0 ;
float Options::first_boost_lambda = .4 ;


