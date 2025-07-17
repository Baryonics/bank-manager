#include "BaseSocket.hpp"
#include <sys/socket.h>
#include <sys/unistd.h>
#include <cstring>

BaseSocket::BaseSocket(std::string path): path_(path)
{
  fd_ = socket(AF_UNIX, SOCK_STREAM, 0);
}


BaseSocket::~BaseSocket()
{
  close(fd_);
}
