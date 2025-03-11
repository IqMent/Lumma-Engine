//
// Created by iqment on 3/11/25.
//

#ifndef LUMMAENGINE_MINER_H
#define LUMMAENGINE_MINER_H

#include "../node/node.h"
#include <sodium.h>
#include <sodium/crypto_sign_ed25519.h>
#include <sodium/crypto_core_ed25519.h>
#include <sodium/crypto_scalarmult_ed25519.h>
#include <vector>
#include <string>

class Miner: protected Node{
private:
    std::vector<uint8_t>
};

#endif //LUMMAENGINE_MINER_H
