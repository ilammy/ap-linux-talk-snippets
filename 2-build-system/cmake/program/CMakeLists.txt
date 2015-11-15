project(hello C CXX)
cmake_minimum_required(VERSION 2.6)

add_executable(hello
	main.c
	hello.cpp
)
