//
// Created by iqment on 3/9/25.
//

#include "address.h"


std::vector<u_int8_t> Address::Stage0::get_address_from_bn(unsigned char *pk) {
    std::vector<uint8_t> address;
    Crypto::evp_SHA256 sha256;
    unsigned char *sha256_address = sha256.sha256(pk);
    Crypto::evp_KECCAK256 keccak256;
    unsigned char *keccak256_address = keccak256.keccak256(sha256_address);
    for (int i = 0; i < 32; i++) {
        address.push_back(keccak256_address[i]);
    }
    delete sha256_address;
    delete keccak256_address;
    return address;
}

std::vector<unsigned char> Address::Address::make_address(const unsigned char *pk, size_t pk_size) {
    std::vector<unsigned char> *address;


}