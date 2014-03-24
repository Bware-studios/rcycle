//
//  LoadingScene.h
//  Rcycle
//
//  Created by Mikel on 04/11/13.
//
//

#ifndef __Rcycle__LoadingScene__
#define __Rcycle__LoadingScene__

#include "Common.h"

//#include "cocos-ext.h"
#include "cocosbuilder/CocosBuilder.h"

#include "SceneLoadManager.h"
#include "MainMenuScene.h"

#include "Audio.h"

class LoadingScene : public MenuScene
//public cocosbuilder::CCBAnimationManagerDelegate
{
public:
    bool init();
    CREATE_FUNC(LoadingScene);
    
    bool onAssignCCBMemberVariable(Object* target, const char* memberVariableName, Node* node);

    
    void time_passes();
    
    void start();

    void do_init();
    
    cocos2d::LabelTTF *text1;
    int state;

};




#endif /* defined(__Rcycle__LoadingScene__) */
