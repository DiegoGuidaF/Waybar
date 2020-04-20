#pragma once

#include "ALabel.hpp"
#include "bar.hpp"
#include "client.hpp"

namespace waybar::modules {

class IdleInhibitor : public ALabel {
 public:
  IdleInhibitor(const std::string&, const waybar::Bar&, const Json::Value&);
  ~IdleInhibitor();
  auto update(std::string format, ALabel::args &args) -> void override;

 private:
  bool handleToggle(GdkEventButton* const& e);

  const Bar&                    bar_;
  std::string                   status_;
  struct zwp_idle_inhibitor_v1* idle_inhibitor_;
  int                           pid_;
};

}  // namespace waybar::modules
