//
//  Audio.cpp
//  Rcycle
//
//  Created by Mikel on 24/03/14.
//
//

#include "Audio.h"

#include "Trash.h"

#include "SimpleAudioEngine.h"
using namespace CocosDenshion;


const char *game_theme_name="Music/Main_theme.mp3";
const char *menu_theme_name="Music/rc_menu.mp3";


const char *sound_botella1="Sounds/Botella01.wav";
const char *sound_botella2="Sounds/Botella02.wav";
const char *sound_botella3="Sounds/Botella03.wav";

const char *sound_carton1="Sounds/GolpCart01.wav";
const char *sound_carton2="Sounds/GolpCart02.wav";
const char *sound_carton3="Sounds/GolpCart03.wav";

const char *sound_cristal1="Sounds/GolpCris01.wav";
const char *sound_cristal2="Sounds/GolpCris02.wav";
const char *sound_cristal3="Sounds/GolpCris03.wav";
const char *sound_cristal4="Sounds/GolpCris04.wav";

const char *sound_papel1="Sounds/Papel01.wav";
const char *sound_papel2="Sounds/Papel02.wav";
const char *sound_papel3="Sounds/Papel03.wav";

const char *sound_plasticoligero1="Sounds/PlastLig01.wav";
const char *sound_plasticoligero2="Sounds/PlastLig02.wav";
const char *sound_plasticoligero3="Sounds/PlastLig03.wav";

const char *sound_plasticomedio1="Sounds/PlastMed01.wav";
const char *sound_plasticomedio2="Sounds/PlastMed02.wav";

const char *sound_lat1="Sounds/GolpLat01.wav";
const char *sound_lat2="Sounds/GolpLat02.wav";
const char *sound_lat3="Sounds/GolpLat03.wav";
const char *sound_lat4="Sounds/GolpLat04.wav";


const char *sound_group_botella[]={sound_botella1,sound_botella2,sound_botella3};
const char *sound_group_carton[]={sound_carton1,sound_carton2,sound_carton3};
const char *sound_group_cristal[]={sound_cristal1,sound_cristal2,sound_cristal3,sound_cristal4};
const char *sound_group_papel[]={sound_papel1,sound_papel2,sound_papel3};
const char *sound_group_plasticoligero[]={sound_plasticoligero1,sound_plasticoligero2,sound_plasticoligero3};
const char *sound_group_plasticomedio[]={sound_plasticomedio1,sound_plasticomedio2};
const char *sound_group_lat[]={sound_lat1,sound_lat2,sound_lat3,sound_lat4};

//const char ***sound_group=new char**[N_SOUND_GROUPS];
const int sound_n_groups=7;
const char **sound_group[]={sound_group_botella,sound_group_carton,sound_group_cristal,sound_group_papel,sound_group_plasticoligero,sound_group_plasticomedio,sound_group_lat};
const int sound_group_n[]={3,3,4,3,3,2,4};

const int id_sound_group_botella=0;
const int id_sound_group_carton=1;
const int id_sound_group_cristal=2;
const int id_sound_group_papel=3;
const int id_sound_group_plasticoligero=4;
const int id_sound_group_plasticomedio=5;
const int id_sound_group_lat=6;

// la fila tiene que tener Trash::max_trash_type_per_cat
const int sound_group_for_trash[] = {
    id_sound_group_cristal,id_sound_group_cristal,id_sound_group_cristal,id_sound_group_cristal,0,
    id_sound_group_plasticoligero,id_sound_group_plasticoligero,id_sound_group_plasticoligero,id_sound_group_plasticoligero,0,
    id_sound_group_lat,id_sound_group_lat,0,0,0,
    id_sound_group_papel,id_sound_group_papel,id_sound_group_papel,id_sound_group_papel,0
};



//const char *sound_slowmotionsong_name="chariots.mp3";


SimpleAudioEngine *audio_engine;

int song_id;
bool song_playing=false;


void sound_init() {
    audio_engine=SimpleAudioEngine::getInstance();
    sound_group[0]=sound_group_botella;

    
}


void sound_preload_all() {
    audio_engine->preloadEffect(game_theme_name);
    audio_engine->preloadEffect(menu_theme_name);
    //audio_engine->preloadEffect(sound_explosion_name);
    for (int i=0;i<sound_n_groups;i++) {
        for (int j=0;j<sound_group_n[i];j++) {
            audio_engine->preloadEffect(sound_group[i][j]);
        }
    }
    
}

void sound_play_effect(const char *name) {
    audio_engine->playEffect(name);
}

void sound_play_effect_from_group(int groupid) {
    int selected=rand()%sound_group_n[groupid];
    sound_play_effect(sound_group[groupid][selected]);
}


void sound_play_effect_from_trash(int cat, int type) {
    sound_play_effect_from_group(sound_group_for_trash[cat*Trash::max_trash_type_per_cat+type]);
}


void sound_play_music(const char *name) {
    if (song_playing) sound_stop_music();
    song_id=audio_engine->playEffect(name);
    song_playing=true;
}

void sound_stop_music() {
    if (song_playing) {
        audio_engine->stopEffect(song_id);
    }
    song_playing=false;
}

