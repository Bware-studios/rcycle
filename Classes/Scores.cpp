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
#include "Net.h"
#include "Preferences.h"

#include <curl/curl.h>


USING_NS_CC;
using namespace std;


//const char *rcycler_dir_name="rcycler";
const char *score_file_name="scoreData_file.json";
const char *tosend_file_name="score_to_send_file.json";
const char *sending_file_name="score_sending_file.json";

const int Scores::num_local_scores = 10;


bool ScoreItem::init()
{
    name=string("");
    score=0;
    own=true;
    return true;
}

ScoreItem* ScoreItem::create(const char *pname,int pscore,bool pown)
{
    ScoreItem *pRet = create();
    if (pRet==NULL) return pRet;
    pRet->name=string(pname);
    pRet->score=pscore;
    pRet->own=pown;
    return pRet;
}





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
    
    
    LOG_SCORE("init called");
    
    // recupera estado de fichero
    bool scores_dict_loadable = false;

    JSONFileLoader *fileloader = JSONFileLoader::create();
    fileloader->setFileName(score_file_name);

    ValueMap scoreData;
    
    scores_dict_loadable=fileloader->load();
    if ( ! scores_dict_loadable ) {
        LOG_SCORE("error not dictionary found");
    } else {
        scoreData = fileloader->getContent().asValueMap();
        scores_dict_loadable=false;
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
        local_top_scores=scoreData.at("scores").asValueVector();
    } else {
        // no hay fichero de records generar

        int i;
        for (i=0;i<num_local_scores;i++) {
            stringstream n1;
            n1<< "Mikel" << (i+1);
            ValueMap ascore;
            ascore["name"]=Value(n1.str());
            ascore["score"]=Value(100*(12-i));
            local_top_scores.push_back(Value(ascore));
        }
        
    }
    
    
    Net::getInstance();
    
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
    JSONFileSaver *filesaver = JSONFileSaver::create();
    filesaver->setFileName(score_file_name);
    
    ValueMap scoreData;
    scoreData["v"]=Value(1);
    scoreData["scores"]=local_top_scores;
    filesaver->setContent(Value(scoreData));

    filesaver->save();
}


bool Scores::save_score()
{
    
    player_name=Preferences::getInstance()->getPlayerName();

    int ascore=Game::thegame->get_total_score();
    bool high_score=false;
    
    
    ValueVector::reverse_iterator i;
    for (i=local_top_scores.rbegin() ; i!=local_top_scores.rend() && i->asValueMap().at("score").asInt()<ascore ; i++ ) {
        //ValueMap si=i->asValueMap();
        //printf("buscando... %s %d\n",si.at("name").asString().c_str(),si.at("score").asInt());
    }
    
    if (i!=local_top_scores.rbegin()) {
        high_score=true;
    }
    ValueMap newscore;
    newscore["name"]=Value(player_name);
    newscore["score"]=Value(ascore);
    
    local_top_scores.insert(i.base(), Value(newscore));
    local_top_scores.pop_back();
    
    
    save_file();
    
    // #### GUARDAR NUEVO EN TO SEND
    const char *newname = newscore["name"].asString().c_str();
    const int oldscore = scores_to_send[newname].asValueMap()["score"].asInt();
    if (oldscore<ascore) {
        scores_to_send[newname]=Value(newscore);
    }
    JSONFileSaver *filesaver = JSONFileSaver::create();
    filesaver->setFileName(tosend_file_name);
    filesaver->setContent(Value(scores_to_send));
    filesaver->save();
    
    check_and_send_scores();
    
    return high_score;
}

// check sending files and sent or wait
void Scores::check_and_send_scores()
{
    // hay algo que enviar?
    if ( scores_to_send.size()==0 ) return;
    
    // #### SI NO ESTOY ESPERANDO RESPUESTA
    // #### MOVER TO_SEND A SENDING Y BOORAR TO_SEND
    // #### ENVIAR
    if ( ! Net::getInstance()->waiting_for_request() ) {
        JSONFileSaver *filesaver = JSONFileSaver::create();
        scores_sending=scores_to_send;
        filesaver = JSONFileSaver::create();
        filesaver->setFileName(sending_file_name);
        filesaver->setContent(Value(scores_sending));
        filesaver->save();

        scores_to_send=ValueMap();
        filesaver = JSONFileSaver::create();
        filesaver->setFileName(tosend_file_name);
        filesaver->setContent(Value(scores_to_send));
        filesaver->save();

        
        // enviar scores_sending
    }

    
}


bool Scores::would_achieve_high_score(int ascore)
{
    ValueMap lastscore=local_top_scores.back().asValueMap();
    
    if (ascore>lastscore.at("score").asInt()) {
        return true;
    }
    return false;
}

// #### HACER RECIBIR localtopscores DE LA RED


