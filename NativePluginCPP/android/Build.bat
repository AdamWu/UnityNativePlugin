@echo off

rem build & copy Android armeabi-v7a
set OPTIONS=^
NDK_PROJECT_PATH=. ^
NDK_APPLICATION_MK=jni/Application.mk

call %NDK_ROOT%/ndk-build clean %OPTIONS%
call %NDK_ROOT%/ndk-build -j4 %OPTIONS%
