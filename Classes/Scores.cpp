//
//  Scores.cpp
//  Rcycle
//
//  Created by Mikel on 31/8/14.
//
//

#include "Scores.h"

#include <sys/stat.h>
#include "JSONcodec.h"
#include "Game.h"


USING_NS_CC;
using namespace std;


const char *rcycler_dir_name="rcycler";
const char *score_file_name="scoreData_file.json";

const int Scores::num_local_scores = 10;


Scores *Scores::thescores = NULL;

Scores *Scores::getInstance()
{
    if (thescores==NULL) {
        Scores::create();
    }
    return thescores;
}


bool Scores::init() {
    Scores::thescores=this;
    Scores::thescores->retain();
    
    high_scores = new struct scoreitem[num_local_scores];
    
    LOG_SCORE("init called");

    stringstream full_dir_name;
    full_dir_name << FileUtils::getInstance()->getWritablePath().c_str() << "/" << rcycler_dir_name << "/";
    mkdir(full_dir_name.str().c_str(),0777);
    full_file_name = full_dir_name.str()+string(score_file_name);
    LOG_SCORE("scores full filename: %s",full_file_name.c_str());

//    Value xx=read_json_file(full_file_name);
//    printf("%s\n",write_json_str(&xx).c_str());
    
    // recupera estado de fichero
    //scoreData = FileUtils::getInstance()->getValueMapFromFile(full_file_name.c_str());
    bool scores_dict_loadable = false;

    Value json_value_loaded = read_json_file(full_file_name);
    if ( json_value_loaded.getType()!=Value::Type::MAP ) {
        LOG_SCORE("error not dictionary found");
        scores_dict_loadable=false;
    } else {
        scoreData = json_value_loaded.asValueMap();
        if ( scoreData.count("v") ) {
            int dict_version=scoreData.at(string("v")).asInt();
            LOG_SCORE("V present v= %d",dict_version);
            if (dict_version==1) {
                LOG_SCORE("loading version 1");
                scores_dict_loadable=true;
            }
        }
    }
    
    if (scores_dict_loadable) {
        if (scoreData.count("name")) {
            player_name=scoreData.at("name").asString();
        }
        
        // cargar scores
        for (int i=0;i<num_local_scores;i++) {
            stringstream i_s;
            i_s<<i;
            Value scoreitem = scoreData.at("scores").asValueMap().at(i_s.str().c_str());
            if (scoreitem.getType()==Value::Type::MAP) {
                ValueMap scoreitemmap = scoreitem.asValueMap();
                high_scores[i].name=scoreitemmap.at("name").asString();
                high_scores[i].score=scoreitemmap.at("score").asInt();
            }
        }
    } else {
        int i;
        for (i=0;i<num_local_scores;i++) {
            //high_scores[i].name=scoreData["scores"][i];
            stringstream n1;
            n1<< "Mikel" << (i+1);
            high_scores[i].name=n1.str();
            high_scores[i].score=100*(12-i);
        }
    }
    
        
    // normalmente no lo grabarias aqui solo para probar
  //  save_file();
    
    

    return true;
}

void Scores::set_player_name(std::string name)
{
    player_name=name;
}

std::string Scores::get_player_name()
{
    return player_name;
}


void Scores::save_file()
{
    // set version to save
    scoreData["v"]=Value(1);

    if (!player_name.empty()) {
        scoreData["name"]=Value(player_name);
    }
    
//    ValueMapIntKey scores=*new ValueMapIntKey;
    ValueMap scores=*new ValueMap;
    int i;
    for (i=0;i<num_local_scores;i++) {
        ValueMap item=*new ValueMap;
        item["name"]=high_scores[i].name;
        item["score"]=high_scores[i].score;
        char ns[10];
        sprintf(ns,"%d",i);
        scores[ns]=item;
    }
    scoreData["scores"]=scores;
    
    //printf("4: %d   %s %d \n",scores.count(4),scores[4].asValueMap()["name"].asString().c_str(),scores[4].asValueMap()["score"].asInt());
    Value raiz=Value(scoreData);
    write_json_file(&raiz, full_file_name);
}


bool Scores::save_score()
{
    player_name=Scores::getInstance()->get_player_name();
    int ascore=Game::thegame->get_total_score();
    bool high_score=false;
    int mypos=num_local_scores;
    while (mypos>0 && high_scores[mypos-1].score<ascore) {
        mypos-=1;
        if (mypos<num_local_scores-1) {
            high_scores[mypos+1].name=high_scores[mypos].name;
            high_scores[mypos+1].score=high_scores[mypos].score;
        }
        if (mypos<num_local_scores) {
            high_scores[mypos].name=player_name.c_str();
            high_scores[mypos].score=ascore;
            // entrado en la lista
            high_score=true;
        }
    }
    
    save_file();
    return high_score;
}



bool Scores::would_achieve_high_score(int ascore)
{
    if (ascore>high_scores[num_local_scores-1].score) {
        return true;
    }
    return false;
}


