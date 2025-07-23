add_executable(common_tests
  test_base_socket.cpp
)

target_link_libraries(common_tests
  PRIVATE common Catch2::Catch2WithMain
)


include(CTest)
include(Catch)
catch_discover_tests(common_tests)


