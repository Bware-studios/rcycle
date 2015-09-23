APP_ABI := armeabi armeabi-v7a 
#APP_ABI := all
APP_STL := gnustl_static
APP_CPPFLAGS := -frtti -DCC_ENABLE_CHIPMUNK_INTEGRATION=1 -DCOCOS2D_DEBUG=1 -std=c++11 -fsigned-char
