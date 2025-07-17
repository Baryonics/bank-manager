cmake_minimum_required(VERSION 3.16)
project(MyProject)

# Setzt die Ausgabepfade für alle Targets
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY )
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY )
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY )

# Add subdirectories (Client & Server)
add_subdirectory(server)
add_subdirectory(client)

