project(hello C CXX)
cmake_minimum_required(VERSION 2.6)

# Global configuration
# ====================

find_package(Threads REQUIRED)

set(CMAKE_C_FLAGS "-std=c99 ${CMAKE_C_FLAGS}")


# Hello library
# =============

add_library(helloer SHARED
	hello.c
)

target_link_libraries(helloer ${CMAKE_THREAD_LIBS_INIT})


# Main executable
# ===============

add_executable(hello
	main.c
)

target_link_libraries(hello helloer)
