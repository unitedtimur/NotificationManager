project(
        logic_plugin
        VERSION 0.0.1
        LANGUAGES CXX
)

AUTO_BUILD_RESOURCES_QT5()

PLUGIN_METADATA_GENERATOR(
    ${PROJECT_NAME}
    NAME logic_plugin
    VERSION ${CMAKE_PROJECT_VERSION}
)

INCLUDE_SOURCES(${PROJECT_NAME})

add_library(
        ${PROJECT_NAME}
        SHARED
        ${HEADERS}
        ${SOURCES}
        ${METADATA}
)

set_target_properties(${PROJECT_NAME}
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/install-root/plugins
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/install-root/plugins
)

add_library(${PROJECT_NAMESPACE}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})


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

target_include_directories(${PROJECT_NAME}
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(${PROJECT_NAME}
        PRIVATE
        ${PROJECT_NAMESPACE}::core
)

SET_BASE_TARGET_PROPERTIES(${PROJECT_NAME})

