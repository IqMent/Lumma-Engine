CMAKE_MINIMUM_REQUIRED(VERSION 3.10)
project(LummaEngine)

set(SRC
        main.cpp
        block/finder/finder.hpp
        LVM/lvm.cpp
        LVM/lvm.h
        address/address.cpp
        address/address.h
        utils/utils.h
        utils/convertor/binary_convertor.cpp
        wallet/wallet.h
        smart_contract/sc.h
        node/dns/dns_node.cpp
        node/dns/dns_node.h
        node/node.h
        crypto/key/key.h
        crypto/signature/signature.h
        bench/sign_transaction.cpp
        network/Network.cpp
        network/Network.h
        PoS/validator.h
        PoW/miner.h
        transaction/transaction.h
        cfg/config_manager.h
        cfg/init.h
        requests/requests.h
        requests/price/price.h
        hex.h
        base64.h
        base58.h
        crypto/key/secp256k1.h
        crypto/key/eddsa25519.h
        crypto/key/secp256k1_recovery.h
        crypto/hash/sha512/sha512.h
        crypto/hash/sha256/sha256.h
        crypto/hash/ripemd160/ripemd160.h
        crypto/hash/keccak256/keccak256.h
        crypto/hash/blake2b/blake2b.h
        crypto/hash/hash.cpp
)

if(CMAKE_SYSTEM_NAME STREQUAL "Darwin")
#    set(SODIUM_ROOT_DIR "/usr/local/opt/libsodium")
#    set(CMAKE_PREFIX_PATH ${SODIUM_ROOT_DIR})
#    set(CMAKE_LIBRARY_PATH ${SODIUM_ROOT_DIR}/lib)
#    set(CMAKE_INCLUDE_PATH ${SODIUM_ROOT_DIR}/include)
#    find_package(OpenSSL REQUIRED)
#    pkg_check_modules(libsodium REQUIRED libsodium)
#    include_directories(${SODIUM_INCLUDE_DIRS})
    set(SODIUM_ROOT_DIR "/usr/local/opt/libsodium")
    set(CMAKE_PREFIX_PATH ${SODIUM_ROOT_DIR})
    set(CMAKE_LIBRARY_PATH ${SODIUM_ROOT_DIR}/lib)
    set(CMAKE_INCLUDE_PATH ${SODIUM_ROOT_DIR}/include)

    find_package(OpenSSL REQUIRED)
    pkg_check_modules(libsodium REQUIRED libsodium)

    include_directories(${libsodium_INCLUDE_DIRS})
    link_directories(${libsodium_LIBRARY_DIRS})


    add_executable(${PROJECT_NAME} ${SRC})
    target_include_directories(${PROJECT_NAME} PRIVATE ${libsodium_INCLUDE_DIRS})
    target_link_libraries(${PROJECT_NAME} OpenSSL::Crypto ${libsodium_LIBRARIES})
endif ()

if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    set(SODIUM_DIR "/usr/local/include")
    find_package(OpenSSL REQUIRED)
    pkg_check_modules(libsodium REQUIRED libsodium)
    include_directories(${SODIUM_DIR})

    add_executable(${PROJECT_NAME} ${SRC})
    #target_link_directories(${PROJECT_NAME} PRIVATE ${SODIUM_DIR})
    target_include_directories(${PROJECT_NAME} PRIVATE ${SODIUM_DIR})
    target_link_libraries(${PROJECT_NAME} OpenSSL::Crypto "/usr/local/lib/libsodium.a")

endif ()




