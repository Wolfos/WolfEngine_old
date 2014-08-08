LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := main

SDL_PATH := ../../jni/SDL
SDL_IMAGE_PATH := ../../jni/SDL2_image
SDL_TTF_PATH := ../../jni/SDL2_ttf
SDL_MIXER_PATH := ../../jni/SDL2_mixer

LOCAL_C_INCLUDES := $(LOCAL_PATH)/$(SDL_PATH)/include \ $(LOCAL_PATH)/$(SDL_IMAGE_PATH) \ $(LOCAL_PATH)/$(SDL_TTF_PATH) \ $(LOCAL_PATH)/$(SDL_MIXER_PATH)

WOLFENGINE_FILES := WolfEngine/Main_SDL.cpp \
WolfEngine/Audio/Sound.cpp \
WolfEngine/Audio/Music.cpp \
WolfEngine/Components/Button.cpp \
WolfEngine/Components/Camera.cpp \
WolfEngine/Components/SpriteRenderer.cpp \
WolfEngine/Components/Transform.cpp \
WolfEngine/ECS/GameObject.cpp \
WolfEngine/ECS/ObjectManager.cpp \
WolfEngine/GUI/GUIBox.cpp \
WolfEngine/GUI/GUISprite.cpp \
WolfEngine/Input/Input.cpp \
WolfEngine/Models/Point.cpp \
WolfEngine/Rendering/Image.cpp \
WolfEngine/Rendering/Map.cpp \
WolfEngine/Rendering/Screen.cpp \
WolfEngine/Utilities/Debug.cpp \
WolfEngine/Utilities/Time.cpp 

# Add your application source files here...
LOCAL_SRC_FILES := $(SDL_PATH)/src/main/android/SDL_android_main.c \
	$(WOLFENGINE_FILES) \
	GameMain.cpp \
	Editor/EditorMain.cpp \
	Editor/TilePicker.cpp

LOCAL_SHARED_LIBRARIES := SDL2 SDL2_image SDL2_ttf SDL2_mixer

LOCAL_LDLIBS := -lGLESv1_CM -llog

include $(BUILD_SHARED_LIBRARY)
