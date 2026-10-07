cmake_minimum_required(VERSION 3.10)

project(class_03)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(class_03
    main.cpp
    src/MarkerManager.cpp
)

