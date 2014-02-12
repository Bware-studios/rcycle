//
//  Trash.h
//  Rcycle
//
//  Created by Mikel on 10/12/13.
//
//

#ifndef __Rcycle__Trash__
#define __Rcycle__Trash__

#include "Common.h"

#include "GameObject.h"


class Trash : public GameObject
{
public:
    bool init();
    bool init(int p_trash_type, int p_trash_category);
    CREATE_FUNC(Trash);
    static Trash* create(int p_trash_type, int p_trash_category);
    void add_to_layer(cocos2d::Layer *alayer);
    
    int trash_type;
    int trash_category;
    
    static const int CAT_CRISTAL;
    static const int CAT_PLASTICO;
    static const int CAT_ORGANICO;
    static const int CAT_PAPEL;
    static const int num_trash_cat;
    static const char *trash_cat_names[];
};


#endif /* defined(__Rcycle__Trash__) */
