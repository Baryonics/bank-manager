#pragma once

#include <string>
#include <array>

constexpr std::size_t ACC_NUM_LEN = 8;

class AccountHolder
{
  public:
    AccountHolder(std::string firstName, std::string lastName);


  private:
    int accountNumber_;
    void genAccountNumber();
    std::string firstName_;
    std::string lastName_;
};
