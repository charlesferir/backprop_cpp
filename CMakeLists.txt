cmake_minimum_required(VERSION 3.0.0)
project(backprop_cpp VERSION 0.1.0)

add_executable(backprop_cpp src/main.cpp)
set_property(TARGET backprop_cpp PROPERTY CXX_STANDARD 17)

find_package(Eigen3 REQUIRED)
find_package(cxxopts REQUIRED)
find_package(spdlog REQUIRED)

target_link_libraries(backprop_cpp 
    Eigen3::Eigen cxxopts::cxxopts spdlog::spdlog
)
