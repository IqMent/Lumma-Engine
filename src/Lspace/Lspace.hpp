//
// Created by IqMent on 04.03.2025.
//

#ifndef LUMMAENGINE_LSPACE_HPP
#define LUMMAENGINE_LSPACE_HPP

#include <fstream>
#include <filesystem>
#include <unordered_map>
#include <string>
#include <vector>
#include <iomanip>
#include <sstream>

class Lspace {
public:
    static int init();
    static int save_key_pair_ed25519(unsigned char *address, unsigned char *public_key, unsigned char *private_key);
    static int save_key_pair_secp256k1(unsigned char *address, unsigned char *public_key, unsigned char *private_key);
    static std::unordered_map<std::string, std::vector<uint8_t> > get_key_pair_ed25519(unsigned char *address);
    static bool is_folder_exists(std::string path);
    static void check_and_create(std::string path);
};


#endif //LUMMAENGINE_LSPACE_HPP
