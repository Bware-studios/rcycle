//
//  Preferences.h
//  rcycle
//
//  Created by Mikel on 08/10/14.
//
//

#ifndef __Rcycle__Preferences__
#define __Rcycle__Preferences__

#include "Common.h"

class Preferences : public cocos2d::Ref
{
public:
    bool init();
    CREATE_FUNC(Preferences);

    static Preferences *thepreferences;
    
    static Preferences *getInstance();

    
    
    std::string getPlayerName();
    void setPlayerName(std::string pname);
    
    int getNumGamesStarted();
    int setOneMoreGameStarted();
    
    
private:
    void load();
    void save();
    cocos2d::ValueMap prefsData;

};

#endif /* defined(__Rcycle__Preferences__) */
