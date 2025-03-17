//
// Created by iqment on 3/9/25.
//

#ifndef LUMMAENGINE_ADDRESS_H
#define LUMMAENGINE_ADDRESS_H

#include <string>
#include <vector>
#include <cstdint>

#include "../crypto/evp/evp.hpp"

#define PREFIX 0x6c
#define ENDFIX 0x61

namespace Address{
    class Stage0{
    public:
        static std::string get_address_from_bn(std::vector<u_int8_t> bn_address);
        static std::vector<u_int8_t> get_address_from_str(std::string str_address);
        static std::vector<u_int8_t> get_address_from_bn(unsigned char *pk);
    };

    class Stage1{

    };
}


#endif //LUMMAENGINE_ADDRESS_H
