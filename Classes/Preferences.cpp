//
//  Preferences.cpp
//  rcycle
//
//  Created by Mikel on 08/10/14.
//
//

#include "Preferences.h"

#include "JSONcodec.h"



USING_NS_CC;
using namespace std;

Preferences *Preferences::thepreferences=NULL;

Preferences *Preferences::getInstance()
{
    if (thepreferences==NULL) {
        Preferences::create();
    }
    return thepreferences;
}

bool Preferences::init()
{
    Preferences::thepreferences=this;
    Preferences::thepreferences->retain();

    load();
    
    return true;
}


string Preferences::getPlayerName()
{
    string name;
    try {
        name=prefsData.at("PlayerName").asString();
        return name;
    } catch (exception& e) {
        return string("Unnamed Player");
    }
}

void Preferences::setPlayerName(string pname)
{
    prefsData["PlayerName"]=pname;
    save();
}

std::string Preferences::getBwnetId()
{
    string bwnetid;
    try {
        bwnetid=prefsData.at("BwnetId").asString();
        return bwnetid;
    } catch (exception& e) {
        return string("");
    }
}

void Preferences::setBwnetId(std::string id)
{
    prefsData["BwnetId"]=id;
    save();
}

bool Preferences::getNetActivated()
{
    bool activated;
    try {
        activated=prefsData.at("NetActive").asBool();
        return activated;
    } catch (exception& e) {
        return true;
    }
}

void Preferences::setNetActivated(bool activated)
{
    prefsData["NetActive"]=activated;
    save();
}



int Preferences::getNumGamesStarted()
{
    try {
        int num=prefsData.at("NumGamesStarted").asInt();
        return num;
    } catch (exception& e) {
        return 0;
    }
}

int Preferences::setOneMoreGameStarted()
{
    int num=getNumGamesStarted();
    num+=1;
    prefsData["NumGamesStarted"]=num;
    save();
    return num;
}

int Preferences::getBestScore()
{
    try {
        int num=prefsData.at("BestScore").asInt();
        return num;
    } catch (exception& e) {
        return 0;
    }
}

bool Preferences::setIfBestScore(int score)
{
    int best = getBestScore();
    if ( score > best ) {
        prefsData["BestScore"] = score;
        return true;
    }
    return false;
}

void Preferences::load()
{
    JSONFileLoader *prefs_file = JSONFileLoader::create();
    prefs_file->setFileName("preferences.json");
    prefs_file->load();
    prefsData=prefs_file->getContent().asValueMap();
}


void Preferences::save()
{
    JSONFileSaver *prefs_file = JSONFileSaver::create();
    prefs_file->setFileName("preferences.json");
    prefs_file->setContent(Value(prefsData));
    prefs_file->save();
}

