//
// Created by iqment on 3/9/25.
//

#ifndef LUMMAENGINE_KEY_H
#define LUMMAENGINE_KEY_H

#include <unordered_map>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
#include <cstdint>

#ifdef _WIN32
    #define PATH "pass"
#elif defined(__linux__)
    #define PATH "~/.LummaEngine/keys/"
#elif defined(__APPLE__)
    #define PATH "~/pass"
#endif

namespace Crypto{
    typedef struct{
        std::vector<uint8_t> pubKey;
        std::vector<uint8_t> privKey;
        std::vector<uint8_t> shortPubKey;
    } secp256k1_key_pair;
}

namespace Crypto{
    class secp256k1_KeyPair{
    public:
        std::unordered_map<std::string, std::vector<uint8_t>> generate_keypair(std::vector<uint8_t> seed);
        std::unordered_map<std::string, std::vector<uint8_t>> generate_keypair();
    public:
        secp256k1_key_pair *generate_keys(std::vector<uint8_t> seed);
        secp256k1_key_pair *generate_keys();
    };
}

namespace Crypto{
    class ed25519_KeyPair{
    public:
        std::unordered_map<std::string, std::vector<uint8_t>> generate_keypair(std::vector<u_int8_t> seed);
        std::unordered_map<std::string, std::vector<uint8_t>> generate_keypair();
        bool save_keypair(std::unordered_map<std::string, std::vector<uint8_t>> *kp);
    private:

    };
}

#endif //LUMMAENGINE_KEY_H
