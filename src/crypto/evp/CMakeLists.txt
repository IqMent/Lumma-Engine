cmake_minimum_required(VERSION 3.10)
project(LummaEngineCryptoEVP)

set(SRC
        keccak256.cpp
        sha512.cpp
        sha256.cpp
)

find_package(OpenSSL REQUIRED)
pkg_check_modules(libsodium REQUIRED libsodium)
add_library(${PROJECT_NAME} ${SRC})
target_link_libraries(${PROJECT_NAME} PRIVATE OpenSSL::Crypto sodium)