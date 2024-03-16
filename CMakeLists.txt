cmake_minimum_required(VERSION 3.10)
project(temperature_monitor)

set (CMAKE_CXX_STANDARD 17)

file(GLOB SOURCES "src/*.cpp")

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} 
  PRIVATE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

# target_link_libraries(${PROJECT_NAME}
#   PRIVATE
# )