project(core)

set(HEADERS ${CMAKE_CURRENT_LIST_DIR}/include/core.h)
set(SOURCES ${CMAKE_CURRENT_LIST_DIR}/src/core.cpp)

add_library(
        core
        STATIC
        ${HEADERS}
        ${SOURCES}
)

set_target_properties(
        core PROPERTIES
        CXX_STANDARD 20
        CXX_STANDARD_REQUIRED ON
)