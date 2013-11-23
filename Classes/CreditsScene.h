//
//  CreditsScene.h
//  Rcycle
//
//  Created by Mikel on 06/11/13.
//
//

#ifndef __Rcycle__CreditsScene__
#define __Rcycle__CreditsScene__

#include <iostream>
#include "cocos2d.h"
#include "cocos-ext.h"
#include "cocosbuilder/CocosBuilder.h"

#include "SceneLoadManager.h"
#include "MainMenuScene.h"


class CreditsScene : public MenuScene
//public cocosbuilder::CCBAnimationManagerDelegate
{
public:
    bool init();
    CREATE_FUNC(CreditsScene);
    
    void back(Object *pSender);
    
};


#endif /* defined(__Rcycle__CreditsScene__) */
