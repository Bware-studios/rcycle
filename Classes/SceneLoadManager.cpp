//
//  SceneLoadManager.cpp
//  Rcycle
//
//  Created by Mikel on 29/10/13.
//
//

#include "SceneLoadManager.h"

USING_NS_CC;
USING_NS_CC_EXT;

SceneLoadManager *SceneLoadManager::theInstance=NULL;

SceneLoadManager::SceneLoadManager()
{
    auto loaderLibrary = NodeLoaderLibrary::newDefaultNodeLoaderLibrary();
    //loaderLibrary->registerNodeLoader("MenuLayer", MenuLayerLoader::loader());
    ccbReader = new CCBReader(loaderLibrary);
    ccbReader->retain();
}

SceneLoadManager::~SceneLoadManager()
{
    ccbReader->release();
}


SceneLoadManager *SceneLoadManager::getInstance()
{
    if (theInstance == NULL) {
        theInstance = new SceneLoadManager();
    }
    return theInstance;
}



