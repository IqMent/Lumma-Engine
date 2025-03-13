#include "sha256.h"
#include <iostream>
#include <iomanip>

int main() {
    Crypto::SHA256 sha256;
    std::string data = "Hello World";

    std::vector<u_int8_t> result = sha256.make_sha256(&data);

    for (size_t i = 0; i < result.size(); i++)
        std::cout << std::hex << std::setw(2) << std::setfill('0') << (int)result[i];

    std::cout << std::endl;
    return 0;
}