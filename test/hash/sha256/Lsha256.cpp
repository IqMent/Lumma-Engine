//
// Created by iqment on 3/13/25.
//
#include "sha256.h"

std::vector<u_int8_t> *Crypto::SHA256::make_sha256(std::vector<u_int8_t> *data) {
    size_t  size = data->size();
    BYTE new_data[size];
    std::vector<unsigned char> *result = new std::vector<unsigned char>;
    for (size_t i=0; i < size; i++)
        new_data[i] = data->at(i);

    SHA256_CTX *ctx;
    sha256_init(ctx);
    sha256_update(ctx, new_data, size);
    sha256_final(ctx, new_data);
    for (size_t i=0; i<size; i++)
        result->at(i) = new_data[i];
    return result;
}


std::vector<u_int8_t> Crypto::SHA256::make_sha256(std::string *data) {
    SHA256_CTX ctx;
    sha256_init(&ctx);

    sha256_update(&ctx, reinterpret_cast<const BYTE*>(data->c_str()), data->size());

    BYTE hash[SHA256_BLOCK_SIZE];
    sha256_final(&ctx, hash);

    return std::vector<u_int8_t>(hash, hash + SHA256_BLOCK_SIZE);
}

// std::vector<u_int8_t> *Crypto::SHA256::make_sha256(std::string *data)
// {
//     size_t  size = data->size();
//     BYTE new_data[SHA256_BLOCK_SIZE];
//     std::vector<unsigned char> *result = new std::vector<unsigned char>;
    

//     SHA256_CTX ctx;
//     sha256_init(&ctx);
//     sha256_update(&ctx, new_data, size);
//     sha256_final(&ctx, new_data);
//     for (size_t i=0; i<size; i++)
//         result->push_back(new_data[i]);
//     return result;
// }