project(core)

set(HEADERS ${CMAKE_CURRENT_LIST_DIR}/include/core.h)
set(SOURCES ${CMAKE_CURRENT_LIST_DIR}/src/core.cpp)

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

FIND_AND_LINK_QT()
target_link_libraries(
        ${PROJECT_NAME} PRIVATE
        ${PROJECT_NAMESPACE}::interface_plugin
        ${PROJECT_NAMESPACE}::logic_plugin
)

SET_BASE_TARGET_PROPERTIES(${PROJECT_NAME})
