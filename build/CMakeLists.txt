cmake_minimum_required(VERSION 3.16)

#project name
PROJECT(cpp)

SET(SRC_LIST ../src/dijkstra.cpp)

#add executable file
ADD_EXECUTABLE(${PROJECT_NAME} ${SRC_LIST})
