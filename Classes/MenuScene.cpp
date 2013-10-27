//
//  MenuScene.cpp
//  Rcycle
//
//  Created by Mikel on 16/10/13.
//
//

#include "MenuScene.h"

USING_NS_CC;
USING_NS_CC_EXT;


bool MenuScene::init(const char *ccb_filename)
{
    cout << "init with file: " <<ccb_filename<<"\n";
    auto loaderLibrary = NodeLoaderLibrary::newDefaultNodeLoaderLibrary();
    loaderLibrary->registerNodeLoader("MenuLayer", MenuLayerLoader::loader());
    auto ccbReader = new CCBReader(loaderLibrary);
    
    layer=(MenuLayer *)ccbReader->readNodeGraphFromFile(ccb_filename,this);
    ccbReader->release();

    this->addChild(layer);
    
    return true;
}


bool MainMenuScene::init()
{
    cout << "init MainMenuScene \n";
    if ( ! MenuScene::init("MainScene") ) return false;
    return true;
}



void MainMenuScene::click(Object *pSender)
{
    FinishScene *newscene = FinishScene::create();
    //cout << "clicked\n";
    newscene->layer->label1->setString("Sorry...\nyou lost :-(");
    Director::getInstance()->replaceScene((Scene *)newscene);
    
}

void MainMenuScene::completedAnimationSequenceNamed(const char *name) {
    printf("%s completada\n",name);
}


bool FinishScene::init()
{
    cout << "init FinishScene \n";
    if ( ! MenuScene::init("FinishScene") ) return false;


    return true;
}



void FinishScene::click(Object *pSender)
{
    //cout << "clicked\n";
    auto scene = MainMenuScene::create();
    Director::getInstance()->replaceScene(scene);

    CCBAnimationManager *amanager=(CCBAnimationManager *)scene->layer->getUserObject();
    amanager->setDelegate(scene);
    amanager->runAnimationsForSequenceNamed("a1");

}



bool MenuLayer::init()
{

    return true;
}


bool MenuLayer::onAssignCCBMemberVariable(Object* pTarget, const char* pMemberVariableName, Node* pNode)
{
    cout << "var: " << pMemberVariableName << "\n";
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "label1", LabelTTF *, this->label1);
    
    return true;
}


SEL_MenuHandler MenuLayer::onResolveCCBCCMenuItemSelector(Object * pTarget, const char* pSelectorName)
{
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "onClick", MainMenuScene::click);
    return NULL;
}


SEL_CallFuncN MenuLayer::onResolveCCBCCCallFuncSelector(Object * pTarget, const char* pSelectorName)
{
    
    return NULL;
}


Control::Handler MenuLayer::onResolveCCBCCControlSelector(Object * pTarget, const char* pSelectorName)
{
    
    return NULL;
}


SEL_MenuHandler MainMenuScene::onResolveCCBCCMenuItemSelector(Object * pTarget, const char* pSelectorName)
{
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "onClick", MainMenuScene::click);
    return NULL;
}


SEL_CallFuncN MainMenuScene::onResolveCCBCCCallFuncSelector(Object * pTarget, const char* pSelectorName)
{
    
    return NULL;
}


Control::Handler MainMenuScene::onResolveCCBCCControlSelector(Object * pTarget, const char* pSelectorName)
{
    
    return NULL;
}


SEL_MenuHandler FinishScene::onResolveCCBCCMenuItemSelector(Object * pTarget, const char* pSelectorName)
{
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "onClick", FinishScene::click);
    return NULL;
}


SEL_CallFuncN FinishScene::onResolveCCBCCCallFuncSelector(Object * pTarget, const char* pSelectorName)
{
    
    return NULL;
}


Control::Handler FinishScene::onResolveCCBCCControlSelector(Object * pTarget, const char* pSelectorName)
{
    
    return NULL;
}





