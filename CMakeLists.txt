cmake_minimum_required(VERSION 3.15)
project(learn_algorithms_cpp)

set(CMAKE_CXX_STANDARD 14)

#add_executable(learn_algorithms_cpp
#        LICENSE
#        README.md)

add_subdirectory(binarytree)
add_subdirectory(measure_execution_time)
add_subdirectory(selection_sort)
add_subdirectory(bubble_sort)
add_subdirectory(insertion_sort)
add_subdirectory(quick_sort)
add_subdirectory(acmicpc)
add_subdirectory(merge_sort)