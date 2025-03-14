//
// Created by iqment on 3/14/25.
//

#ifndef LUMMAENGINE_OUT_FORMAT_H
#define LUMMAENGINE_OUT_FORMAT_H

#include "block/Block.hpp"
#include "hex.h"
#include "base58.h"
#include "base64.h"
#include <iostream>
#include <iomanip>


namespace Out_format{
class BlockPrint: protected Block::Block{
    public:
        void print_block(Block *block);

    };

class TransactionPrint:
}

#endif //LUMMAENGINE_OUT_FORMAT_H
