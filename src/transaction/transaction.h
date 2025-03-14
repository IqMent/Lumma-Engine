//
// Created by iqment on 3/11/25.
//

#ifndef LUMMAENGINE_TRANSACTION_H
#define LUMMAENGINE_TRANSACTION_H

#include <string>
#include <vector>
#include <cstdint>
#include <memory>

#define FVOID 0

class Transaction{
private:
    std::vector<u_int8_t> sender;
    std::vector<u_int8_t> receiver;
    std::vector<u_int8_t> signature;
    unsigned long long value;
    unsigned long nonce;
    unsigned long long timestamp;
    std::vector<uint8_t> message;
public:
    Transaction(std::vector<u_int8_t> sender, std::vector<u_int8_t> receiver, unsigned long long value,
                std::vector<uint8_t> message, std::vector<u_int8_t> signature, unsigned long nonce,
                unsigned long long timestamp);
    ~Transaction();
    Transaction *make_transaction(std::vector<u_int8_t> sender, std::vector<u_int8_t> receiver, unsigned long long value,
                                  std::vector<uint8_t> message, std::vector<u_int8_t> signature, unsigned long nonce,
                                  unsigned long long timestamp);
    std::vector<uint8_t> sign_transaction(std::vector<uint8_t> message, std::vector<uint8_t> priv_key);
    bool verify_transaction(Transaction *trx);
    //Getter's
protected:
    std::vector<u_int8_t> get_sender();
    std::vector<u_int8_t> get_receiver();
    std::vector<u_int8_t> get_signature();
    unsigned long long get_value();
    unsigned long get_nonce();
    unsigned long long get_timestamp();
    std::vector<uint8_t> get_message();
};

#endif //LUMMAENGINE_TRANSACTION_H
