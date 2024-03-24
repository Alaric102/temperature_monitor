cmake_minimum_required(VERSION 3.10)
project(temperature_monitor)

set (CMAKE_CXX_STANDARD 17)

add_library(${PROJECT_NAME} SHARED "src/temperature_monitor.cpp")
target_include_directories(${PROJECT_NAME} 
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)
target_link_libraries(${PROJECT_NAME}
  PUBLIC
)

set_target_properties(${PROJECT_NAME} 
  PROPERTIES 
    PUBLIC_HEADER include/temperature_monitor/temperature_monitor.hpp
)

install(TARGETS ${PROJECT_NAME} EXPORT ${PROJECT_NAME}Config
  ARCHIVE  DESTINATION ${CMAKE_INSTALL_LIBDIR}
  LIBRARY  DESTINATION ${CMAKE_INSTALL_LIBDIR}
  RUNTIME  DESTINATION ${CMAKE_INSTALL_BINDIR}
)

install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME})

install(EXPORT ${PROJECT_NAME}Config DESTINATION share/${PROJECT_NAME})

# export(TARGETS ${PROJECT_NAME} FILE MyLibConfig.cmake)