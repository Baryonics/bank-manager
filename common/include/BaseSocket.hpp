#pragma once
#include <string>
#include <span>
#include <sys/socket.h>
#include <sys/un.h>

class BaseSocket 
{
  public:
    BaseSocket(std::string path);

    ~BaseSocket();
    int createSocket();

    int recieve(std::span<const std::byte> buff);

    int send(std::span<std::byte> buff);


  private:
    std::string path_;
    int fd_;
    struct sockaddr_un sa_ = {};


  protected:
    int bind();

    int listen();

    int accept();

    int close();
};
