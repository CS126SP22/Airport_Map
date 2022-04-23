cmake_minimum_required(VERSION 3.21)
project(final_project_ws9922)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(final_project_ws9922
        include/edge.h
        include/graph.h
        include/random.h
        src/graph.cpp
        src/random.cpp src/dijkstra.cpp include/dijkstra.h src/astar.cpp include/astar.h)
