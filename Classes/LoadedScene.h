//
//  LoadedScene.h
//  Rcycle
//
//  Created by Mikel on 29/10/13.
//
//

// Class for scene loaded from CCB
// Scenes will inherit from this


#ifndef __Rcycle__LoadedScene__
#define __Rcycle__LoadedScene__

#include <iostream>
#include "cocos2d.h"
#include "cocos-ext.h"
#include "cocosbuilder/CocosBuilder.h"



class LoadedScene : public cocos2d::Scene
{
public:
    bool init(const char *ccb_filename);

};











#endif /* defined(__Rcycle__LoadedScene__) */
