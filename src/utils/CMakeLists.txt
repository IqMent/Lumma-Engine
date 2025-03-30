cmake_minimum_required(VERSION 3.10)
project(LummaEngineUtils)

set(SRC
        read/keys/keys_reader.cpp
)

add_library(${PROJECT_NAME} ${SRC})