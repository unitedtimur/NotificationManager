project(manager_app
    VERSION 0.1
    LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(QT_COMPONENTS
    Core Widgets
    LinguistTools
    QuickWidgets
    Core
    QuickControls2)

set(HEADERS ...)

set(SOURCES ...)

set(UI_FILES ...)

set(RESOURCES ...)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS ${QT_COMPONENTS})
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS ${QT_COMPONENTS})

add_executable(${PROJECT_NAME}
    ${HEADERS}
    ${SOURCES}
    ${UI_FILES}
    ${RESOURCES}
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::QuickWidgets
    Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::QuickControls2
    notification_manager::core
)
