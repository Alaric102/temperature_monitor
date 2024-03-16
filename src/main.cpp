#include "temperature_monitor.hpp"

constexpr std::string_view THERMAL_ZONES_FOLDER = "/sys/class/thermal";
constexpr std::string_view THERMAL_ZONE_FILE = "thermal_zone0";
constexpr std::string_view TEMPERATURE_FIELD = "temp";

int main(int argc, char** argv){
    const auto filename = (fs::path(THERMAL_ZONES_FOLDER) / THERMAL_ZONE_FILE / TEMPERATURE_FIELD).string();

    TemperatureMonitor monitor;
    monitor.read_temperature(filename);
    return 0;
}