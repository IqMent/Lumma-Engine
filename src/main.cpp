//
// Created by IqMent on 26.02.2025.
//
#include <iostream>
#include <string>
#include <sodium.h>
#include <cassert>
#include "crypto/hash/sha256/sha256.h"
#include <vector>
#include <iomanip>
#include "crypto/hash/sha512/sha512.h"
int main()
{
    Crypto::SHA256 sha256;
    std::string str = "Hello World!";
    std::vector<uint8_t> result = sha256.make_sha256(&str);
    std::cout << "\nSHA256: " << std::endl;
    for (size_t i=0; i < 32; i++)
        std::cout << std::hex << std::setw(2) << std::setfill('0') << (int)result.at(i);
    Crypto::SHA512 sha512;
    std::vector<uint8_t> result512 = sha512.make_sha512(&str);
    std::cout << "\nSHA512: " << std::endl;
    for(size_t i=0; i<64; i++)
        std::cout << std::hex << std::setw(2) << std::setfill('0') << (int)result512.at(i);

    return 0;
}

