project(core)

file(GLOB_RECURSE SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
file(GLOB_RECURSE HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/*.h)

add_library(core STATIC ${HEADERS} ${SOURCES})
add_library(${PROJECT_NAMESPACE}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

set(QT_COMPONENTS
        Core Widgets
        LinguistTools
        QuickWidgets
        Core
        QuickControls2)

target_include_directories(
        ${PROJECT_NAME}
        PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/include
)
find_package(QT NAMES Qt6 Qt5 COMPONENTS Core Quick REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Quick REQUIRED)
target_link_libraries(core
  PRIVATE Qt${QT_VERSION_MAJOR}::Core)
target_link_libraries(
        ${PROJECT_NAME} PRIVATE
        ${PROJECT_NAMESPACE}::interface_plugin
        ${PROJECT_NAMESPACE}::logic_plugin
)

SET_BASE_TARGET_PROPERTIES(${PROJECT_NAME})
