//
//  Scores.cpp
//  Rcycle
//
//  Created by Mikel on 31/8/14.
//
//

#include "Scores.h"

#include <sys/stat.h>


USING_NS_CC;
using namespace std;


const char *rcycler_dir_name="rcycler";
const char *score_file_name="scoreData_file.dct";

const int num_local_scores = 10;


Scores *Scores::thescores = NULL;


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

    
    // recupera estado de fichero
    scoreData = FileUtils::getInstance()->getValueMapFromFile(full_file_name.c_str());
    
    bool scores_dict_loadable = false;
    if ( scoreData.count("v") ) {
        int dict_version=scoreData.at(string("v")).asInt();
        LOG_SCORE("V present v= %d",dict_version);
        if (dict_version==1) {
            LOG_SCORE("loading version 1");
            scores_dict_loadable=true;
        }
    }

    if (scores_dict_loadable) {
        // cargar scores
        int i;
        for (i=0;i<num_local_scores;i++) {
            //high_scores[i].name=scoreData["scores"][i];
            
        }
    }
    
    

    
    // normalmente no lo grabarias aqui solo para probar
    save_file();
    
    

    return true;
}


void Scores::save_file()
{
    // set version to save
    scoreData["v"]=Value(42);

    ValueMap &scores=scoreData["scores"].asValueMap();
    ValueMap *item;
    
    int i;
    for (i=0;i<num_local_scores;i++) {
        item=&(scores[i].asValueMap());
    }
    
    
    FileUtils::getInstance()->writeToFile(scoreData, full_file_name.c_str());
}


void Scores::save_score(std::string aname,int ascore)
{
    
    save_file();
}



