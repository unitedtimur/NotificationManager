project(core)

set(HEADERS ${CMAKE_CURRENT_LIST_DIR}/include/core.h)
set(SOURCES ${CMAKE_CURRENT_LIST_DIR}/src/core.cpp)

add_library(
        core
        STATIC
        ${HEADERS}
        ${SOURCES}
)

set(QT_COMPONENTS
        Core Widgets
        LinguistTools
        QuickWidgets
        Core
        QuickControls2)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS ${QT_COMPONENTS})
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS ${QT_COMPONENTS})

target_include_directories(
        ${PROJECT_NAME}
        PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/include
)

target_link_libraries(${PROJECT_NAME} PRIVATE
        Qt${QT_VERSION_MAJOR}::Widgets
        Qt${QT_VERSION_MAJOR}::QuickWidgets
        Qt${QT_VERSION_MAJOR}::Core
        Qt${QT_VERSION_MAJOR}::QuickControls2
        interface_plugin
        logic_plugin)

set_target_properties(
        core PROPERTIES
        CXX_STANDARD 20
        CXX_STANDARD_REQUIRED ON
)
