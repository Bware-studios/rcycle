//
//  Scores.cpp
//  Rcycle
//
//  Created by Mikel on 31/8/14.
//
//

#include "Scores.h"

USING_NS_CC;
using namespace std;


const char *score_file_name="scoreData_file.dct";



Scores *Scores::thescores = NULL;

bool Scores::init() {
    Scores::thescores=this;
    Scores::thescores->retain();
    
    LOG_SCORE("init called");
    
    // recupera estado de fichero

    scoreData = FileUtils::getInstance()->getValueMapFromFile(string(score_file_name));
    
    bool scores_dict_loadable = false;
    if ( scoreData.count("v") ) {
        int dict_version=scoreData.at(string("v")).asInt();
        LOG_SCORE("V present");
    }
    
    string full_file_name;
    full_file_name= FileUtils::getInstance()->getWritablePath().c_str()+string("/")+string(score_file_name);
    
    
    scoreData["v"]=Value(42);
    FileUtils::getInstance()->writeToFile(scoreData, score_file_name);
    //scoreData = Dictionary::createWithContentsOfFile(score_file_name);
    
    
    // cocos2d String
    
//    if (dict_version_str->length()>0) {
//        int dict_version;
//        // to char* string to stringstream
//        stringstream vstrm(dict_version_str->getCString());
//        vstrm >> dict_version;
//        LOG_SCORE("r: %d",dict_version);
//        if (dict_version==1) {
//            LOG_SCORE("Scores dictionary found");
//            scores_dict_loadable=true;
//        } else {
//            LOG_SCORE("No scores dictionary known version loaded");
//        }
//    } else {
//        LOG_SCORE("No scores dictionary loaded");
//    }
//    
//    if (scores_dict_loadable) {
//        
//        
//    }
//
//    scoreData->setObject(<#cocos2d::Ref *pObject#>, <#const std::string &key#>)
//    
    return true;
}




