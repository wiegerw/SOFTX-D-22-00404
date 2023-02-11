CMAKE_MINIMUM_REQUIRED(VERSION 3.10)
project(CNPYpp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(libzip REQUIRED)

include_directories(include)

add_library(cnpy++ "src/cnpy++.cpp" "src/buffer.cpp")
target_link_libraries(cnpy++ PRIVATE libzip::zip)

add_executable(example1 "examples/example1.cpp")
target_link_libraries(example1 cnpy++)

add_executable(example2 "examples/example2.cpp")
target_link_libraries(example2 cnpy++)
