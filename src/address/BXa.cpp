//
// Created by IqMent on 08.04.2025.
//
#include "BXa.hpp"

BXa_standard::BXa_standard(std::string address) {
    std::unique_ptr<unsigned char []>
            checkSum(new unsigned char [SUM_BYTE]);
    std::unique_ptr<unsigned char []>
            address_bytes(new unsigned char [32]);

    this->address = "abc";
    this->encoding = HEX;
    this->version = 0x0;
    this->netWork = "mainNet";
}
