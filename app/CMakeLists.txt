project(manager_app
    VERSION 0.0.1
    LANGUAGES CXX)

# add CMAKE_AUTOMOC, CMAKE_AUTORCC, CMAKE_AUTOUIC
AUTO_BUILD_RESOURCES_QT5()

set(QT_COMPONENTS
    Core Widgets
    LinguistTools
    QuickWidgets
    Core
    QuickControls2)

add_executable(${PROJECT_NAME} ${CMAKE_CURRENT_LIST_DIR}/src/main.cpp)

FIND_AND_LINK_QT()
target_link_libraries(
        ${PROJECT_NAME}
        PRIVATE
        ${PROJECT_NAMESPACE}::core
)

SET_BASE_TARGET_PROPERTIES(${PROJECT_NAME})