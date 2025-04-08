//
// Created by IqMent on 04.03.2025.
//

#include "Lspace.hpp"
#include <iostream>

int Lspace::init() {
#ifdef __APPLE__
    std::string base_path = std::getenv("HOME");
    base_path += "/.LummaEngine";
    std::string keys_path = base_path + "/keys";


#endif
#ifdef __linux__

    std::filesystem::path base_path = std::filesystem::path(std::getenv("HOME")) /  ".LummaEngine";
    if(std::filesystem::exists(base_path)){
        std::cout << "Directory already inited!" << std::endl;
        return 1;
    }
    std::filesystem::create_directories(base_path / "keys");
    std::filesystem::create_directories(base_path / "blockChain");
    std::filesystem::create_directories(base_path / "peers");
    std::filesystem::create_directories(base_path / "config");
    std::cout << "Directories succeeded created!" << std::endl;
#endif
    return 0;
}