#include <catch2/catch_test_macros.hpp>
#include "BaseSocket.hpp"

TEST_CASE("BaseSocket creates valid socket", "[BaseSocket]") {
    BaseSocket socket("/tmp/test_socket.sock");
    REQUIRE(socket.get_fd() >= 0);
}

