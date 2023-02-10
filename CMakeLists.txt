CMAKE_MINIMUM_REQUIRED(VERSION 3.10)

project(CNPYpp LANGUAGES CXX)

add_library(cnpy++ "src/cnpy++.cpp" "src/buffer.cpp")

find_package(libzip REQUIRED)
find_package(Boost 1.78 COMPONENTS filesystem iostreams REQUIRED)

target_compile_features(cnpy++ PUBLIC cxx_std_17)
set_property(TARGET cnpy++ PROPERTY CXX_EXTENSIONS OFF)
target_include_directories(cnpy++ PUBLIC ${Boost_INCLUDE_DIR})
target_include_directories(cnpy++ SYSTEM PUBLIC $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>)
target_include_directories(cnpy++ SYSTEM INTERFACE $<INSTALL_INTERFACE:$<INSTALL_PREFIX>/include>)
target_link_libraries(cnpy++ PRIVATE Boost::filesystem Boost::iostreams)
target_link_libraries(cnpy++ PRIVATE libzip::zip)

if(MSVC)
  target_compile_options(cnpy++ PRIVATE /W4 /WX)
else()
  target_compile_options(cnpy++ PRIVATE -Wall -Wextra -pedantic -Wfatal-errors)
endif()

install(TARGETS "cnpy++" LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
install(FILES "include/cnpy++/tuple_util.hpp"
    "include/cnpy++/stride_iterator.hpp"
    "include/cnpy++/map_type.hpp"
    "include/cnpy++/buffer.hpp" DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/cnpy++)
install(FILES "include/cnpy++.hpp" "include/cnpy++.h" DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

if (NOT hasParent)
  add_executable(example1 "examples/example1.cpp")
  target_link_libraries(example1 cnpy++)

  if (CNPYPP_USE_LIBZIP)
    add_executable(example2 "examples/example2.cpp")
    target_link_libraries(example2 cnpy++)
  endif()
endif()
