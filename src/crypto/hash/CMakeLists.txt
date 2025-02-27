CMAKE_MINIMUM_REQUIRED(VERSION 3.10)
project(EngineHash)

SRC(Hash.cpp)

find_package(OpenSSL REQUIRED)

add_library(${PROJECT_NAME} ${SRC})
target_link_libraries(${PROJECT_NAME} OpenSSL::Crypto)