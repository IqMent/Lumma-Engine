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

int main()
{
    Crypto::SHA256 sha256;
    std::string str = "Hello World!";
    std::vector<uint8_t> result = sha256.make_sha256(&str);
    for (size_t i=0; i < 32; i++)
        std::cout << std::hex << std::setw(2) << std::setfill('0') << (int)result.at(i);
    return 0;
}

