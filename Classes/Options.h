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
    
    //game
    static bool easy_game_for_debug;
};


#endif /* defined(__rcycle__Options__) */
