cmake_minimum_required(VERSION 2.8.9)
project(cv)

set(CMAKE_CXX_STANDARD 17)

enable_testing()

include_directories(src)

add_subdirectory(tst)
add_subdirectory(src)
#add_subdirectory(lib/googletest)
