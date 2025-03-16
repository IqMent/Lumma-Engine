//
// Created by IqMent on 16.03.2025.
//


#include "lumma_ed25519.hpp"

#include <fstream>
#include <memory>
unsigned char *Crypto::ED25519::get_randb() {
    unsigned char *randb = new unsigned char [32];
#ifdef __APPLE__
    FILE *f = fopen("/dev/urandom", "rb");
    fread(randb, 1, 32, f);
    fclose(f);
    return (randb);
#endif
    return nullptr;
}

unsigned char *Crypto::ED25519::get_random_bytes() {
    Crypto::ED25519 ed25519;
    return ed25519.get_randb();
}