project(interface_plugin
    VERSION 0.0.1
    LANGUAGES CXX)

INCLUDE_SOURCES(${PROJECT_NAME})

add_library(
        interface_plugin
        SHARED
        ${HEADERS}
        ${SOURCES}
)

set_target_properties(${PROJECT_NAME}
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib
    LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib
    RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib
)

add_library(${PROJECT_NAMESPACE}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

include(GenerateExportHeader)
generate_export_header(${PROJECT_NAME})
file(COPY ${PROJECT_BINARY_DIR}/${PROJECT_NAME}_export.h
        DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/include)
file(COPY ${PROJECT_BINARY_DIR}/${PROJECT_NAME}_export.h
        DESTINATION ${PROJECT_BINARY_DIR}/include)
file(REMOVE ${PROJECT_BINARY_DIR}/${PROJECT_NAME}_export.h)

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

set(PROJECT_DESCRIPTION "Interface plugin description...")
configure_file(${CMAKE_SOURCE_DIR}/third_party/template_metadata.json metadata.json)

BUILD_STRUCTURING()
