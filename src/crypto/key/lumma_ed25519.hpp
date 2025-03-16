//
// Created by IqMent on 16.03.2025.
//
/*  LummaEngine implementation of ed25519
 * Actually generate private, pub key,
 * Actually more generation just public key from bytes
 */


//The private key is 57 octets (456 bits, corresponding to b) of
//cryptographically secure random data.

#ifndef LUMMAENGINE_LUMMA_ED25519_HPP
#define LUMMAENGINE_LUMMA_ED25519_HPP

#include <cmath>
#include <fstream>

#define MOD(A) ((A) * (A)) // x^2 = a (mod p).  Then x is a square root.
#define CONSTANT

typedef struct{
    unsigned char seed[32];
    unsigned char pk[32];
}   lumma_ed25519_Pkey;

namespace Crypto{
    class ED25519{
    public:
        unsigned char *get_random_bytes();
        unsigned char *generate_keypair(unsigned char *seed);
        unsigned char *generate_keypair();

    private:
        unsigned char *get_randb();
        unsigned char *secret_to_pub(unsigned char *secret);
    };
}

#endif //LUMMAENGINE_LUMMA_ED25519_HPP
