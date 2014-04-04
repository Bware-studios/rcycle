//
//  CreditsScene.h
//  Rcycle
//
//  Created by Mikel on 06/11/13.
//
//

#ifndef __Rcycle__CreditsScene__
#define __Rcycle__CreditsScene__

#include "Common.h"

//#include "cocos-ext.h"
#include "cocosbuilder/CocosBuilder.h"

#include "SceneLoadManager.h"
#include "MainMenuScene.h"


class CreditsScene : public MenuScene
//public cocosbuilder::CCBAnimationManagerDelegate
{
public:
    bool init();
    CREATE_FUNC(CreditsScene);
    
    void back(cocos2d::Ref *pSender);
    
};


#endif /* defined(__Rcycle__CreditsScene__) */
