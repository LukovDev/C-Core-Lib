//
// platform.h - Модуль, определяющий платформу, на которой компилируется код.
//

#pragma once


#if defined(_WIN32) || defined(_WIN64)
    #define PLATFORM_WINDOWS 1
    #define PLATFORM_MACOS   0
    #define PLATFORM_LINUX   0
    #define PLATFORM_NAME "Windows"
#elif defined(__APPLE__) && defined(__MACH__)
    #define PLATFORM_WINDOWS 0
    #define PLATFORM_MACOS   1
    #define PLATFORM_LINUX   0
    #define PLATFORM_NAME "MacOS"
#elif defined(__linux__)
    #define PLATFORM_WINDOWS 0
    #define PLATFORM_MACOS   0
    #define PLATFORM_LINUX   1
    #define PLATFORM_NAME "Linux"
#else
    #define PLATFORM_WINDOWS 0
    #define PLATFORM_MACOS   0
    #define PLATFORM_LINUX   0
    #define PLATFORM_NAME "Unknown"
#endif
