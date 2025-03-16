cmake_minimum_required(VERSION 3.10)
project(LummaEngineLspace)

set(SRC
        Lspace.cpp
)


add_library(${PROJECT_NAME} ${SRC})