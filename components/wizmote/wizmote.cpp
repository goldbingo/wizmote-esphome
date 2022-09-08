#include "wizmote.h"

namespace esphome {
namespace wizmote {
void WizMoteListener::on_esp_now_message(esp_now::ESPNowPacket packet) {
  
  static const char *const TAG = "wizmote";
  
  WizMotePacket wizmote = WizMotePacket::build(packet);
  if (wizmote.sequence <= this->last_sequence_
    return;
  
  this->last_sequence_ = wizmote.sequence;
  this->on_button_->trigger(wizmote);
}
}  // namespace wizmote
}  // namespace esphome
