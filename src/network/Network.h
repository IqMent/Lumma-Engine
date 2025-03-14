//
// Created by iqment on 3/11/25.
//

#ifndef LUMMAENGINE_NETWORK_H
#define LUMMAENGINE_NETWORK_H

#ifdef _WIN32
    #define PORT "pass"
#elif defined(__linux__)
    #define PORT 7499
#elif defined(__APPLE__)
    #define PORT "pass"
#endif

#define PORT 7499
#include <unordered_map>
#include <mutex>
#include <thread>

extern "C"{
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <limits.h>
};

#endif //LUMMAENGINE_NETWORK_H
