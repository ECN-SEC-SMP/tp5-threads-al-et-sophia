cmake_minimum_required(VERSION 3.28)

project(comp) #Modify this

set (CMAKE_CXX_STANDARD 14) #Set CPP standard

set(SOURCE_FILES main.cpp
) #Add source files here

add_executable(${PROJECT_NAME} ${SOURCE_FILES})