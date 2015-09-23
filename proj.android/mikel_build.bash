
# o el que sea en el ordenador
export NDK_ROOT=/opt2/android-ndk-r9d


android_targetid=4

android update project -p . -t $android_targetid --subprojects
android update project -p ../cocos2d/cocos/2d/platform/android/java/ -t $android_targetid --subprojects

./build_native.py
find assets -name "Icon*" -exec rm \{\} \;
ant debug
#ant release

