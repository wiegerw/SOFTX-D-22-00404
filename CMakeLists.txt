CMAKE_MINIMUM_REQUIRED(VERSION 3.10)

project(CNPYpp LANGUAGES CXX)

add_library(cnpy++ "src/cnpy++.cpp" "src/buffer.cpp")

find_package(libzip REQUIRED)
find_package(Boost 1.78 COMPONENTS iostreams REQUIRED)

target_compile_features(cnpy++ PUBLIC cxx_std_17)
set_property(TARGET cnpy++ PROPERTY CXX_EXTENSIONS OFF)
target_include_directories(cnpy++ PUBLIC ${Boost_INCLUDE_DIR})
target_include_directories(cnpy++ SYSTEM PUBLIC $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>)
target_include_directories(cnpy++ SYSTEM INTERFACE $<INSTALL_INTERFACE:$<INSTALL_PREFIX>/include>)
target_link_libraries(cnpy++ PRIVATE Boost::iostreams)
target_link_libraries(cnpy++ PRIVATE libzip::zip)

if(MSVC)
  target_compile_options(cnpy++ PRIVATE /W4 /WX)
else()
  target_compile_options(cnpy++ PRIVATE -Wall -Wextra -pedantic -Wfatal-errors)
endif()

add_executable(example1 "examples/example1.cpp")
target_link_libraries(example1 cnpy++)

add_executable(example2 "examples/example2.cpp")
target_link_libraries(example2 cnpy++)
