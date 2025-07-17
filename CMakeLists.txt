cmake_minimum_required(VERSION 3.16)
project(BankManager)
set(CMAKE_CXX_STANDARD 20)

# Setzt die Ausgabepfade für alle Targets
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_LIBRARY_OUTPUT_DIRECTORY/lib})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY/lib})

# Add subdirectories (Client & Server)
add_subdirectory(common)
add_subdirectory(finance_system)
add_subdirectory(atm)

target_link_libraries(atm-cli PUBLIC
  common
)
