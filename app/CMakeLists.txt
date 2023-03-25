project(manager_app
    VERSION 0.0.1
    LANGUAGES CXX)

AUTO_BUILD_RESOURCES_QT5()

set(QT_COMPONENTS
    Core Widgets
    LinguistTools
    QuickWidgets
    Core
    QuickControls2)

add_executable(${PROJECT_NAME} ${CMAKE_CURRENT_LIST_DIR}/src/main.cpp)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS ${QT_COMPONENTS})
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS ${QT_COMPONENTS})

target_link_libraries(${PROJECT_NAME} PRIVATE
        Qt${QT_VERSION_MAJOR}::Widgets
        Qt${QT_VERSION_MAJOR}::QuickWidgets
        Qt${QT_VERSION_MAJOR}::Core
        Qt${QT_VERSION_MAJOR}::QuickControls2
        core
)
