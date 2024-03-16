#include "temperature_monitor.hpp"

#include <iostream>
#include <fstream>
#include <string>

TemperatureMonitor::TemperatureMonitor()
{
}

TemperatureMonitor::~TemperatureMonitor()
{
}

void TemperatureMonitor::read_temperature(const std::string& filename) const
{
  std::ifstream in(filename, std::ios_base::binary);
  if (!in.is_open()){
    std::cout << "Can't open file: " << filename << std::endl;
  }
  unsigned long v;
  in >> v;
  std::cout << "Readen: " << v << std::endl;
}
