//
// Created by iqment on 3/17/25.
//

#include "../Lspace.hpp"

int Lspace::save_key_pair_ed25519(unsigned char *address, unsigned char *public_key, unsigned char *private_key) {
    std::filesystem::path base_path = std::filesystem::path(std::getenv("HOME")) / ".LummaEngine" / "keys";
    std::stringstream ss_address;
    for (size_t i=0; i<32; i++){
        ss_address << std::hex << std::setfill('0') << std::setw(2) << (int)address[i];
    }
    if(!std::filesystem::exists(base_path / ss_address.str())){
        std::filesystem::create_directories(base_path / ss_address.str());
    }
//    std::stringstream ss_public_key;
//    std::stringstream ss_private_key;
//    for(size_t i=0; i < 32; i++){ //ed25519 sk is 64 bytes, first 32 - seed, second public key!
//        ss_public_key << std::hex << std::setfill('0') << std::setw(2) << (int)public_key[i];
//        ss_private_key << std::hex << std::setfill('0') << std::setw(2) << (int)private_key[i];
//    }
    std::ofstream pub_key_file(base_path / ss_address.str() / "public_key.bin", std::ios::binary);
    pub_key_file.write((char *)public_key, 32);
    pub_key_file.close();
    std::ofstream private_key_file(base_path / ss_address.str() / "private_key.bin", std::ios::binary);
    private_key_file.write((char *)private_key, 64);
    private_key_file.close();
    return (0);
}