CMAKE_MINIMUM_REQUIRED(VERSION 3.16)
project(CNPYpp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(libzip REQUIRED)
find_package (Eigen3 REQUIRED NO_MODULE)

include_directories(include)

add_library(cnpy++ "src/cnpy++.cpp")
target_link_libraries(cnpy++ PRIVATE libzip::zip)

add_subdirectory(examples)
