#include "ProtocolMessage.hpp"

ProtocolMessage::ProtocolMessage(
      MessageType type,
      float amount,
      AccountHolder sender,
      AccountHolder rec
    )
{
  data_ = (R"(
    {
      "m_type": type,
      "sender": sender,
      "reciever": rec,
      "amount": amount
    }
  )");
}
