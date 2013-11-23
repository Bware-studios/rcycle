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

using namespace std;
using namespace cocosbuilder;

SceneLoadManager *SceneLoadManager::theInstance=NULL;

SceneLoadManager::SceneLoadManager()
{
    auto loaderLibrary = NodeLoaderLibrary::newDefaultNodeLoaderLibrary();
    loaderLibrary->retain();
    loaderLibrary->registerNodeLoader("MenuLayer", MenuLayerLoader::loader());
    loaderLibrary->registerNodeLoader("GameLayer", GameLayerLoader::loader());
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


Layer *SceneLoadManager::layerFromFile(const char *pFileName,CCBSelectorResolver *pOwner)
{
    
    auto loaderLibrary = NodeLoaderLibrary::newDefaultNodeLoaderLibrary();
    loaderLibrary->registerNodeLoader("MenuLayer", MenuLayerLoader::loader());
    loaderLibrary->registerNodeLoader("GameLayer", GameLayerLoader::loader());
    ccbReader = new CCBReader(loaderLibrary);

    
    Object *owner=dynamic_cast<Object*>(pOwner);
    return (Layer *)ccbReader->readNodeGraphFromFile(pFileName,owner);
}



bool MenuLayer::init()
{
    
    return true;
}




bool MenuScene::init(const char *ccb_filename)
{
    auto loadmanager = SceneLoadManager::getInstance();
    layer=(MenuLayer *)loadmanager->layerFromFile(ccb_filename,this);
    this->addChild(layer);
    
    return true;
}

SEL_MenuHandler MenuScene::onResolveCCBCCMenuItemSelector(Object * pTarget, const char* pSelectorName)
{
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "enter", MenuScene::enter);
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "back", MenuScene::back);
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "info", MenuScene::info);
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "options", MenuScene::options);
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "fame", MenuScene::fame);
    
    return NULL;
}

SEL_CallFuncN MenuScene::onResolveCCBCCCallFuncSelector(Object * pTarget, const char* pSelectorName)
{
    return NULL;
}

Control::Handler MenuScene::onResolveCCBCCControlSelector(Object * pTarget, const char* pSelectorName)
{
    return NULL;
}


bool MenuScene::onAssignCCBMemberVariable(Object* target, const char* memberVariableName, Node* node)
{
    return true;
}


void MenuScene::completedAnimationSequenceNamed(const char *name)
{
    cout << "Menu scene completedanimation  Not overriden\n";
}


void MenuScene::enter(Object *pSender)
{
    cout << "Menu scene selector called: enter  Not overriden\n";
}

void MenuScene::back(Object *pSender)
{
    cout << "Menu scene selector called: back  Not overriden\n";
}

void MenuScene::info(Object *pSender)
{
    cout << "Menu scene selector called: info  Not overriden\n";
}

void MenuScene::options(Object *pSender)
{
    cout << "Menu scene selector called: options  Not overriden\n";
}

void MenuScene::fame(Object *pSender)
{
    cout << "Menu scene selector called: fame  Not overriden\n";
}



bool GameLayer::init()
{
    
    return true;
}
