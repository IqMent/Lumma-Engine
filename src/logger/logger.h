//
// Created by iqment on 3/15/25.
//
// Logger structure
#ifndef LUMMAENGINE_LOGGER_H
#define LUMMAENGINE_LOGGER_H

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
#include <unordered_map>
#include <thread>
#include <mutex>

#ifdef _WIN32
    #define PATH "pass"
#elif defined(__linux__)
    #define PATH "~/.LummaEngine/logs/"
#elif defined(__APPLE__)
    #define PATH "~/pass"
#endif
static class Logger{
private:
    static std::string level;

public:
    static void logger_init(std::string logger_level);
    static void debug_log(std::unordered_map<std::string, std::unordered_map<std::string, std::vector<uint8_t>>> &data);
};

#endif //LUMMAENGINE_LOGGER_H
