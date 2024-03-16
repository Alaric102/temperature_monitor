#include "temperature_monitor.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <optional>

static std::optional<temp_t> read_temperature(const std::string& filename)
{
  std::ifstream in(filename, std::ios_base::binary);
  if (!in.is_open()){
    std::cout << "Can't open file: " << filename << std::endl;
    return std::nullopt;
  }
  temp_t v;
  in >> v;
  return v;
}

TemperatureMonitor::TemperatureMonitor(const TemperatureMonitor::Parameters& parameters)
: PARAMETERS_(parameters)
{
}

bool TemperatureMonitor::update(const std::string& filename)
{
  const auto value = read_temperature(filename);
  if (value.has_value()){
    history_.emplace_back(value.value());
    if (history_.size() > PARAMETERS_.max_history_size){
      history_.pop_front();
    }
    return true;
  }
  return false;
}