//
// Created by iqment on 3/14/25.
//

#include "block.hpp"

Block::block::block(unsigned long index, std::vector<uint8_t> block_hash, std::vector<uint8_t> previous_hash,
                    std::vector<uint8_t> merkle_three_hash, std::vector<Transaction *> trxs,
                    unsigned long long timestamp) {
    this->index = index;
    this->block_hash = block_hash;
    this->previous_hash = previous_hash;
    this->merkle_three_hash = merkle_three_hash;
    this->trxs = trxs;
    this->timestamp = timestamp;
}

std::vector<uint8_t> Block::block::get_block_hash() {
    return this->block_hash;
}
unsigned long Block::block::get_index() {
    return this->index;
}
std::vector<uint8_t> Block::block::get_previous_hash() {
    return this->previous_hash;
}
std::vector<uint8_t> Block::block::get_merkle_three_hash() {
    return this->merkle_three_hash;
}
uint64_t Block::block::get_timestamp() {
    return this->timestamp;
}
std::vector<Transaction *> Block::block::get_trx(std::vector<uint8_t> uni_data, std::string data) {
    std::vector<Transaction *> trxs;
    return trxs;
}
Block::block::~block() {
    for (auto &trx : this->trxs) {
        delete trx;
    }
}