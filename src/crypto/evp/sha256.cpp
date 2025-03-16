//
// Created by iqment on 3/17/25.
//

#include "evp.hpp"

unsigned char *Crypto::evp_SHA256::sha256(std::vector<uint8_t> data) {
    unsigned char *hash = new unsigned char[SHA256_DIGEST_LENGTH];
    SHA256_CTX ctx;
    SHA256_Init(&ctx);
    SHA256_Update(&ctx, data.data(), data.size());
    SHA256_Final(hash, &ctx);
    return hash;
}

