
# o el que sea en el ordenador
export NDK_ROOT=/opt2/local/android-ndk-r9c 

android_targetid=4

android update project -p . -t $android_targetid
android update project -p ../cocos2d/cocos/2d/platform/android/java/ -t $android_targetid

./build_native.py
find assets -name "Icon*" -exec rm \{\} \;
ant debug


