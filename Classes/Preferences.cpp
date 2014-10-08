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

