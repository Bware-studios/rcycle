
# o el que sea en el ordenador
export NDK_ROOT=/opt2/local/android-ndk-r9c 

./build_native.py
find assets -name "Icon*" -exec rm \{\} \;
ant debug


