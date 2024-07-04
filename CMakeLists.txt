cmake_minimum_required(VERSION 3.5.0)
project(leet-code-tests VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_subdirectory(coin_sort)
add_subdirectory(move_to_front)
add_subdirectory(min_max_sum)
add_subdirectory(diamond_pattern)
add_subdirectory(reverse_linked_list)
add_subdirectory(hash)
