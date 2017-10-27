include $(CLEAR_VARS)

LOCAL_PATH := $(call my-dir)

LOCAL_ARM_MODE  := arm
LOCAL_PATH      := $(NDK_PROJECT_PATH)
LOCAL_MODULE    := libUnityNativePlugin
LOCAL_CFLAGS    := -O2 -D__EFFEKSEER_RENDERER_GLES2__
LOCAL_LDLIBS    := -landroid -lEGL -lGLESv2

LOCAL_C_INCLUDES += \
	$(LOCAL_PATH)/../src

LOCAL_SRC_FILES := \
	$(LOCAL_PATH)/../src/NativePluginCPP.cpp 


include $(BUILD_SHARED_LIBRARY)