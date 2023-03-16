cmake_minimum_required(VERSION 3.14)

project(NotificationManager
    VERSION 0.1
    DESCRIPTION ""
    LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(core)
add_subdirectory(logicPlugin)
add_subdirectory(interfacePlugin)
