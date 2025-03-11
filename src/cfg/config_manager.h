//
// Created by iqment on 3/11/25.
//

#pragma once
#ifndef LUMMAENGINE_CONFIG_MANAGER_H
#define LUMMAENGINE_CONFIG_MANAGER_H


#include <filesystem>
#include <fstream>
#include "init.h"
#include <string>

class ConfigManager{
private:
    std::string cgf_path;
public:
    bool save_cfg_local();
};

#endif //LUMMAENGINE_CONFIG_MANAGER_H
