project(logic_plugin)

set(HEADERS ${CMAKE_CURRENT_LIST_DIR}/include/logic.h)
set(SOURCES ${CMAKE_CURRENT_LIST_DIR}/src/logic.cpp)

add_library(
        logic_plugin
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
