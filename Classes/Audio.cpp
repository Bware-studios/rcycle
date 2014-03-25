//
//  Audio.cpp
//  Rcycle
//
//  Created by Mikel on 24/03/14.
//
//

#include "Audio.h"

#include "SimpleAudioEngine.h"
using namespace CocosDenshion;


const char *game_theme_name="Music/Main_theme.mp3";
const char *menu_theme_name="Music/rc_menu.mp3";


const char *sound_botella1="Sounds/Botella01.wav";
const char *sound_botella2="Sounds/Botella02.wav";
const char *sound_botella3="Sounds/Botella03.wav";

const char *sound_slowmotionsong_name="chariots.mp3";

SimpleAudioEngine *audio_engine;

int song_id;
bool song_playing=false;


void sound_init() {
    audio_engine=SimpleAudioEngine::getInstance();
}


void sound_preload_all() {
    audio_engine->preloadEffect(game_theme_name);
    audio_engine->preloadEffect(menu_theme_name);
    //audio_engine->preloadEffect(sound_explosion_name);
}

void sound_play_effect(const char *name) {
    audio_engine->playEffect(name);
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

