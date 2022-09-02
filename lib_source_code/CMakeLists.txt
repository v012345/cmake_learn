aux_source_directory(. SRC_CODE)

# 使用 ${SRC_CODE} 生成名为 lib_add_d 的动态库
add_library(_add_d SHARED ${SRC_CODE})

# 使用 ${SRC_CODE} 生成名为 lib_add_s 的静态库
add_library(_add_s STATIC ${SRC_CODE})

# 重命名库名
set_target_properties(_add_d PROPERTIES OUTPUT_NAME "_add")
set_target_properties(_add_s PROPERTIES OUTPUT_NAME "_add")

set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)