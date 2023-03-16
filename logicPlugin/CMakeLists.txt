add_library(logicPlugin SHARED logicplugin.cxx)

target_include_directories (logicPlugin PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
