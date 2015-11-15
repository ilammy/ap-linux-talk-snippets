project(hello C CXX)
cmake_minimum_required(VERSION 2.6)

add_library(helloer SHARED
	hello.cpp
)

add_executable(hello
	main.c
)

target_link_libraries(hello helloer)
