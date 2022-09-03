cmake_minimum_required(VERSION 3.10)
project(RecurseDir)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin) # 生成的 exe 所在的目录
add_executable(${PROJECT_NAME} main.cpp)
# target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)