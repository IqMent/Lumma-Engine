CMAKE_MINIMUM_REQUIRED(VERSION 3.10)
#CMAKE_LANGUAGE(CXX)
project(LummaEngineHash)
set(SRC
        sha256/sha256.cpp
        sha256/Lsha256.cpp
)

add_library(${PROJECT_NAME} ${SRC})