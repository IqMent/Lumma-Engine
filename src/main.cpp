//
// Created by IqMent on 26.02.2025.
//
#include <iostream>
#include <string>
#include <cassert>
//#include "crypto/hash/sha256/sha256.h"
#include <vector>
#include <iomanip>
#include <cstring>
//#include "crypto/hash/sha512/sha512.h"
#include "crypto/key/secp256k1/include/secp256k1.h"
#include "crypto/key/secp256k1/include/secp256k1_extrakeys.h"
#include "crypto//key/secp256k1/include/secp256k1_ecdh.h"

#include "crypto/key/ed25519/ed25519.h"

#include <sodium.h>

//int main()
//{
//    Crypto::SHA256 sha256;
//    std::string str = "Hello World!";
//    std::vector<uint8_t> result = sha256.make_sha256(&str);
//    std::cout << "\nSHA256: " << std::endl;
//    for (size_t i=0; i < 32; i++)
//        std::cout << std::hex << std::setw(2) << std::setfill('0') << (int)result.at(i);
//    Crypto::SHA512 sha512;
//    std::vector<uint8_t> result512 = sha512.make_sha512(&str);
//    std::cout << "\nSHA512: " << std::endl;
//    for(size_t i=0; i<64; i++)
//        std::cout << std::hex << std::setw(2) << std::setfill('0') << (int)result512.at(i);
//    unsigned char priv_key[64];
//    secp256k1_context *ctx = secp256k1_context_create(SECP256K1_CONTEXT_SIGN);
//
//
//    unsigned char privkey[32];
//    FILE *frand = fopen("/dev/urandom", "r");
//    fread(privkey, 1, 32, frand);
//    fclose(frand);
//    if (!secp256k1_ec_seckey_verify(ctx, privkey)) {
//        printf("Error\n");
//        return 1;
//    }
//    secp256k1_pubkey pubkey;
//    if (!secp256k1_ec_pubkey_create(ctx, &pubkey, privkey)) {
//        printf("Error\n");
//        return 1;
//    }
//
//    unsigned char pubkey_serialized[33];
//    size_t pubkey_len = sizeof(pubkey_serialized);
//    secp256k1_ec_pubkey_serialize(ctx, pubkey_serialized, &pubkey_len, &pubkey, SECP256K1_EC_COMPRESSED);
//    printf("\n");
//    printf("Priv key secp256k1: ");
//    for (int i = 0; i < 32; i++) printf("%02X", privkey[i]);
//    printf("\n");
//
//    printf("Pub (short) secp256k1: ");
//    for (int i = 0; i < 33; i++) printf("%02x", pubkey_serialized[i]);
//    printf("\n");
//    secp256k1_context_destroy(ctx);
//
//    unsigned char public_key[32], private_key[64], /*seed[32],*/ scalar[32];
//    unsigned char other_public_key[32], other_private_key[64];
//    unsigned char shared_secret[32], other_shared_secret[32];
//    unsigned char signature[64];
//
//    clock_t start;
//    clock_t end;
//    int i;
//
//    const unsigned char message[] = "Hello, world!";
//    const int message_len = strlen((char*) message);
//
//    /* create a random seed, and a keypair out of that seed */
//    //ed25519_create_seed(seed);
//        unsigned char seed[32] = {
//                0x9F, 0x3A, 0x8F, 0x3A, 0x56, 0x12, 0x7D, 0x9F, 0xB0,
//                0x34, 0xA8, 0x2C, 0xFA, 0x1B, 0x17, 0xA6, 0x80, 0x99,
//                0xF2, 0xD4, 0x15, 0x6A, 0x4F, 0x31, 0xC1, 0xF3, 0x2B,
//                0x4F, 0xBA, 0xB3, 0xA9, 0xC4
//        };
//    ed25519_create_keypair(public_key, private_key, seed);
//
//    std::cout << "Priv ed25519: \n";
//    for(size_t i=0; i<64; i++)
//        std::cout << std::hex << std::setfill('0') << std::setw(2) << (int)private_key[i];
//    std::cout << "\nPub ed25519: \n";
//
//    for(size_t i=0; i <32; i++)
//        std::cout <<  std::hex << std::setfill('0') << std::setw(2) << (int)public_key[i];
//
//
//    //crypto_sign_ed25519_seed_keypair(public_key, private_key, seed);
//    crypto_sign_ed25519_keypair(public_key, private_key);
//
//    std::cout << std::endl;
//    std::cout << "Private key (ed25519): \n";
//    for (int i = 0; i < crypto_sign_SECRETKEYBYTES; i++) {
//        printf("%02x", private_key[i]);
//    }
//    std::cout << std::endl;
//
//    std::cout << "Public key (ed25519): \n";
//    for (int i = 0; i < crypto_sign_PUBLICKEYBYTES; i++) {
//        printf("%02x", public_key[i]);
//    }
//    std::cout << std::endl;
//
//    return 0;
//}

