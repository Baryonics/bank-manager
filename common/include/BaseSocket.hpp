#pragma once
#include <string>

class BaseSocket 
{
  public:
    BaseSocket(std::string path);
    ~BaseSocket();

    void recieve();
    void send();

  private:
    std::string path_;
    int fd_;
};
