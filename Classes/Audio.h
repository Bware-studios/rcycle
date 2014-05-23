//
//  Audio.h
//  Rcycle
//
//  Created by Mikel on 24/03/14.
//
//

#ifndef __Rcycle__Audio__
#define __Rcycle__Audio__

#include <iostream>


extern const char *game_theme_name;
extern const char *menu_theme_name;

extern const char *sound_botella1;
extern const char *sound_botella2;
extern const char *sound_botella3;



extern const int id_sound_group_botella;
extern const int id_sound_group_carton;
extern const int id_sound_group_cristal;
extern const int id_sound_group_papel;
extern const int id_sound_group_plasticoligero;
extern const int id_sound_group_plasticomedio;
extern const int id_sound_group_lat;


void sound_init();
void sound_preload_all();

void sound_play_effect(const char *name);
void sound_play_effect_from_group(int groupid);
void sound_play_effect_from_trash(int cat, int type);

void sound_play_music(const char *name);
void sound_stop_music();



#endif /* defined(__Rcycle__Audio__) */
