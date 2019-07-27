cmake_minimum_required(VERSION 2.8)

project(eigen)

set(CMAKE_BUILD_TYPE "Debug")
include_directories(/usr/local/Cellar/eigen/3.3.7/include/eigen3/)

add_executable(eigen_matrix eigenMatrix.cpp)
add_executable(use_geometry useGeometry.cpp)