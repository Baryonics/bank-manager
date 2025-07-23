#include "BaseSocket.hpp"
#include <sys/socket.h>
#include <sys/unistd.h>
#include <cstring>
#include <stdexcept>

BaseSocket::BaseSocket(std::string path) : path_(std::move(path)) {
    fd_ = socket(AF_UNIX, SOCK_STREAM, 0);
    if (fd_ < 0) {
        throw std::runtime_error("Socket creation failed");
    }

    sa_.sun_family = AF_UNIX;
    if (path_.size() >= sizeof(sa_.sun_path)) {
        throw std::runtime_error("Socket path too long");
    }

    std::strncpy(sa_.sun_path, path_.c_str(), sizeof(sa_.sun_path) - 1);
}

BaseSocket::~BaseSocket()
{
  close(fd_); // ... Not done
}
