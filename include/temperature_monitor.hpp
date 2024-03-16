#pragma once

#include <filesystem>

namespace fs = std::filesystem;

class TemperatureMonitor
{   
public:
    TemperatureMonitor();

    ~TemperatureMonitor();

    void read_temperature(const std::string& filename) const;
private:
};