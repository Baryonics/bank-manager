#pragma once

#include "nlohmann/json.hpp"
#include "AccountHolder.hpp"
#include "nlohmann/json_fwd.hpp"

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

  private:
    nlohmann::json data_;
};