#include "crypto/key/lumma_ed25519.hpp"

//int main() {
//    unsigned char public_key[32], private_key[64], seed[32], scalar[32];
//    unsigned char other_public_key[32], other_private_key[64];
//    unsigned char shared_secret[32], other_shared_secret[32];
//    unsigned char signature[64];
//
//    clock_t start;
//    clock_t end;
//    int i;
//
//    const unsigned char message[] = "Hello, world!";
//    const int message_len = strlen((char *) message);
//
//    /* create a random seed, and a keypair out of that seed */
//    ed25519_create_seed(seed);
//    ed25519_create_keypair(public_key, private_key, seed);
//    printf("Seed: \n");
//    for (auto i=0;i<32;i++)
//        //printf("%d", seed[i]);
//        printf("%02x", seed[i]);
//    printf("\nPrivate key ed22519: \n");
//    for (auto i=0; i<64; i++)
//        printf("%02x", private_key[i]);
//    printf("\nPublic key ed22519: \n");
//    for (auto i=0; i< 32; i++)
//        printf("%02x", public_key[i]);
//    crypto_sign_ed25519_seed_keypair(public_key, private_key, seed);
//
//    std::cout << std::endl;
//    std::cout << "Private key (ed25519): \n";
//    for (int i = 0; i < crypto_sign_SECRETKEYBYTES; i++) {
//        printf("%02x", private_key[i]);
//    }
//    std::cout << std::endl;
//
//    std::cout << "Public key (ed25519): \n";
//    for (int i = 0; i < crypto_sign_PUBLICKEYBYTES; i++) {
//        printf("%02x", public_key[i]);
//    }
//    std::cout << std::endl;
//    Crypto::ED25519 ed25519;
//
//    printf("\n\nMy version of rand bytes: \n");
//    unsigned char *rndb;
//    rndb = ed25519.get_random_bytes();
//    for (size_t i=0 ;i<32; i++)
//        printf("%d", rndb[i]);
//    printf("\n");
//    return 0;
//}

#include "Lspace/Lspace.hpp"
#include "block/genesis_block.h"
#include "crypto/evp/evp.hpp"
#include "address/address.h"

int main(){
    Lspace::init();
    GenesisBlock genesisBlock;
    //unsigned char address[32];
    unsigned char pk[32];
    unsigned char sk[64];

    crypto_sign_ed25519_keypair(pk, sk);
    std::cout << "Private key (ed25519): \n";
    for (int i = 0; i < crypto_sign_SECRETKEYBYTES; i++) {
        printf("%02x", sk[i]);
    }
    std::cout << "\n\nPublic key (ed25519): \n";
    for (int i = 0; i < crypto_sign_PUBLICKEYBYTES; i++){
        printf("%02x", pk[i]);
    }
    std::cout << std::endl;
    std::cout << "Address: " << std::endl;
    unsigned char data[] = { 0x86, 0xb5, 0x20, 0xbe, 0x86, 0x67, 0x94, 0x78, 0x15, 0x36, 0xbf, 0x41, 0x6d, 0x9d, 0x11, 0x4f, 0x7f, 0x1e, 0xe1, 0x93, 0x67, 0x8a, 0x71, 0x9d, 0x4b, 0x42, 0xc4, 0x57, 0x02, 0xa1, 0xa1, 0x75 };

    auto address = Address::Stage0::get_address_from_bn(data);

    for (size_t i=0; i<32; i++)
        printf("%02x", address[i]);
    std::cout << std::endl;
    return (0);
}