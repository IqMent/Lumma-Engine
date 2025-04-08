//
// Created by IqMent on 08.04.2025.
//
#include "evp.hpp"

#include <sodium/crypto_generichash_blake2b.h>

unsigned char *Crypto::evp_Blake2b::blake2b(unsigned char *data, size_t data_size) {
    unsigned char *blake2b = new unsigned char [32];
    crypto_generichash_blake2b(blake2b, 32, data, data_size, NULL, 0);
    return blake2b;
}