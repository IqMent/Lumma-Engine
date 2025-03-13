/*********************************************************************
* Filename:   sha256.h
* Author:     Brad Conte (brad AT bradconte.com)
* Copyright:
* Disclaimer: This code is presented "as is" without any guarantees.
* Details:    Defines the API for the corresponding SHA1 implementation.
*********************************************************************/

#ifndef SHA256_H
#define SHA256_H

extern "C" {
/*************************** HEADER FILES ***************************/
#include <stddef.h>

/****************************** MACROS ******************************/
#define SHA256_BLOCK_SIZE 32            // SHA256 outputs a 32 byte digest

/**************************** DATA TYPES ****************************/
typedef unsigned char BYTE;             // 8-bit byte
typedef unsigned int WORD;             // 32-bit word, change to "long" for 16-bit machines

typedef struct {
    BYTE data[64];
    WORD datalen;
    unsigned long long bitlen;
    WORD state[8];
} SHA256_CTX;

/*********************** FUNCTION DECLARATIONS **********************/
void sha256_init(SHA256_CTX *ctx);
void sha256_update(SHA256_CTX *ctx, const BYTE data[], size_t len);
void sha256_final(SHA256_CTX *ctx, BYTE hash[]);
}
#include <vector>
#include <string>

namespace Crypto{
    class SHA256{
        public:
        std::vector<u_int8_t> make_sha256(std::string *data);
        std::vector<u_int8_t> *make_sha256(std::vector<u_int8_t> *data);
        std::vector<u_int8_t> *make_sha256(unsigned long long data);
        std::vector<u_int8_t> *make_sha256(unsigned long data);
        std::vector<u_int8_t> *make_sha256(long long data);
        std::vector<u_int8_t> *make_sha256(long data);
    };
}
#endif   // SHA256_H