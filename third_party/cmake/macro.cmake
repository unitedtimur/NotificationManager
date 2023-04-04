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

# Макрос ищет указанные в аргументах компоненты QT линкует их с таргетом
macro(FIND_AND_LINK_QT)
    # Ищем пакеты Qt6 или Qt5
    find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS ${ARGV})

    # Ищем нужные компоненты
    find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS ${ARGV})
    foreach(component IN ITEMS ${ARGV})
        target_link_libraries(
                ${PROJECT_NAME}
                PRIVATE
                Qt${QT_VERSION_MAJOR}::${component}
        )
    endforeach()
endmacro()

# Макрос ищет все исходники в проекте и формирует группу из них
macro(INCLUDE_SOURCES NAME)
    set(_OPTIONS_ARGS NOT_RECURSIVE)
    set(_ONE_VALUE_ARGS DIR)
    set(_MULTI_VALUE_ARGS EXCLUDE_LIST)

    cmake_parse_arguments(_INCLUDE_SOURCES
        "${_OPTIONS_ARGS}"
        "${_ONE_VALUE_ARGS}"
        "${_MULTI_VALUE_ARGS}"
        ${ARGN})

    if (NOT _INCLUDE_SOURCES_DIR)
        set(_INCLUDE_SOURCES_DIR ${CMAKE_CURRENT_SOURCE_DIR})
    endif()

    if (_INCLUDE_SOURCES_NOT_RECURSIVE)
        set(RECURSIVE_FLAG GLOB)
    else()
        set(RECURSIVE_FLAG GLOB_RECURSE)
    endif()

    # Ищем исходники в подпроекте, исходя из переменной DIR
    file(${RECURSIVE_FLAG} HEADERS ${_INCLUDE_SOURCES_DIR}/*.h)
    file(${RECURSIVE_FLAG} SOURCES ${_INCLUDE_SOURCES_DIR}/*.cpp *.cc)
    file(${RECURSIVE_FLAG} RESOURCES ${_INCLUDE_SOURCES_DIR}/*.qrc)
    file(${RECURSIVE_FLAG} MANIFESTS ${_INCLUDE_SOURCES_DIR}/*.rc README.txt)
    file(${RECURSIVE_FLAG} METADATA ${_INCLUDE_SOURCES_DIR}/*.json README.txt)
    file(${RECURSIVE_FLAG} UI_FILES ${_INCLUDE_SOURCES_DIR}/*.ui)

    # Исключаем файлы, которые были переданы в EXCLUDE_LIST
    foreach(EXCLUDE_FILE ${_INCLUDE_SOURCES_EXCLUDE_LIST})
        set(REGEX "^(.*)${EXCLUDE_FILE}(.*)$")
        list(FILTER HEADERS EXCLUDE REGEX ${REGEX})
        list(FILTER SOURCES EXCLUDE REGEX ${REGEX})
        list(FILTER RESOURCES EXCLUDE REGEX ${REGEX})
        list(FILTER MANIFESTS EXCLUDE REGEX ${REGEX})
        list(FILTER METADATA EXCLUDE REGEX ${REGEX})
        list(FILTER UI_FILES EXCLUDE REGEX ${REGEX})
    endforeach()

    # Выделяем группу исходников (для отображения в IDE)
    source_group("Header Files" FILES ${HEADERS})
    source_group("Source Files" FILES ${SOURCES})
    source_group("Resources" FILES ${RESOURCES})
    source_group("Manifests" FILES ${MANIFESTS})
    source_group("Proto Files" FILES ${PROTOS})
    source_group("Metadata Files" FILES ${METADATA})
    source_group("UI Files" FILES ${UI_FILES})

    message(STATUS "CONFIGURED SOURCES FOR ${NAME}")
endmacro()

# Макрос формирует структуру файлов в билд папке
macro(BUILD_STRUCTURING)
    foreach(file IN ITEMS ${HEADERS})
        file(COPY ${file} DESTINATION ${PROJECT_BINARY_DIR}/include)
    endforeach()

    foreach(file IN ITEMS ${SOURCES})
        file(COPY ${file} DESTINATION ${PROJECT_BINARY_DIR}/src)
    endforeach()

    file(GLOB RM_FILES ${PROJECT_BINARY_DIR}/*.dll *.dll.a *.h *.cpp *.cc)
    file(REMOVE "${RM_FILES}")
endmacro()

# Макрос генерирует заголовочные файлы экспорта и добаляет их в указанную
# директорию
macro(GENERATE_EXPORT_HEADERS dir)
    include(GenerateExportHeader)
    generate_export_header(${PROJECT_NAME})
    file(COPY ${PROJECT_BINARY_DIR}/${PROJECT_NAME}_export.h
            DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/${dir})
    file(COPY ${PROJECT_BINARY_DIR}/${PROJECT_NAME}_export.h
            DESTINATION ${PROJECT_BINARY_DIR}/${dir})
    file(REMOVE ${PROJECT_BINARY_DIR}/${PROJECT_NAME}_export.h)
endmacro()