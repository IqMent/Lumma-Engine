//
// Created by iqment on 3/9/25.
//

#ifndef LUMMAENGINE_WALLET_H
#define LUMMAENGINE_WALLET_H

#include <string>
#include <vector>

namespace Wallet{
    class Wallet{
    private:
        std::vector<u_int8_t> address;
        std::vector<u_int8_t> pubkey;
        unsigned long long balance;
        bool active;
    };
}

#endif //LUMMAENGINE_WALLET_H
