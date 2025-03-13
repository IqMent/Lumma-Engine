//
// Created by iqment on 3/14/25.
//

#include "sha512.h"

std::vector<uint8_t> Crypto::SHA512::make_sha512(std::string *data) {
    unsigned char hash[64];
    sha512_context ctx;
    sha512_init(&ctx);
    sha512_update(&ctx, reinterpret_cast<const unsigned char *>(data->c_str()), data->size());
    sha512_final(&ctx, hash);
    return std::vector<u_int8_t>(hash, hash + 64);
}