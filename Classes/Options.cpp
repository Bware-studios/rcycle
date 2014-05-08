//
//  Options.cpp
//  rcycle
//
//  Created by Mikel on 08/02/14.
//
//

#include "Options.h"



bool Options::debug_draw_physics = true;
bool Options::debug_draw_alfa = true;
bool Options::debug_draw_background = false;
bool Options::debug_draw_outside = false;
float Options::debug_draw_outside_scale = 0.5;
bool Options::debug_draw_spritesquare = false;

// g en pixeles/s^2
float Options::physics_g = 100.0;
bool Options::physics_intertrash_collision = true;
