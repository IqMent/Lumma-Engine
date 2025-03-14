//
// Created by IqMent on 09.03.2025.
//
#pragma once
#ifndef LUMMAENGINE_BLOCK_HPP
#define LUMMAENGINE_BLOCK_HPP

#include <memory>
#include <string>
#include <cstdint>
#include <vector>
#include <ctime>

#include "../transaction/transaction.h"
#include "../transaction/coinbase_transaction.h"
#include "block_header.h"
namespace Block{
    class block{
    private:
        BlockHeader* bh;
        unsigned short trx_count;
        CoinBaseTrx *cb_trx;
        std::vector<Transaction *> trxs;
    public:
        block(unsigned long index, std::vector<uint8_t> block_hash, std::vector<uint8_t> previous_hash,
              std::vector<uint8_t> merkle_three_hash, std::vector<Transaction *> trxs, unsigned long long timestamp);
        ~block();
    protected:
        unsigned long get_index();
        std::vector<uint8_t> get_block_hash();
        std::vector<uint8_t> get_previous_hash();
        std::vector<uint8_t> get_merkle_three_hash();
        std::vector<Transaction *> get_trxs();
        std::vector<Transaction *> get_trx(std::vector<uint8_t> uni_data, std::string data);
        uint64_t get_timestamp();
    };
}

namespace Block{
    class BlockValidate{
        bool validate_block(block *block);
    };
}

#endif //LUMMAENGINE_BLOCK_HPP
