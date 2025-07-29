#include "AccountHolder.hpp"
#include <array>


int hashFunc(char c)
{
  return int(c % 10);
}


int getIntFromArr(std::array<int, ACC_NUM_LEN> arr)
{
  int mult = 1;
  int num = 0;

  for (int a : arr)
  {
    num += a * mult;
    mult *= 10;
  }

  return num;
}


AccountHolder::AccountHolder(std::string firstName, std::string lastName):
  firstName_(std::move(firstName)),
  lastName_(std::move(lastName))
{}


void AccountHolder::genAccountNumber()
  // TODO: Check if account number is available. add one if not
  // but not here... maybe
{
  std::array<int, ACC_NUM_LEN> num;

  for (int i = 0; i <= 2; i++)
  {
    num[i] = hashFunc(firstName_[i]);
    num[i+2] = hashFunc(lastName_[i+2]);
  }
}
