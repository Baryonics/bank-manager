#include "BaseSocket.hpp"
#include <sys/socket.h>
#include <sys/unistd.h>
#include <cstring>
#include <stdexcept>
#include <system_error>
#include <unistd.h>

BaseSocket::BaseSocket(std::string path) : path_(std::move(path))
{
    fd_ = socket(AF_UNIX, SOCK_STREAM, 0);

    if (fd_ < 0)
    {
      throw std::system_error(errno, std::generic_category(), "socket failed");
    }

    sa_.sun_family = AF_UNIX;

    if (path_.size() >= sizeof(sa_.sun_path))
    {
      throw std::runtime_error("Path too long");
    }

    std::strncpy(sa_.sun_path, path_.c_str(), sizeof(sa_.sun_path) - 1);
}


int BaseSocket::get_fd()
{
  return fd_;
}


std::string BaseSocket::get_path()
{
  return path_;
}


void BaseSocket::bind()
{
  if (::unlink(path_.c_str()) < 0)
  {
    throw std::system_error(errno, std::generic_category(), "unlink failed");
  }

  if (::bind(fd_, (const sockaddr*) &sa_, sizeof(sa_)) < 0)
  {
    throw std::system_error(errno, std::generic_category(), "bin failed");
  }
}


void BaseSocket::listen()
{
  if (::listen(fd_, 5) < 0) // Backlog might better be a member var
  {
    throw std::system_error(errno, std::generic_category(), "listen failed");
  }
}


int BaseSocket::accept()
{
  int clientFd = ::accept(fd_, NULL, NULL);

  if (clientFd < 0)
  {
    throw std::system_error(errno, std::generic_category(), "accept failed");
  }

  return clientFd;
}


void BaseSocket::close()
{
  if (::close(fd_) < 0)
  {
    throw std::system_error(errno, std::generic_category(), "close failed");
  }
  fd_ = -1;
}


BaseSocket::~BaseSocket()
{
  if (fd_ >= 0)
  {
    ::close(fd_);
  }
}
