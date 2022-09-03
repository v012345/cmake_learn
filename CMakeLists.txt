cmake_minimum_required(VERSION 3.10)
project(MY_PROJECT)
message(STATUS ${CMAKE_SYSTEM_NAME}) # 输出平台类型
add_subdirectory(lib_source_code) # 引入目录 , 执行里面的 CMakeLists.txt
add_subdirectory(external_projects)
add_subdirectory(src)
