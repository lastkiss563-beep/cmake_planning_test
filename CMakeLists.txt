cmake_minimum_required(VERSION 4.2.1)
project(planning)
set(CMAKE_CXX_STANDARD 17)
#把动态库和exe放在同一个bin目录下，变量和目录设置
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
#CMAKE_LIBRARY_OUTPUT_DIRECTORY 用于linux设置动态库的输出目录
#CMAKE_ARCHIVE_OUTPUT_DIRECTORY 用于设置静态库的输出目录,不输出exe文件
#生成动态库
aux_source_directory(${PROJECT_SOURCE_DIR}/src SRC_LISTS)
add_library(common
SHARED
${SRC_LISTS}
)
#动态库包含头文件目录
target_include_directories(common
PUBLIC
${PROJECT_SOURCE_DIR}/include
)

#生成可执行文件
add_executable(planning_main planning_main.cpp)

#exe包含头文件目录
target_include_directories(planning_main
PUBLIC
${PROJECT_SOURCE_DIR}/include
)
#exe链接动态库
target_link_libraries(planning_main
PUBLIC
common
)