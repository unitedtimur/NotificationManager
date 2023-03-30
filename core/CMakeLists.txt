project(core)

INCLUDE_SOURCES(${PROJECT_NAME})

add_library(core STATIC ${HEADERS} ${SOURCES})
add_library(${PROJECT_NAMESPACE}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

include(GenerateExportHeader)
generate_export_header(${PROJECT_NAME})
file(COPY ${PROJECT_BINARY_DIR}/${PROJECT_NAME}_export.h
        DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/include)

set(QT_COMPONENTS
        Core Widgets
        QuickWidgets
        Core
        QuickControls2)

target_include_directories(
        ${PROJECT_NAME}
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

FIND_AND_LINK_QT("${QT_COMPONENTS}")

SET_BASE_TARGET_PROPERTIES(${PROJECT_NAME})
