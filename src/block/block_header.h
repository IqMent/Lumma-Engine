//
// Created by iqment on 3/14/25.
//
#pragma once
#ifndef LUMMAENGINE_BLOCK_HEADER_H
#define LUMMAENGINE_BLOCK_HEADER_H

#include <string>
#include <vector>

class BlockHeader{
private:
    unsigned short version;
    std::vector<u_int8_t> previous_hash;
    std::vector<u_int8_t> merkle_hash;
    unsigned long long timestamp;
    unsigned short difficult;
    unsigned long long nonce;
public:
    BlockHeader(unsigned short version, std::vector<u_int8_t> previous_hash, std::vector<u_int8_t> merkle_hash,
    unsigned long long timestamp, unsigned short difficult, unsigned long long nonce);
    ~BlockHeader();

    //Getter's
    unsigned short get_version();
    std::vector<u_int8_t> get_previous_hash();
    std::vector<u_int8_t> get_merkle_hash();
    unsigned long long get_timestamp();
    unsigned short get_difficult();
    unsigned long long get_nonce();
};

#endif //LUMMAENGINE_BLOCK_HEADER_H
