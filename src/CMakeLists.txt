CMAKE_MINIMUM_REQUIRED(VERSION 3.10)
project(LummaEngine)


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
endif ()

set(SRC
    main.cpp)


add_executable(${PROJECT_NAME} ${SRC})
target_include_directories(${PROJECT_NAME} PRIVATE ${libsodium_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} OpenSSL::Crypto ${libsodium_LIBRARIES})


