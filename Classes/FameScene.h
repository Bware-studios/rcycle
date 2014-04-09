//
//  FameScene.h
//  Rcycle
//
//  Created by Mikel on 10/11/13.
//
//

#ifndef __Rcycle__FameScene__
#define __Rcycle__FameScene__

#include "Common.h"

//#include "cocos-ext.h"
#include "cocosbuilder/CocosBuilder.h"

#include "MainMenuScene.h"
#include "SceneLoadManager.h"



class FameScene : public MenuScene
//public cocosbuilder::CCBAnimationManagerDelegate
{
public:
    bool init();
    CREATE_FUNC(FameScene);
    
    void back(cocos2d::Ref *pSender);
    
};



#endif /* defined(__Rcycle__FameScene__) */
