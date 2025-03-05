//
// Created by IqMent on 26.02.2025.
//
#include <iostream>
#include <string>
#include <sodium.h>

//int main(){
//    std::cout << "Hello, world!" << std::endl;
//    return 0;
//}
int main(void)
{
    if (sodium_init() < 0) {
    }
    return 0;
}