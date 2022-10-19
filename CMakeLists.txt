cmake_minimum_required(VERSION 3.23)
project(HW5)

set(CMAKE_CXX_STANDARD 23)

add_executable(HW5 main.cpp
                stack.h
                queue.h
                exam.h
                exam.cpp
        binary_search_tree.h)
