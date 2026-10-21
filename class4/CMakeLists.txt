cmake_minimum_required(VERSION 3.16)
project(jena_roi_demo)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(PkgConfig REQUIRED)
pkg_check_modules(OPENCV REQUIRED opencv4)

include_directories(${OPENCV_INCLUDE_DIRS})
link_directories(${OPENCV_LIBRARY_DIRS})

add_executable(homework main.cpp)
target_link_libraries(homework ${OPENCV_LIBRARIES})