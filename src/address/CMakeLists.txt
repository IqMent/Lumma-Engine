cmake_minimum_required(VERSION 3.10)
project(LummaEngineAddress)


set(SRC
        address.cpp
)

add_library(${PROJECT_NAME} ${SRC})
target_link_libraries(${PROJECT_NAME} LummaEngineCryptoEVP)