#pragma once

#include <string>
#include <list>

typedef size_t temp_t;
typedef float celsius_t;

static constexpr celsius_t CELSIUS_DIGITS = 1e+3;

inline celsius_t cast(const temp_t value) {
  return static_cast<celsius_t>(value)/CELSIUS_DIGITS;
}

class TemperatureMonitor {
public:
  struct Parameters {
    size_t max_history_size = 100u;
    float frequency = 1.f;
    std::string filename = "";
    bool is_verbose = true;
  };

public:
  explicit TemperatureMonitor(const TemperatureMonitor::Parameters& parameters): PARAMETERS_(parameters) {};

  void update_history();

  void run();

  const std::list<temp_t>::const_iterator begin() const noexcept {return history_.begin(); };
  
  const std::list<temp_t>::const_iterator end() const noexcept {return history_.end(); };

  const temp_t back() const noexcept { return history_.back(); };

  size_t size() const noexcept { return history_.size(); };
  
  bool is_full() const noexcept { return history_.size() >= PARAMETERS_.max_history_size; };

private:

  const Parameters PARAMETERS_;
  std::list <temp_t> history_;
  const float v = static_cast<float>(0u);
};