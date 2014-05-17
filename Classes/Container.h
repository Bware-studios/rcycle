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

#include "cocosbuilder/CocosBuilder.h"


class GameObject;
class Trash;

#include "GameObject.h"

class Container : public GameObject
{
public:
    bool init();
    bool init(int p_trash_category);
    CREATE_FUNC(Container);
    static Container* create(int p_trash_category);
    void setAnimationManager(cocosbuilder::CCBAnimationManager *p_animation_manager);
    void add_to_layer(cocos2d::Layer *alayer);
    
    void destroy(Trash *atrash);
    
    void start_enter_animation(cocos2d::Point start_postion,cocos2d::Point end_position);
    void start_exit_animation(cocos2d::Point end_position);
    
    int trash_category;
    
private:
    int semiheight;
    int semiwidth;
    int semiindent;
    int offset;
    int verticalindent;
    int recycled_ok_text_x;
    int recycled_ok_text_y;
    int recycled_fail_text_x;
    int recycled_fail_text_y;


    
    int recycled_ok;
    int recycled_fail;
    
    cocos2d::Label *score_ok;
    cocos2d::Label *score_fail;

    cocos2d::ParticleSystem *dust;
    
    // para el contenedor de cristal que esta arriba
    cocos2d::Sprite *over_sprite;
    
    cocosbuilder::CCBAnimationManager *animation_manager;

};

#endif /* defined(__Rcycle__Container__) */
