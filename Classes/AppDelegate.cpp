//
// Resoluciones de interes
//
//
// iphone classic     480 x 320   << design
// iphone retina      960 x 640      r x2
// iphone 5s retina  1136 x 640      r x2
// ipad   classic    1024 x 768      r x2
// ipad retinas      2048 x 1536     r x4


#include "AppDelegate.h"

#include "Preferences.h"
#include "Scores.h"


extern "C"{
    size_t fwrite$UNIX2003( const void *a, size_t b, size_t c, FILE *d )
    {
        return fwrite(a, b, c, d);
    }
    char* strerror$UNIX2003( int errnum )
    {
        return strerror(errnum);
    }
}


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
            // ipad
            //glview->setFrameSize(1024, 768);
            // ipad hd
            //glview->setFrameSize(2048, 1536);
            // iphone 5s
            //glview->setFrameSize(1136, 640);
            // iphone 4 retina
            //glview->setFrameSize(960, 640);
            // generic
            glview->setFrameSize(960, 640);
        }
        director->setOpenGLView(glview);
    }

    Point vorig=glview->getVisibleOrigin();
    LOG_RESOLUTION("visible origin: %f %f",vorig.x, vorig.y);
    Size vsize=glview->getVisibleSize();
    LOG_RESOLUTION("visible size: %f %f",vsize.width, vsize.height);
    
    // turn on display FPS
    director->setDisplayStats(false);

    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0 / 60);
    
    
    //
    Size designSize = Size(480, 320);
    Size resourceSize = Size(480, 320);
    Size screenSize = glview->getFrameSize();

    float content_scale_factor=1;
    
    ResolutionPolicy rpolicy=ResolutionPolicy::FIXED_HEIGHT;

    
    std::vector<std::string> searchPaths;
    std::vector<std::string> resDirOrders;

    
    
    
    if (  platform == Application::Platform::OS_IPHONE
         || platform == Application::Platform::OS_IPAD
         || ( platform == Application::Platform::OS_MAC && !Options::resolution_mac_res_as_android) )
    {
        searchPaths.push_back("publish-ios");
        FileUtils::getInstance()->setSearchPaths(searchPaths);
        if (screenSize.height > 768)
        {
            LOG_RESOLUTION("ipad hd");
            resourceSize = Size(2048, 1536);
            resDirOrders.push_back("resources-ipadhd");
            rpolicy=ResolutionPolicy::FIXED_WIDTH;
            content_scale_factor=4;
        }
        else if (screenSize.height > 640)
        {
            LOG_RESOLUTION("ipad");
            resourceSize = Size(1024, 768);
            resDirOrders.push_back("resources-ipad");
            rpolicy=ResolutionPolicy::FIXED_WIDTH;
            content_scale_factor=2;
        }else if (screenSize.height > 480)
        {
            LOG_RESOLUTION("iphone hd");
            resourceSize = Size(960, 640);
            resDirOrders.push_back("resources-iphonehd");
            content_scale_factor=2;
        }
        else
        {
            LOG_RESOLUTION("iphone");
            resDirOrders.push_back("resources-iphone");
            content_scale_factor=1;
        }

        FileUtils::getInstance()->setSearchResolutionsOrder(resDirOrders);

    } else if (platform == Application::Platform::OS_ANDROID
        || ( platform == Application::Platform::OS_MAC && Options::resolution_mac_res_as_android) )
    {
        searchPaths.push_back("publish-android");
        FileUtils::getInstance()->setSearchPaths(searchPaths);
        if (screenSize.height > 640)
        {
            LOG_RESOLUTION("android resources-xlarge");
            resourceSize = Size(1920, 1280);
            resDirOrders.push_back("resources-xlarge");
            rpolicy=ResolutionPolicy::SHOW_ALL;
        } else if (screenSize.height > 480)
        {
            LOG_RESOLUTION("android resources-large");
            resourceSize = Size(960, 640);
            resDirOrders.push_back("resources-large");
            rpolicy=ResolutionPolicy::SHOW_ALL;
        }
        else if (screenSize.height > 320)
        {
            LOG_RESOLUTION("android resources-medium");
            resourceSize = Size(640, 480);
            resDirOrders.push_back("resources-medium");
            rpolicy=ResolutionPolicy::SHOW_ALL;
        }
        else
        {
            LOG_RESOLUTION("android resources-small");
            resourceSize = Size(480, 320);
            resDirOrders.push_back("resources-small");
            rpolicy=ResolutionPolicy::SHOW_ALL;
        }
        
        FileUtils::getInstance()->setSearchResolutionsOrder(resDirOrders);
        content_scale_factor=resourceSize.height/designSize.height;
    } else {
        LOG_RESOLUTION("cannot determine plataform resolution");
        LOG("Warning platform not supported");
        content_scale_factor=resourceSize.height/designSize.height;
    }
    
//    // pon codigo decente para el orden de resoluciones
//    std::vector<std::string> searchDirs;
//    searchDirs.push_back("resources-iphonehd");
//    FileUtils::getInstance()->setSearchResolutionsOrder(searchDirs);

    LOG_RESOLUTION("scale factor (p): %f",resourceSize.height/designSize.height);
    LOG_RESOLUTION("scale factor: %f",resourceSize.width/designSize.width);
//    director->setContentScaleFactor(resourceSize.width/designSize.width);
    director->setContentScaleFactor(content_scale_factor);

//    ResolutionPolicy rpolicy=ResolutionPolicy::SHOW_ALL;
//    ResolutionPolicy rpolicy=ResolutionPolicy::NO_BORDER;

    glview->setDesignResolutionSize(designSize.width, designSize.height, rpolicy);
    

    LOG_RESOLUTION("target design resolution: %f %f",designSize.width, designSize.height);
    
    Size actualDesignSize = glview->getDesignResolutionSize();
    LOG_RESOLUTION("design resolution final: %f %f",actualDesignSize.width, actualDesignSize.height);

    

    Preferences::getInstance()->setPlayerName("");

    
    printf("Playe name: %s <<<<<<<<<<<<<<<< \n",Preferences::getInstance()->getPlayerName().c_str());
    
    // create a scene. it's an autorelease object
    //auto scene= HelloWorld::createScene();

    //auto scene2 = MainMenuScene::create();
    auto scene2 = LoadingScene::create();

    // run
    director->runWithScene(scene2);
    
    
    Scores::getInstance();

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
