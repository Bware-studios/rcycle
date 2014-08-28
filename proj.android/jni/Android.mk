LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := cocos2dcpp_shared

LOCAL_MODULE_FILENAME := libcocos2dcpp

LOCAL_SRC_FILES := hellocpp/main.cpp \
	../../Classes/AppDelegate.cpp \
	../../Classes/Audio.cpp \
	../../Classes/Camion.cpp \
	../../Classes/Container.cpp \
	../../Classes/CreditsScene.cpp \
	../../Classes/FameScene.cpp \
	../../Classes/Game.cpp \
	../../Classes/GameObject.cpp \
	../../Classes/GameScene.cpp \
	../../Classes/LoadingScene.cpp \
	../../Classes/Log.cpp \
	../../Classes/MainMenuScene.cpp \
	../../Classes/Options.cpp \
	../../Classes/OptionsScene.cpp \
	../../Classes/SceneLoadManager.cpp \
	../../Classes/StatsScene.cpp \
	../../Classes/Trash.cpp \
	../../Classes/TrashGenerator.cpp \
	../../Classes/WorldFrame.cpp \



LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../Classes \
    $(LOCAL_PATH)/../../cocos2d/cocos/editor-support \
    $(LOCAL_PATH)/../../cocos2d 

LOCAL_WHOLE_STATIC_LIBRARIES := cocos2dx_static
LOCAL_WHOLE_STATIC_LIBRARIES += cocosdenshion_static
LOCAL_WHOLE_STATIC_LIBRARIES += box2d_static
LOCAL_WHOLE_STATIC_LIBRARIES += cocosbuilder_static


include $(BUILD_SHARED_LIBRARY)

$(call import-module,2d)
$(call import-module,audio/android)
$(call import-module,Box2D)
$(call import-module,editor-support/cocosbuilder)
