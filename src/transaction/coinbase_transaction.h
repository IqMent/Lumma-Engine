//
// Created by iqment on 3/14/25.
//

#ifndef LUMMAENGINE_COINBASE_TRANSACTION_H
#define LUMMAENGINE_COINBASE_TRANSACTION_H

#include <string>
#include <vector>
#include <cstdint>

class CoinBaseTrx{
private:
    std::vector<uint8_t> address;
    std::vector<uint8_t> message;
    unsigned long long nonce;
    unsigned long long level;
    unsigned long long reward;
public:
    CoinBaseTrx(std::vector<uint8_t> address, std::vector<uint8_t> message, unsigned long long nonce,
                unsigned long long level, unsigned long long reward);

};

#endif //LUMMAENGINE_COINBASE_TRANSACTION_H
