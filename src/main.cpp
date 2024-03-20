#include "temperature_monitor.hpp"

#include <iostream>
#include <string_view>
#include <filesystem>

namespace fs = std::filesystem;

constexpr std::string_view THERMAL_ZONES_FOLDER = "/sys/class/thermal";
constexpr std::string_view THERMAL_ZONE_FILE = "thermal_zone0";
constexpr std::string_view TEMPERATURE_FIELD = "temp";

static void print_temperatures(const TemperatureMonitor& monitor){
  std::cout << "Data: ";
  for (const auto& value : monitor){
    std::cout << cast(value) << " ";
  }
  std::cout << std::endl;
}

int main(int argc, char** argv){
  const auto filename = (fs::path(THERMAL_ZONES_FOLDER) / THERMAL_ZONE_FILE / TEMPERATURE_FIELD).string();

  TemperatureMonitor::Parameters parameters = {1000u};
  TemperatureMonitor monitor(parameters);
  while (!monitor.is_full()){
    monitor.update(filename);
  }
  print_temperatures(monitor);
  
  return 0;
}