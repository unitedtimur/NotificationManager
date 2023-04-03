project(common)

file(GLOB_RECURSE SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
file(GLOB_RECURSE HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/*.h)
AUTO_BUILD_RESOURCES_QT5()
add_library(
        common
        SHARED
        ${HEADERS}
        ${SOURCES}
)
add_library(${PROJECT_NAMESPACE}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})
set(QT_COMPONENTS
        Core Widgets
        QuickWidgets
        Core
        QuickControls2)
FIND_AND_LINK_QT("${QT_COMPONENTS}")
target_include_directories(
        ${PROJECT_NAME}
        PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/include
)
SET_BASE_TARGET_PROPERTIES(${PROJECT_NAME})
