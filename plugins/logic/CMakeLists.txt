project(logic_plugin
    VERSION 0.0.1
    LANGUAGES CXX)

INCLUDE_SOURCES(${PROJECT_NAME})

add_library(
        logic_plugin
        SHARED
        ${HEADERS}
        ${SOURCES}
)
add_library(${PROJECT_NAMESPACE}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

set_target_properties(${PROJECT_NAME}
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib
    LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib
    RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib
)

GENERATE_EXPORT_HEADERS(include)

set(QT_COMPONENTS
        Core Widgets
        QuickWidgets
        Core
        QuickControls2)

FIND_AND_LINK_QT("${QT_COMPONENTS}")

target_include_directories(
        ${PROJECT_NAME}
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

SET_BASE_TARGET_PROPERTIES(${PROJECT_NAME})

set(PROJECT_DESCRIPTION "Logic plugin description...")
configure_file(${CMAKE_SOURCE_DIR}/third_party/template_metadata.json metadata.json)

BUILD_STRUCTURING()
