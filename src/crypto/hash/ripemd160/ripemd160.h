//
// Created by iqment on 3/11/25.
//

#ifndef LUMMAENGINE_RIPEMD160_H
#define LUMMAENGINE_RIPEMD160_H

#include <vector>
#include <string>
#include <cstdint>

namespace Crypto{
    class RIPEMD160{
    public:
        std::vector<uint8_t> make_ripemd160(std::string *data);
    };
}

extern "C" {
#include <stdint.h>

#define RIPEMD160_BLOCK_LENGTH 64
#define RIPEMD160_DIGEST_LENGTH 20

typedef struct _RIPEMD160_CTX {
    uint32_t total[2];                      /*!< number of bytes processed  */
    uint32_t state[5];                      /*!< intermediate digest state  */
    uint8_t buffer[RIPEMD160_BLOCK_LENGTH]; /*!< data block being processed */
} RIPEMD160_CTX;

void ripemd160_Init(RIPEMD160_CTX *ctx);
void ripemd160_Update(RIPEMD160_CTX *ctx, const uint8_t *input, uint32_t ilen);
void ripemd160_Final(RIPEMD160_CTX *ctx,
                     uint8_t output[RIPEMD160_DIGEST_LENGTH]);
void ripemd160(const uint8_t *msg, uint32_t msg_len,
               uint8_t hash[RIPEMD160_DIGEST_LENGTH]);

};

#endif //LUMMAENGINE_RIPEMD160_H
