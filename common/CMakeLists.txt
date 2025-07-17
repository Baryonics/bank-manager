cmake_minimum_required(VERSION 3.28.1)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_LIBRARY_OUTPUT_DIRECTORY/lib})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY/lib})
add_library(common STATIC
  src/BaseSocket.cpp
  src/ProtocolParser.cpp
  src/ProtocolMessage.cpp
  include/Utils.hpp
)

target_include_directories(common PUBLIC
  include
)

