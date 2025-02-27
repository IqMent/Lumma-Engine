CMAKE_MINIMUM_REQUIRED(VERSION 3.10)
project(LummaEngine)

set(SRC
    main.cpp)

find_package(OpenSSL REQUIRED)

add_executable(${PROJECT_NAME} ${SRC})
target_link_libraries(${PROJECT_NAME} OpenSSL::Crypto)

