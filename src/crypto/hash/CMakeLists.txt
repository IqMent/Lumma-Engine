CMAKE_MINIMUM_REQUIRED(VERSION 3.10)
#CMAKE_LANGUAGE(CXX)
project(LummaEngineHash)
set(SRC
        sha256/sha256.cpp
        sha256/Lsha256.cpp
        sha512/Lsha512.cpp
        sha512/fixedint.h
        sha512/sha512.cpp
)

add_library(${PROJECT_NAME} ${SRC})