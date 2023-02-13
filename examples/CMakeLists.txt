project(CNPY_EXAMPLES)

add_executable(example1 "example1.cpp")
target_link_libraries(example1 cnpy++)

add_executable(example2 "example2.cpp")
target_link_libraries(example2 cnpy++)

add_executable(save "save.cpp")
target_include_directories(save PUBLIC ".")
target_link_libraries(save cnpy++ Eigen3::Eigen)

add_executable(load "load.cpp")
target_link_libraries(load cnpy++ Eigen3::Eigen)
target_include_directories(load PUBLIC ".")
