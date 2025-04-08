//
// Created by IqMent on 04.03.2025.
//

#include "Lspace.hpp"
#include <iostream>
#include <sys/stat.h>

using std::string;
using std::stringstream;

bool Lspace::is_folder_exists(std::string path) {
#ifdef __APPLE__
    struct stat info;
    return (stat(path.c_str(), &info) == 0 && S_ISDIR(info.st_mode));
#endif
#ifdef __linux__
    return true;
#endif
#ifdef __WIN32__
    return true;
#endif
}


void Lspace::check_and_create(std::string path) {
    size_t current_pos = path.size();
    std::string current_folder;
    char *folder_ptr;
    // /home/bla1/bla2/bla3
    while (current_pos > 0){

    }
}

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