cmake_minimum_required(VERSION 3.0.0)
project(backprop_cpp VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(backprop_cpp src/main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

find_package(Eigen3)

if(TARGET Eigen3::Eigen)
   target_link_libraries(backprop_cpp Eigen3::Eigen)
endif()
