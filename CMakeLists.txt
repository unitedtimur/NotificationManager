cmake_minimum_required(VERSION 3.24.2)

project(NotificationManager
    VERSION 0.1
    DESCRIPTION ""
    LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt5 REQUIRED COMPONENTS Widgets Quick)

add_subdirectory(app)
add_subdirectory(core)
add_subdirectory(plugins)
add_subdirectory(third_party)
add_subdirectory(translations)
