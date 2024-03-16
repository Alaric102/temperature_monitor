#pragma once

#include <string>
#include <list>

using temp_t = size_t;

class TemperatureMonitor {
public:
  struct Parameters {
    size_t max_history_size = 100u;
  };

public:
  TemperatureMonitor() = default;

  explicit TemperatureMonitor(const TemperatureMonitor::Parameters& parameters);

  bool update(const std::string& filename);

private:
  const Parameters PARAMETERS_;
  std::list <temp_t> history_;
};