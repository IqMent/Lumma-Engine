//
// Created by iqment on 3/9/25.
//

#ifndef LUMMAENGINE_ADDRESS_H
#define LUMMAENGINE_ADDRESS_H

#include <string>
#include <vector>
#include <cstdint>

#include "../crypto/evp/evp.hpp"

#define ADDRESS_PREFIX 0x0

// Address generation:
// Sha256(PK) -> Blake2b() -> RIPEMD160() -> BXa
// Bxa -------> version + network + prefix + address + checksum
namespace Address{
    class Stage0{
    public:
        static std::string get_address_from_bn(std::vector<u_int8_t> bn_address);
        static std::vector<u_int8_t> get_address_from_str(std::string str_address);
        static std::vector<u_int8_t> get_address_from_bn(unsigned char *pk);
        static std::unique_ptr<std::vector<unsigned char []> > make_address(const unsigned char *pk,
                                                                            size_t pk_size);
    };

    class Address{
    public:
        static std::vector<unsigned char> make_address(const unsigned char *pk,
                                                                    size_t pk_size);
    };

}


#endif //LUMMAENGINE_ADDRESS_H
