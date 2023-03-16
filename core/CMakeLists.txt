add_executable(core core.cxx)

target_link_libraries(core LINK_PUBLIC interfacePlugin)
target_link_libraries(core LINK_PUBLIC logicPlugin)
target_include_directories (core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
