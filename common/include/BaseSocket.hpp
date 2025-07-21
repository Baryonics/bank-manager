#pragma once
#include <string>

class BaseSocket 
{
  public:
    /** Calls socket
     *
     */
    BaseSocket(std::string path, bool is_listening);

    /** Calls close
     *
     */
    ~BaseSocket();
    int createSocket();

    int recieve();

    int send();

  private:
    std::string path_;
    int fd_;
};
