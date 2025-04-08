//
// Created by IqMent on 16.03.2025.
//
#pragma once
#ifndef LUMMAENGINE_EVP_HPP
#define LUMMAENGINE_EVP_HPP

#include <sodium.h>
#include <openssl/sha.h>
#include <openssl/ecdsa.h>
#include <openssl/evp.h>
#include <vector>
#include <string>
#include <unordered_map>

typedef struct{
    std::vector<uint8_t> pubKey;
    std::vector<uint8_t> priKey;
    std::unordered_map<std::string, std::vector<uint8_t> > keys;
}   KeyPair;

namespace Crypto{
    class evp_SHA256{
    public:
        std::vector<uint8_t> vector_sha256(std::vector<uint8_t> data);
        unsigned char *sha256(const std::vector<uint8_t> data);
        unsigned char *sha256(const unsigned char *pk);
    };

    class evp_SHA512{
        std::vector<uint8_t> sha512(std::vector<uint8_t> data);
    };

    class evp_KECCAK256{
    public:
        unsigned char * keccak256(unsigned char *sha256);
    };

    class evp_ED25519{
        std::unordered_map<std::string, std::vector<uint8_t> > generate_keys();
        std::vector<uint8_t> sign(std::vector<uint8_t> message, std::vector<uint8_t> sk);
        bool verify(std::vector<uint8_t> data, std::vector<uint8_t> pk);
    };

    class evp_SECP256k1{

    };
}

#endif //LUMMAENGINE_EVP_HPP
