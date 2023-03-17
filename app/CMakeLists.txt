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

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS ${QT_COMPONENTS})
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS ${QT_COMPONENTS})

INCLUDE_SOURCES(${PROJECT_NAME} DIR src)

if (WIN32)
    list(APPEND SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/resources.rc")
endif()

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

INSTALL_PREFIX(TARGET_NAME ${PROJECT_NAME} CATEGORY binary)

if(WIN32)
    set_target_properties(${PROJECT_NAME} PROPERTIES WIN32_EXECUTABLE TRUE)
endif()
