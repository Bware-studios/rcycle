//
//  Options.h
//  rcycle
//
//  Created by Mikel on 08/02/14.
//
//

#ifndef __rcycle__Options__
#define __rcycle__Options__

#include "Common.h"



class Options {
public:
    // Debug options
    static bool debug_draw_physics;
    static bool debug_draw_alfa;
    static bool debug_draw_background;
    static bool debug_draw_outside;
    static float debug_draw_outside_scale;
    static bool debug_draw_spritesquare;
    
    // physics parameters
    static float physics_g;
    static bool physics_intertrash_collision;
    
    // resolution
    static bool resolution_mac_res_as_android;
    
    // UI
    static int autohelp_n_firsttimes_show;
    static int settings_button_show;
    static bool quit_is_valid_end;
    static bool container_show_score;
    
//    static bool online_scores;
    
    //game
    static bool easy_game_for_debug;
    static int num_fails_to_end;
    static bool fails_persist;
    static bool one_fail_bonus_per_level;
//    static bool one_fail
    //generator
    static float lambda0;
    static float lambdam;
    static float rnd_tmax;
    static float rnd_tmin;
    static float p20;
    static float p2m;
    static bool randomtime;
    static bool first_boost;
    static float first_boost_time;
    static float first_boost_lambda;
};


#endif /* defined(__rcycle__Options__) */
