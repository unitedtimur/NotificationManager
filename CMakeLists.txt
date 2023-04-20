cmake_minimum_required(VERSION 3.24)

project(notification_manager
    VERSION 0.0.1
    LANGUAGES CXX)

set(PROJECT_NAMESPACE notification_manager)

include(${CMAKE_CURRENT_SOURCE_DIR}/third_party/cmake/base.cmake)

AUTO_BUILD_RESOURCES_QT5()

file(
    COPY ${CMAKE_PREFIX_PATH}/qml
    DESTINATION ${CMAKE_BINARY_DIR}/install-root
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

PARSE_SUBDIRECTORIES(
    app
    core
    plugins
    translations)
