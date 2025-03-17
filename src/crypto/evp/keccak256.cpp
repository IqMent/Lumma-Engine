//
// Created by iqment on 3/17/25.
//

#include "evp.hpp"

unsigned char *Crypto::evp_KECCAK256::keccak256(unsigned char *sha256) {
    EVP_MD_CTX *mdctx = EVP_MD_CTX_new();
    if (mdctx == nullptr) {
        return nullptr;
    }
    if (1 != EVP_DigestInit_ex(mdctx, EVP_sha3_256(), nullptr)) {
        EVP_MD_CTX_free(mdctx);
        return nullptr;
    }

    if (1 != EVP_DigestUpdate(mdctx, sha256, 32)) {
        EVP_MD_CTX_free(mdctx);
        return nullptr;
    }
    unsigned char *hash = new unsigned char[32];
    unsigned int len = 0;
    if (1 != EVP_DigestFinal_ex(mdctx, hash, &len)) {
        EVP_MD_CTX_free(mdctx);
        return nullptr;
    }

    EVP_MD_CTX_free(mdctx);
    return hash;
}