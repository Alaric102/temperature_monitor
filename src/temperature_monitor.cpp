#include "temperature_monitor/temperature_monitor.hpp"

#include <fstream>
#include <string>
#include <optional>

#include <thread>
#include <ratio>
#include <chrono>

static std::optional<temp_t> read_temperature(const std::string& filename)
{
  std::ifstream in(filename, std::ios_base::binary);
  if (!in.is_open()){
    return std::nullopt;
  }
  temp_t v;
  in >> v;
  in.close();
  return v;
}

void TemperatureMonitor::run()
{
  // TODO: think about std::ratio type
  const std::chrono::seconds sleep_period(static_cast<int64_t>(1.f/PARAMETERS_.frequency));
  auto loop_control = [this, &sleep_period](){
    while(!is_full()){
      this->update_history();
      std::this_thread::sleep_for(sleep_period);
    }
  };
  std::thread loop_thread(loop_control);
  loop_thread.join();
}

void TemperatureMonitor::update_history()
{
  const auto value_opt = read_temperature(PARAMETERS_.filename);
  if (!value_opt.has_value()){
    return;
  }
  history_.push_back(value_opt.value());
  if (PARAMETERS_.max_history_size < history_.size()){
    history_.pop_front();
  }
}