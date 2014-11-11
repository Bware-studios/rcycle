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


class ScoreItem : public cocos2d::Ref
{
public:
    bool init();
    CREATE_FUNC(ScoreItem);
    ScoreItem *create(const char *pname,int pscore,bool pown);
    
    std::string name;
    int score;
    bool own;
    
};

struct scoreitem {
    std::string name;
    int score;
    bool own;
    // pongo aqui la fecha... ?
};


class Scores : public cocos2d::Ref
{
public:
    bool init();
    CREATE_FUNC(Scores);
    
    static Scores *thescores;
    
    static Scores *getInstance();

    void set_player_name(std::string name);
    std::string get_player_name();

    void save_file();
    bool save_score();

    void check_and_send_scores();

    bool would_achieve_high_score(int ascore);
    std::string predicted_player_name();
    
    
    
    cocos2d::ValueVector local_top_scores;
    cocos2d::ValueMap scores_to_send;
    cocos2d::ValueMap scores_sending;

    
    const static int num_local_scores;
    //struct scoreitem *high_scores;
    std::string player_name = "";
    
};



#endif /* defined(__Rcycle__Scores__) */


