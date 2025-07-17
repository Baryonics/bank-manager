add_library(atm STATIC
  src/ATMController.cpp
  src/SocketClient.cpp
  src/UI.cpp
)

target_include_directories(atm PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(atm PRIVATE common)

# Optional: Executable (ATM CLI)
add_executable(atm-cli src/main.cpp)
target_link_libraries(atm-cli PRIVATE atm)

