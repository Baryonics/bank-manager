add_library(finance_system STATIC
  src/AccountManager.cpp
  src/Database.cpp
  src/SocketServer.cpp
)

target_include_directories(finance_system PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(finance_system PRIVATE common)

add_executable(bankd src/main.cpp)
target_link_libraries(bankd PRIVATE finance_system)

