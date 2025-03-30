//
// Created by iqment on 3/9/25.
//

#ifndef LUMMAENGINE_UTILS_H
#define LUMMAENGINE_UTILS_H
#include <cstdint>
#include <string>
#include <vector>
#include <fstream>



namespace Utils{
    class BinaryConvertor{
    public:
        std::string bn_2_str(std::vector<uint8_t> data, size_t size);
        unsigned long long bn_2_ull(std::vector<uint8_t> data, size_t size);
        unsigned long bn_2_ul(std::vector<uint8_t> data, size_t size);
        long long bn_2_ll(std::vector<uint8_t> data, size_t size);
        long bn_2_l(std::vector<uint8_t> data, size_t size);

        std::vector<uint8_t> str_2_bn(std::string data);
        std::vector<uint8_t> ull_2_bn(unsigned long long data);
        std::vector<uint8_t> ul_2_bn(unsigned long data);
        std::vector<uint8_t> ll_2_bn(long long data);
        std::vector<uint8_t> l_2_bn(long data);
    };
    class Reader{
    public:
        std::vector<uint8_t> readECseckey(const std::string path);
        std::vector<uint8_t> readECpubkey(const std::string path);
    };
}


#endif //LUMMAENGINE_UTILS_H
