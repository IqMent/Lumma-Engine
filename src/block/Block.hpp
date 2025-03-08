//
// Created by IqMent on 09.03.2025.
//
#pragma once
#ifndef LUMMAENGINE_BLOCK_HPP
#define LUMMAENGINE_BLOCK_HPP

#include <iostream>
#include <fstream>
#include <memory>
#include <string>
#include <cstdint>
#include <vector>
#include <ctime>

namespace Block{
    class Block{
    public:
        Block(unsigned long index, std::vector<uint8_t> block_hash, std::vector<uint8_t> previous_hash,
              std::vector<uint8_t> sender, std::vector<uint8_t> receiver, unsigned long long value,
              std::vector<uint8_t> message, uint64_t timestamp);
        ~Block();
    protected:
        unsigned long get_index();
        std::vector<uint8_t> get_block_hash();
        std::vector<uint8_t> get_previous_hash();
        std::vector<uint8_t> get_sender();
        std::vector<uint8_t> get_receiver();
        unsigned long long get_value();
        std::vector<uint8_t> get_message();
        uint64_t get_timestamp();
    };
}

#endif //LUMMAENGINE_BLOCK_HPP
