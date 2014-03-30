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

CCBAnimationManager *SceneLoadManager::getAnimationManager()
{
    return SceneLoadManager::getInstance()->ccbReader->getAnimationManager();
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


bool MenuScene::onAssignCCBMemberVariable(Object* pTarget, const char* pMemberVariableName, Node* pNode)
{
    LOG_CCB("variable [%s]",pMemberVariableName);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "quit_button", MenuItem *, this->quit_button);
    return true;
}


void MenuScene::completedAnimationSequenceNamed(const char *name)
{
    LOG_CCB("Menu scene completedanimation  Not overriden");
}


void MenuScene::enter(Object *pSender)
{
    LOG_CCB("Menu scene selector called: enter  Not overriden");
}

void MenuScene::back(Object *pSender)
{
    LOG_CCB("Menu scene selector called: back  Not overriden");
}

void MenuScene::info(Object *pSender)
{
    LOG_CCB("Menu scene selector called: info  Not overriden");
}

void MenuScene::options(Object *pSender)
{
    LOG_CCB("Menu scene selector called: options  Not overriden");
}

void MenuScene::fame(Object *pSender)
{
    LOG_CCB("Menu scene selector called: fame  Not overriden");
}



bool GameLayer::init()
{

    return true;
}
