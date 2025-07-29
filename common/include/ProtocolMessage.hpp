#pragma once

#include "nlohmann/json.hpp"
#include "AccountHolder.hpp"
enum class MessageType
{
  WITHDRAW,
  DEPOSIT,
  TRANSFER
};

class ProtocolMessage {
  public:
    ProtocolMessage(
      MessageType type,
      float amount,
      AccountHolder sender,
      AccountHolder rec
    );
};
