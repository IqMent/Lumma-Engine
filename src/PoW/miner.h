//
// Created by iqment on 3/11/25.
//

#pragma once

#ifndef LUMMAENGINE_MINER_H
#define LUMMAENGINE_MINER_H


#include "../node/node.h"
#include "../block/Block.hpp"
#include <sodium.h>
#include <sodium/crypto_sign_ed25519.h>
#include <sodium/crypto_core_ed25519.h>
#include <sodium/crypto_scalarmult_ed25519.h>
#include <vector>
#include <string>

#define SYMBOL 0
#define BGN 0ULL

typedef unsigned long long nonce;

class Miner: protected Node{
private:
    std::vector<uint8_t> empty;

public:
    nonce work_2_block(Block::Block *block);
};

#endif //LUMMAENGINE_MINER_H
