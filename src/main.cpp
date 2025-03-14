//
// Created by IqMent on 26.02.2025.
//
#include <iostream>
#include <string>
#include <sodium.h>
#include <cassert>
#include "crypto/hash/sha256/sha256.h"
#include <vector>
#include <iomanip>
#include <cstring>
#include "crypto/hash/sha512/sha512.h"
#include "crypto/key/secp256k1/include/secp256k1.h"
#include "crypto/key/secp256k1/include/secp256k1_extrakeys.h"
#include "crypto//key/secp256k1/include/secp256k1_ecdh.h"

#include "crypto/key/ed25519/ed25519.h"

int main()
{

    Crypto::SHA256 sha256;
    std::string str = "Hello World!";
    std::vector<uint8_t> result = sha256.make_sha256(&str);
    std::cout << "\nSHA256: " << std::endl;
    for (size_t i=0; i < 32; i++)
        std::cout << std::hex << std::setw(2) << std::setfill('0') << (int)result.at(i);
    Crypto::SHA512 sha512;
    std::vector<uint8_t> result512 = sha512.make_sha512(&str);
    std::cout << "\nSHA512: " << std::endl;
    for(size_t i=0; i<64; i++)
        std::cout << std::hex << std::setw(2) << std::setfill('0') << (int)result512.at(i);
    unsigned char priv_key[64];
    secp256k1_context *ctx = secp256k1_context_create(SECP256K1_CONTEXT_SIGN);


    unsigned char privkey[32];
    FILE *frand = fopen("/dev/urandom", "r");
    fread(privkey, 1, 32, frand);
    fclose(frand);
    if (!secp256k1_ec_seckey_verify(ctx, privkey)) {
        printf("Error\n");
        return 1;
    }
    secp256k1_pubkey pubkey;
    if (!secp256k1_ec_pubkey_create(ctx, &pubkey, privkey)) {
        printf("Error\n");
        return 1;
    }

    unsigned char pubkey_serialized[33];
    size_t pubkey_len = sizeof(pubkey_serialized);
    secp256k1_ec_pubkey_serialize(ctx, pubkey_serialized, &pubkey_len, &pubkey, SECP256K1_EC_COMPRESSED);
    printf("\n");
    printf("Priv key secp256k1: ");
    for (int i = 0; i < 32; i++) printf("%02x", privkey[i]);
    printf("\n");

    printf("Pub (short) secp256k1: ");
    for (int i = 0; i < 33; i++) printf("%02x", pubkey_serialized[i]);
    printf("\n");
    secp256k1_context_destroy(ctx);

    unsigned char public_key[32], private_key[64], seed[32], scalar[32];
    unsigned char other_public_key[32], other_private_key[64];
    unsigned char shared_secret[32], other_shared_secret[32];
    unsigned char signature[64];

    clock_t start;
    clock_t end;
    int i;

    const unsigned char message[] = "Hello, world!";
    const int message_len = strlen((char*) message);

    /* create a random seed, and a keypair out of that seed */
    ed25519_create_seed(seed);
    ed25519_create_keypair(public_key, private_key, seed);

    std::cout << "Priv ed25519: \n";
    for(size_t i=0; i<64; i++)
        std::cout << std::hex << std::setfill('0') << std::setw(2) << (int)privkey[i];
    std::cout << "\nPub ed25519: \n";
    for(size_t i=0; i <32; i++)
        std::cout << std::hex << std::setfill('0') << std::setw(2) << (int)public_key[i];
    std::cout << std::endl;

    return 0;
}

