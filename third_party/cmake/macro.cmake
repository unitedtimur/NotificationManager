macro(PARSE_SUBDIRECTORIES)
    foreach(arg IN ITEMS ${ARGN})
        add_subdirectory(${arg})
    endforeach()
endmacro()

macro(AUTO_BUILD_RESOURCES_QT5)
    set(CMAKE_AUTOMOC ON)
    set(CMAKE_AUTORCC ON)
    set(CMAKE_AUTOUIC ON)
endmacro()

macro(SET_BASE_TARGET_PROPERTIES target)
    set_target_properties(
            ${target} PROPERTIES
            CXX_STANDARD 20
            CXX_STANDARD_REQUIRED ON
    )
endmacro()

macro(FIND_AND_LINK_QT)
    # say that we want to find a Qt6 or Qt5 package
    find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS ${ARGV})

    # say that we need such components from the found package
    find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS ${ARGV})
    foreach(component IN ITEMS ${ARGV})
        target_link_libraries(
                ${PROJECT_NAME}
                PRIVATE
                Qt${QT_VERSION_MAJOR}::${component}
        )
    endforeach()
endmacro()
