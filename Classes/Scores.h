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


class Scores : public cocos2d::Ref
{
public:
    bool init();
    CREATE_FUNC(Scores);
    
    static Scores *thescores;
    
    void save_score(std::string aname,int ascore);

    cocos2d::ValueMap scoreData;
    
    
};



#endif /* defined(__Rcycle__Scores__) */


