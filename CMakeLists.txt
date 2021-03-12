cmake_minimum_required(VERSION 3.17)
project(Puncturable_PRF)

set(CMAKE_CXX_STANDARD 14)
FIND_PACKAGE(OpenSSL REQUIRED)

add_executable(main main.cpp GGMNode.h GGMTree.cpp GGMTree.h Utils.c Utils.h)

TARGET_LINK_LIBRARIES(main OpenSSL::Crypto)