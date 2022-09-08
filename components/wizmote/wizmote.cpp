#include "wizmote.h"

#include "esphome/core/helpers.h"
#include "esphome/core/log.h"
#include "esphome/core/version.h"

namespace esphome {
namespace wizmote {
void WizMoteListener::on_esp_now_message(esp_now::ESPNowPacket packet) {
  
  static const char *const TAG = "wizmote";
  ESP_LOGD(TAG, "Button pressed");
  
  WizMotePacket wizmote = WizMotePacket::build(packet);
  if (wizmote.sequence <= this->last_sequence_) {
    ESP_LOGD(TAG, "Sequence rmpty");
    return;
  }
  
  ESP_LOGD(TAG, "Sequence ongoing...");
  
  this->last_sequence_ = wizmote.sequence;
  this->on_button_->trigger(wizmote);
}
}  // namespace wizmote
}  // namespace esphome
