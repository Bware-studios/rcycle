//
//  Scores.h
//  Rcycle
//
//  Created by Mikel on 31/8/14.
//
//

#ifndef __Rcycle__Scores__
#define __Rcycle__Scores__

#include "Common.h"

struct scoreitem {
    std::string name;
    int score;
};


class Scores : public cocos2d::Ref
{
public:
    bool init();
    CREATE_FUNC(Scores);
    
    static Scores *thescores;
    
    static Scores *getInstance();
    
    void save_file();
    void save_score(std::string aname,int ascore);
    bool would_achieve_high_score(int ascore);
    std::string predicted_player_name();
    
    std::string full_file_name;
    cocos2d::ValueMap scoreData;
    
    const static int num_local_scores;
    struct scoreitem *high_scores;
    
};



#endif /* defined(__Rcycle__Scores__) */


