project(cmake_learn)
SET(USER_VAR_HI "Hello Cmake")
MESSAGE("Say ${USER_VAR_HI}")
MESSAGE(STATUS "Say ${USER_VAR_HI}") # 会有消息前加上 --
add_executable(${PROJECT_NAME} main.cpp)