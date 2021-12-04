#include <string>
#include <cerrno>
#include <cassert>

#include <EGL/egl.h>
#include <GLES/gl.h>

#include <android/sensor.h>
#include <android/log.h>
#include <dlfcn.h>


#include <jni.h>
#include <poll.h>
#include <pthread.h>
#include <sched.h>
#include <android/configuration.h>
#include <cstdlib>
#include <cstring>
#include <android/looper.h>
#include <android/native_activity.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <android/log.h>

#define LOGI(...) ((void)__android_log_print(ANDROID_LOG_INFO, "lf5", __VA_ARGS__))
#define LOGE(...) ((void)__android_log_print(ANDROID_LOG_ERROR, "lf5", __VA_ARGS__))

/* For debug builds, always enable the debug traces in this library */
#ifndef NDEBUG
#  define LOGV(...)  ((void)__android_log_print(ANDROID_LOG_VERBOSE, "lf5", __VA_ARGS__))
#else
#  define LOGV(...)  ((void)0)
#endif

JNIEXPORT
void ANativeActivity_onCreate(ANativeActivity* activity, void* savedState, size_t savedStateSize) {
    LOGV("NativeActivity on create from c code: %p", activity);
    std::string game_lib_name = "lf5_android_core";
    char* game_lib_name_charptr = const_cast<char*>(game_lib_name.c_str());

    void* game_entry_mobule  = dlopen(game_lib_name_charptr,RTLD_LAZY);
    if ((game_entry_mobule) == NULL){
      LOGE("not find ");
    }
    //activity->callbacks->onConfigurationChanged = onConfigurationChanged;
    //activity->callbacks->onContentRectChanged = onContentRectChanged;
    //activity->callbacks->onDestroy = onDestroy;
    //activity->callbacks->onInputQueueCreated = onInputQueueCreated;
    //activity->callbacks->onInputQueueDestroyed = onInputQueueDestroyed;
    //activity->callbacks->onLowMemory = onLowMemory;
    //activity->callbacks->onNativeWindowCreated = onNativeWindowCreated;
    //activity->callbacks->onNativeWindowDestroyed = onNativeWindowDestroyed;
    //activity->callbacks->onNativeWindowRedrawNeeded = onNativeWindowRedrawNeeded;
    //activity->callbacks->onNativeWindowResized = onNativeWindowResized;
    //activity->callbacks->onPause = onPause;
    //activity->callbacks->onResume = onResume;
    //activity->callbacks->onSaveInstanceState = onSaveInstanceState;
    //activity->callbacks->onStart = onStart;
    //activity->callbacks->onStop = onStop;
    //activity->callbacks->onWindowFocusChanged = onWindowFocusChanged;

    //activity->instance = android_app_create(activity, savedState, savedStateSize);
}
