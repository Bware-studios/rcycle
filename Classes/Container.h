//
//  Container.h
//  Rcycle
//
//  Created by Mikel on 13/12/13.
//
//

#ifndef __Rcycle__Container__
#define __Rcycle__Container__

#include "Common.h"

#include "Game.h"
#include "GameScene.h"
#include "GameObject.h"
#include "Trash.h"


class Container : public GameObject
{
public:
    bool init(int p_trash_category);
    static Container* create(int p_trash_category);
    void add_to_layer(cocos2d::Layer *alayer);
    
    void destroy(Trash *atrash);
    
    int trash_category;
    
private:
    int semiheight;
    int semiwidth;
    int semiindent;
    int verticalindent;
    
    // para el contenedor de cristal que esta arriba
    cocos2d::Sprite *over_sprite;

};

#endif /* defined(__Rcycle__Container__) */
