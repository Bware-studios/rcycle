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
    loaderLibrary->registerNodeLoader("Container", ContainerLoader::loader());
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

    
    Ref *owner=dynamic_cast<Ref*>(pOwner);
    return (Layer *)ccbReader->readNodeGraphFromFile(pFileName,owner);
}


Container *SceneLoadManager::containerFromFile(const char *pFileName,CCBSelectorResolver *pOwner)
{
    
    auto loaderLibrary = NodeLoaderLibrary::newDefaultNodeLoaderLibrary();
    loaderLibrary->registerNodeLoader("MenuLayer", MenuLayerLoader::loader());
    loaderLibrary->registerNodeLoader("GameLayer", GameLayerLoader::loader());
    loaderLibrary->registerNodeLoader("Container", ContainerLoader::loader());
    ccbReader = new CCBReader(loaderLibrary);
    
    
    Ref *owner=dynamic_cast<Ref*>(pOwner);
    Container *acontainer=(Container *)ccbReader->readNodeGraphFromFile(pFileName,owner);
    acontainer->setAnimationManager(ccbReader->getAnimationManager());
    return acontainer;
}

AnimatedGameObject *SceneLoadManager::gameObjectFromFile(const char *pFileName,CCBSelectorResolver *pOwner)
{
    
    auto loaderLibrary = NodeLoaderLibrary::newDefaultNodeLoaderLibrary();
    loaderLibrary->registerNodeLoader("MenuLayer", MenuLayerLoader::loader());
    loaderLibrary->registerNodeLoader("GameLayer", GameLayerLoader::loader());
    loaderLibrary->registerNodeLoader("Container", ContainerLoader::loader());
    loaderLibrary->registerNodeLoader("Camion", CamionLoader::loader());
    ccbReader = new CCBReader(loaderLibrary);
    
    
    Ref *owner=dynamic_cast<Ref*>(pOwner);
    AnimatedGameObject *agameobject=(AnimatedGameObject*)(ccbReader->readNodeGraphFromFile(pFileName,owner));
    agameobject->setAnimationManager(ccbReader->getAnimationManager());
    return agameobject;
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

SEL_MenuHandler MenuScene::onResolveCCBCCMenuItemSelector(Ref * pTarget, const char* pSelectorName)
{
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "enter", MenuScene::enter);
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "back", MenuScene::back);
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "info", MenuScene::info);
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "options", MenuScene::options);
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "help", MenuScene::help);
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "fame", MenuScene::fame);
    
    return NULL;
}

SEL_CallFuncN MenuScene::onResolveCCBCCCallFuncSelector(Ref * pTarget, const char* pSelectorName)
{
    return NULL;
}

Control::Handler MenuScene::onResolveCCBCCControlSelector(Ref * pTarget, const char* pSelectorName)
{
    return NULL;
}


bool MenuScene::onAssignCCBMemberVariable(Ref* pTarget, const char* pMemberVariableName, Node* pNode)
{
    LOG_CCB("variable [%s]",pMemberVariableName);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "quit_button", MenuItem *, this->quit_button);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "settings_button", MenuItem *, this->settings_button);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "t1", Label *, this->text1);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "t2", Label *, this->text2);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "menu", Menu *, this->menu);
    return true;
}


void MenuScene::completedAnimationSequenceNamed(const char *name)
{
    LOG_CCB("Menu scene completedanimation  Not overriden");
}


void MenuScene::enter(Ref *pSender)
{
    LOG_CCB("Menu scene selector called: enter  Not overriden");
}

void MenuScene::back(Ref *pSender)
{
    LOG_CCB("Menu scene selector called: back  Not overriden");
}

void MenuScene::info(Ref *pSender)
{
    LOG_CCB("Menu scene selector called: info  Not overriden");
}

void MenuScene::options(Ref *pSender)
{
    LOG_CCB("Menu scene selector called: options  Not overriden");
}

void MenuScene::help(Ref *pSender)
{
    LOG_CCB("Menu scene selector called: help  Not overriden");
}

void MenuScene::fame(Ref *pSender)
{
    LOG_CCB("Menu scene selector called: fame  Not overriden");
}



bool GameLayer::init()
{

    return true;
}
