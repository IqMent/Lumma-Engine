//
// Created by iqment on 3/14/25.
//
#include "transaction.h"

Transaction::Transaction(std::vector<u_int8_t> sender, std::vector<u_int8_t> receiver, unsigned long long value,
                         std::vector<uint8_t> message, std::vector<u_int8_t> signature, unsigned long nonce,
                         unsigned long long timestamp) {
    this->sender = sender;
    this->receiver = receiver;
    this->value = value;
    this->message = message;
    this->signature = signature;
    this->nonce = nonce;
    this->timestamp = timestamp;
}

Transaction *
Transaction::make_transaction(std::vector<u_int8_t> sender, std::vector<u_int8_t> receiver, unsigned long long value,
                              std::vector<uint8_t> message, std::vector<u_int8_t> signature, unsigned long nonce,
                              unsigned long long timestamp) {
    return new Transaction(sender, receiver, value, message, signature, nonce, timestamp);
}

