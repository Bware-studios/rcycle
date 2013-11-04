//
//  LoadingScene.h
//  Rcycle
//
//  Created by Mikel on 04/11/13.
//
//

#ifndef __Rcycle__LoadingScene__
#define __Rcycle__LoadingScene__

#include <iostream>
#include "cocos2d.h"
#include "cocos-ext.h"

#include "SceneLoadManager.h"
#include "MainMenuScene.h"


class LoadingScene : public MenuScene
//public cocos2d::extension::CCBAnimationManagerDelegate
{
public:
    bool init();
    CREATE_FUNC(LoadingScene);
    
    bool onAssignCCBMemberVariable(Object* target, const char* memberVariableName, Node* node);

    
    void time_passes();
    
    void start();

    cocos2d::LabelTTF *text1;
    int state;

};




#endif /* defined(__Rcycle__LoadingScene__) */
