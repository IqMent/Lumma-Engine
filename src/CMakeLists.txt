CMAKE_MINIMUM_REQUIRED(VERSION 3.10)
project(LummaEngine)

set(SRC
        main.cpp
        out_format.h
        block/shasum/shasum.cpp
        block/shasum/shasum.h
        transaction/make_transaction.cpp
        transaction/sign_transaction.cpp
        transaction/validate_transaction.cpp
        transaction/secp256k1_trx/transaction_secp256k1.h
        transaction/verify_transaction.cpp
        transaction/coinbase_transaction.h
        block/block_header.h
        leveldb/leveldb_api.cpp
        leveldb/leveldb_api.h
        block/genesis_block.h
        transaction/ed25519_trx/transaction_ed25519.h
        network/ws/WebSocket.cpp
        network/ws/WebSocket.h
        network/http/HTTP.cpp
        network/http/HTTP.h
        logger/logger.h
        crypto/evp/sha256.cpp
        crypto/evp/ed25519.cpp
        crypto/evp/sha512.cpp
)

add_subdirectory(crypto/)
add_subdirectory(Lspace/)
set(CMAKE_CXX_STANDARD 17)
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
    target_link_libraries(${PROJECT_NAME} OpenSSL::Crypto ${libsodium_LIBRARIES} LummaEngineHash secp256k1 LummaEngineKeyED25519)
endif ()

if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    set(SODIUM_DIR "/usr/local/include")
    find_package(OpenSSL REQUIRED)
    pkg_check_modules(libsodium REQUIRED libsodium)
    include_directories(${SODIUM_DIR})

    add_executable(${PROJECT_NAME} ${SRC})
    #target_link_directories(${PROJECT_NAME} PRIVATE ${SODIUM_DIR})
    target_include_directories(${PROJECT_NAME} PRIVATE ${SODIUM_DIR})
    target_link_libraries(${PROJECT_NAME} OpenSSL::Crypto LummaEngineHash secp256k1 LummaEngineKeyED25519 "/usr/local/lib/libsodium.a"
    LummaEngineLspace)
    #target_link_libraries(LummaEngineHash)

endif ()




