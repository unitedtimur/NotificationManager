project(
        gui_plugin
        VERSION 0.0.1
        LANGUAGES CXX
)

AUTO_BUILD_RESOURCES_QT5()

PLUGIN_METADATA_GENERATOR(
    ${PROJECT_NAME}
    NAME gui_plugin
    VERSION ${CMAKE_PROJECT_VERSION}
)

INCLUDE_SOURCES(${PROJECT_NAME})

add_library(
        ${PROJECT_NAME}
        SHARED
        ${SOURCES}
        ${HEADERS}
        ${RESOURCES}
        ${METADATA}
)

if(WIN32)
    set(OS_VAR_OUTPUT_DIRECTORY RUNTIME_OUTPUT_DIRECTORY)
else()
    set(OS_VAR_OUTPUT_DIRECTORY LIBRARY_OUTPUT_DIRECTORY)
endif()

set_target_properties(${PROJECT_NAME}
    PROPERTIES
    ${OS_VAR_OUTPUT_DIRECTORY} ${CMAKE_BINARY_DIR}/install-root/plugins
)

add_library(${PROJECT_NAMESPACE}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

GENERATE_EXPORT_HEADERS(TARGET ${PROJECT_NAME} DIR include)

set(QT_COMPONENTS
        Core Widgets
        QuickWidgets
        Core
        QuickControls2
        Sql
    )

FIND_AND_LINK_QT(TARGET ${PROJECT_NAME}
    QT_COMPONENTS
    ${QT_COMPONENTS})

target_include_directories(${PROJECT_NAME}
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(${PROJECT_NAME}
        PRIVATE
        ${PROJECT_NAMESPACE}::core
        ${PROJECT_NAMESPACE}::logic_plugin
)

SET_BASE_TARGET_PROPERTIES(${PROJECT_NAME})

