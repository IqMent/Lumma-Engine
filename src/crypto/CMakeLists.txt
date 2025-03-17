CMAKE_MINIMUM_REQUIRED(VERSION 3.10)
project(LummaEngineCrypto)


add_subdirectory(hash)
add_subdirectory(key)
add_subdirectory(evp)
#set(SRC
#        evp/ed25519.cpp
#        evp/sha256.cpp
#        evp/sha512.cpp
#        evp/keccak256.cpp
#        evp/evp.hpp
#)

#find_package(OpenSSL REQUIRED)
#pkg_check_modules(libsodium REQUIRED libsodium)
#add_library(${PROJECT_NAME} ${SRC})
#target_link_libraries(${PROJECT_NAME} PRIVATE OpenSSL::Crypto sodium)
