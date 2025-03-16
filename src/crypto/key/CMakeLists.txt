cmake_minimum_required(VERSION 3.10)
project(LummaEngineKeyED25519)

set(SRC
        ed25519/add_scalar.c
        ed25519/fe.c
        ed25519/ge.c
        ed25519/key_exchange.c
        ed25519/keypair.c
        ed25519/sc.c
        ed25519/seed.c
        ed25519/sha512.c
        ed25519/sign.c
        ed25519/verify.c
        randb.cpp
)
add_subdirectory(secp256k1)

add_library(${PROJECT_NAME} ${SRC})