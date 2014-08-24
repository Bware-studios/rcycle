#include "AppDelegate.h"

USING_NS_CC;

using namespace std;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

bool AppDelegate::applicationDidFinishLaunching() {
    Application::Platform platform = Application::getInstance()->getTargetPlatform();

    
    // initialize director
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
        glview = GLView::create("My Game");
        // frame size for mac window
        if (platform == Application::Platform::OS_MAC) {
            glview->setFrameSize(1136, 640);
        }
        director->setOpenGLView(glview);
    }
	
    // turn on display FPS
    director->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0 / 60);
    
    
    //
    Size designSize = Size(480, 320);
    Size resourceSize = Size(480, 320);
    Size screenSize = glview->getFrameSize();
    
    std::vector<std::string> searchPaths;
    std::vector<std::string> resDirOrders;

    
    if (platform == Application::Platform::OS_IPHONE || platform == Application::Platform::OS_IPAD || platform == Application::Platform::OS_MAC) {
        searchPaths.push_back("publish-ios");
        FileUtils::getInstance()->setSearchPaths(searchPaths);
        if (screenSize.height > 768)
        {
            LOG_RESOLUTION("ipad hd");
            resourceSize = Size(2048, 1536);
            resDirOrders.push_back("resources-ipadhd");
        }
        else if (screenSize.height > 640)
        {
            LOG_RESOLUTION("ipad");
            resourceSize = Size(1536, 768);
            resDirOrders.push_back("resources-ipad");
        }else if (screenSize.height > 480)
        {
            LOG_RESOLUTION("iphone hd");
            resourceSize = Size(960, 640);
            resDirOrders.push_back("resources-iphonehd");
        }
        else
        {
            LOG_RESOLUTION("iphone");
            resDirOrders.push_back("resources-iphone");
        }

        FileUtils::getInstance()->setSearchResolutionsOrder(resDirOrders);

    } else if (platform == Application::Platform::OS_ANDROID) {
        if (screenSize.height > 960)
        {
            LOG_RESOLUTION("android resources-large");
            resourceSize = Size(960, 640);
            resDirOrders.push_back("resources-large");
        }
        else if (screenSize.height > 480)
        {
            LOG_RESOLUTION("android resources-medium");
            resourceSize = Size(720, 480);
            resDirOrders.push_back("resources-medium");
        }
        else
        {
            LOG_RESOLUTION("android resources-small");
            resourceSize = Size(568, 320);
            resDirOrders.push_back("resources-small");
        }
        
        FileUtils::getInstance()->setSearchResolutionsOrder(resDirOrders);
        
    } else {
        LOG_RESOLUTION("cannot determine plataform resolution");
        LOG("Warning platform not supported");
    }
    
//    // pon codigo decente para el orden de resoluciones
//    std::vector<std::string> searchDirs;
//    searchDirs.push_back("resources-iphonehd");
//    FileUtils::getInstance()->setSearchResolutionsOrder(searchDirs);

    LOG("scale factor (p): %f",resourceSize.height/designSize.height);
    LOG("scale factor: %f",resourceSize.width/designSize.width);
//    director->setContentScaleFactor(resourceSize.width/designSize.width);
    director->setContentScaleFactor(resourceSize.height/designSize.height);

    glview->setDesignResolutionSize(designSize.width, designSize.height, /*ResolutionPolicy::SHOW_ALL*/ResolutionPolicy::FIXED_HEIGHT);
    

    // create a scene. it's an autorelease object
    //auto scene= HelloWorld::createScene();

    Scene *scene2;
    scene2 = LoadingScene::create();

    // run
    director->runWithScene(scene2);

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
}
