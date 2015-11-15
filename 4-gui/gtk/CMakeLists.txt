project(example C)
cmake_minimum_required(VERSION 2.6)

add_executable(example main.c)

find_package(GTK2 2.6 REQUIRED gtk)
include_directories(${GTK2_INCLUDE_DIRS})
target_link_libraries(example ${GTK2_LIBRARIES})
