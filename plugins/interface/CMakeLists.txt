project(
        interface_plugin
        VERSION 0.0.1
        LANGUAGES CXX
        DESCRIPTION "Interface plugin description..."
)

file(GLOB_RECURSE SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
file(GLOB_RECURSE HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/*.h)
file(GLOB_RECURSE QML_SRC ${CMAKE_CURRENT_SOURCE_DIR}/*.qml)
file(GLOB_RECURSE ASSETS ${CMAKE_CURRENT_SOURCE_DIR}/*.png)
add_custom_target(qml_src SOURCES ${QML_SRC})
add_custom_target(assets SOURCES ${ASSETS})

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

PLUGIN_METADATA_GENERATOR()

BUILD_STRUCTURING()
