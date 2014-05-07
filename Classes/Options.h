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
    
};


#endif /* defined(__rcycle__Options__) */
