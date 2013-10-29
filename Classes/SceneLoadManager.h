//
//  SceneLoadManager.h
//  Rcycle
//
//  Created by Mikel on 29/10/13.
//
//

#ifndef __Rcycle__SceneLoadManager__
#define __Rcycle__SceneLoadManager__

#include <iostream>
#include "cocos2d.h"
#include "cocos-ext.h"

class SceneLoadManager
{
public:
    SceneLoadManager();
    ~SceneLoadManager();
    static SceneLoadManager *getInstance();
    
    
    
private:
    static SceneLoadManager *theInstance;
    cocos2d::extension::CCBReader *ccbReader;
};





#endif /* defined(__Rcycle__SceneLoadManager__) */
