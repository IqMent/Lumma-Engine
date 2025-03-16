//
// Created by iqment on 3/17/25.
//
#include "evp.hpp"

std::unordered_map<std::string, std::vector<uint8_t>> Crypto::evp_ED25519::generate_keys() {
    std::vector<unsigned char> pk(crypto_sign_PUBLICKEYBYTES);
    std::vector<unsigned char> sk(crypto_sign_SECRETKEYBYTES);
    std::unordered_map<std::string, std::vector<uint8_t>> keys;
    crypto_sign_ed25519_keypair(pk.data(), sk.data());
    keys["public_key"] = pk;
    keys["private_key"] = sk;
    return keys;
}