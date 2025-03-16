CMAKE_MINIMUM_REQUIRED(VERSION 3.10)
#CMAKE_LANGUAGE(CXX)
project(LummaEngineHash)
SET(CMAKE_CXX_STANDARD 17)
set(SRC
        sha256/sha256.cpp
        sha256/Lsha256.cpp
        sha512/Lsha512.cpp
        sha512/fixedint.h
        sha512/sha512.cpp
        sha512/sha512.h
        ripemd160/memzero.c
        ripemd160/memzero.h
        ripemd160/ripemd160.cpp
        ripemd160/Lripemd160.cpp
)

add_library(${PROJECT_NAME} ${SRC})