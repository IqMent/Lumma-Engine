//
// Created by IqMent on 09.03.2025.
//

#ifndef LUMMAENGINE_BLOCK_HPP
#define LUMMAENGINE_BLOCK_HPP

#include <iostream>
#include <fstream>
#include <memory>
#include <string>
#include <cstdint>
#include <vector>

namespace Block{
    class Block{
    public:
        Block(std::vector<uint8_t> block_hash, std::vector<uint8_t> previous_hash);
    };
}

#endif //LUMMAENGINE_BLOCK_HPP
