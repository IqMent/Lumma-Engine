//
// Created by IqMent on 16.03.2025.
//

#ifndef LUMMAENGINE_EVP_HPP
#define LUMMAENGINE_EVP_HPP

#include <sodium.h>
#include <openssl/sha.h>
#include <openssl/ecdsa.h>
#include <openssl/evp.h>
#include <vector>
#include <string>
#include <unordered_map>


namespace Crypto{
    class evp_SHA256{
        std::vector<uint8_t> sha256(std::vector<uint8_t> data);
    };

    class evp_SHA512{
        std::vector<uint8_t> sha512(std::vector<uint8_t> data);
    };

    class evp_ED25519{
        std::unordered_map<std::string, std::vector<uint8_t>> generate_keys();
        std::vector<uint8_t> sign(std::vector<uint8_t> message, std::vector<uint8_t> sk);
        bool verify(std::vector<uint8_t> data, std::vector<uint8_t> pk);
    };

    class evp_SECP256k1{

    };
}

#endif //LUMMAENGINE_EVP_HPP
