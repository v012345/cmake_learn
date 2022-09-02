## 环境
+ 平台 windows 11
+ 工具 vscode
+ 环境 MinGW
+ 其他 `cmake .. -G "MinGW Makefiles"` 都在 build 下执行 
## 定义并打印消息
```cmake 
SET(USER_VAR_HI "Hello Cmake")
MESSAGE("Say ${USER_VAR_HI}")
MESSAGE(STATUS "Say ${USER_VAR_HI}") # 会有消息前加上 --
```