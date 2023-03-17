cmake_minimum_required(VERSION 3.24.2)

project(notification_manager)
set(PROJECT_NAMESPACE notification_manager)

include(${CMAKE_CURRENT_SOURCE_DIR}/third_party/cmake/base.cmake)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

PARSE_SUBDIRECTORIES(
    app
    core
    plugins
    translations)
