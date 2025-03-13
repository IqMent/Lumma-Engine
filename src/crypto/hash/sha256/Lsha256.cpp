//
// Created by iqment on 3/13/25.
//
#include "sha256.h"

std::vector<u_int8_t> Crypto::SHA256::make_sha256(std::string *data) {
    SHA256_CTX ctx;
    sha256_init(&ctx);
    sha256_update(&ctx, reinterpret_cast<const BYTE*>(data->c_str()), data->size());
    BYTE hash[SHA256_BLOCK_SIZE];
    sha256_final(&ctx, hash);
    return std::vector<u_int8_t>(hash, hash + SHA256_BLOCK_SIZE);
}