//
// Created by iqment on 3/14/25.
//

#include "../crypto/hash/sha256/sha256.h"
#include "../crypto/hash/sha512/sha512.h"
#include "../crypto/key/ed25519/ed25519.h"
#include "transaction.h"
#include <iostream>


std::vector<uint8_t> Transaction::sign_transaction(std::vector<uint8_t> message, std::vector<uint8_t> priv_key) {
    
}