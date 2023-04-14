project(
        logic_plugin
        VERSION 0.0.1
        LANGUAGES CXX
        DESCRIPTION "Logic plugin description..."
)

PLUGIN_METADATA_GENERATOR(
    ${PROJECT_NAME}
    NAME logic_plugin
    VERSION 0.0.1
)

INCLUDE_SOURCES(${PROJECT_NAME})

message("Path to ${PROJECT_NAME} metadata: ${METADATA}")

add_library(
        logic_plugin
        SHARED
        ${HEADERS}
        ${SOURCES}
        ${METADATA}
)
add_library(${PROJECT_NAMESPACE}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

set_target_properties(${PROJECT_NAME}
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/plugins
)

GENERATE_EXPORT_HEADERS(TARGET ${PROJECT_NAME} DIR include)

set(QT_COMPONENTS
        Core Widgets
        QuickWidgets
        Core
        QuickControls2)

FIND_AND_LINK_QT(TARGET
    ${PROJECT_NAME}
    QT_COMPONENTS
    ${QT_COMPONENTS})

target_include_directories(
        ${PROJECT_NAME}
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(
        ${PROJECT_NAME}
        PRIVATE
        ${PROJECT_NAMESPACE}::core
)

SET_BASE_TARGET_PROPERTIES(${PROJECT_NAME})

