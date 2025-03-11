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
        PoW/miner.h)

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




