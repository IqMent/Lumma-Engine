//
// Created by IqMent on 26.02.2025.
//

#ifndef LUMMAENGINE_HASH_HPP
#define LUMMAENGINE_HASH_HPP

#include <sodium.h>
#include <openssl/sha.h>
#include <vector>


namespace Crypto{
    class Hash{
        template<typename T>std::vector<uint8_t>sha512(T *data);
        template<typename T>std::vector<uint8_t>sha256(T *data);
        template<typename T>std::vector<uint8_t>ripemd160(T *data);
        template<typename T>std::vector<uint8_t>keccak256(T *data);
        template<typename T>std::vector<uint8_t>blake2b(T *data);
    };

}

#endif //LUMMAENGINE_HASH_HPP
