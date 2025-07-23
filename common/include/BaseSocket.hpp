#pragma once
#include <string>
#include <span>
#include <sys/socket.h>
#include <sys/un.h>

class BaseSocket 
{
  public:
    BaseSocket(std::string path);

    virtual ~BaseSocket();

    int createSocket();

    int recieve(std::span<const std::byte> buff);

    int send(std::span<std::byte> buff);


    int get_fd();

    std::string get_path();

  private:
    std::string path_;
    int fd_;
    struct sockaddr_un sa_ = {};


  protected:
    void bind();

    void listen();

    int accept();

    void close();
};
