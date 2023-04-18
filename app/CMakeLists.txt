project(manager_app
    VERSION 0.0.1
    LANGUAGES CXX)

# add CMAKE_AUTOMOC, CMAKE_AUTORCC, CMAKE_AUTOUIC
AUTO_BUILD_RESOURCES_QT5()

INCLUDE_SOURCES(${PROJECT_NAME})

set(QT_COMPONENTS
    Core Widgets
    QuickWidgets
    Core
    QuickControls2)

add_executable(${PROJECT_NAME}
    ${HEADERS}
    ${SOURCES}
    ${RESOURCES})

FIND_AND_LINK_QT(
    TARGET
    ${PROJECT_NAME}
    QT_COMPONENTS
    ${QT_COMPONENTS})

target_include_directories(
        ${PROJECT_NAME}
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(${PROJECT_NAME}
        PRIVATE
        ${PROJECT_NAMESPACE}::core
)

SET_BASE_TARGET_PROPERTIES(${PROJECT_NAME})
