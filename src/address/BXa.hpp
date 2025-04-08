//
// Created by IqMent on 07.04.2025.
//

#ifndef LUMMAENGINE_BXA_HPP
#define LUMMAENGINE_BXA_HPP

#include <string>
#include <vector>
#include <memory>

#define SUM_BYTE 4
#define NETWORK_BYTE 3

typedef enum {
    HEX,
    BASE58,
    BASE64,
}   address_encoding;

class BXa_standard{
private:
    std::string address;
    unsigned short version;
    std::string netWork;
    address_encoding encoding;
    std::unique_ptr<unsigned char []> address_bytes;
    std::unique_ptr<unsigned char []> checkSum;
public:
    BXa_standard(std::string address);
    ~BXa_standard();
    std::string get_address();
    std::string get_netWork();
    std::string get_version();
    std::unique_ptr<unsigned char []> get_address_bytes();
    std::unique_ptr<unsigned char []> get_checkSum();
    std::string get_address_base58();
    std::string get_address_base64();
    std::string get_address_hex();
};

class BXa: public BXa_standard{
private:
    BXa_standard bXaStandard;
public:
    static bool check_sum(std::string address);
    BXa(std::string address);
};

#endif //LUMMAENGINE_BXA_HPP
