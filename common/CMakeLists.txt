cmake_minimum_required(VERSION 3.28.1)

set(CMAKE_CXX_STANDARD 20)


add_library(common STATIC
  src/BaseSocket.cpp
  src/ProtocolParser.cpp
  src/ProtocolMessage.cpp
  include/Utils.hpp
)

target_include_directories(common PUBLIC
  include
)

