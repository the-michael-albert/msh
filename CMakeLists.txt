cmake_minimum_required(VERSION 3.28)
project(msh)

set(CMAKE_CXX_STANDARD 11)

add_executable(msh main.cpp
        command.cpp
        command.h
        log.h
)
