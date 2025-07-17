cmake_minimum_required(VERSION 3.28.1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/common)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/common/lib)

add_library(common STATIC
  src/BaseSocket.cpp src/ProtocolParser.cpp
  src/ProtocolMessage.cpp Utils.hpp
)

target_include_directories(common PUBLIC
  common/include
)

