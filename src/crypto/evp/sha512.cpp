//
// Created by iqment on 3/17/25.
//

#include "evp.hpp"


std::vector<uint8_t> Crypto::evp_SHA512::sha512(std::vector<uint8_t> data) {
    unsigned char hash[SHA512_DIGEST_LENGTH];
    SHA512_CTX ctx;
    SHA512_Init(&ctx);
    SHA512_Update(&ctx, data.data(), data.size());
    SHA512_Final(hash, &ctx);
    std::vector<uint8_t> result(hash, hash + SHA512_DIGEST_LENGTH);
    return result;
}