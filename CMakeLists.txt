cmake_minimum_required(VERSION 3.15)
project(ex4)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS -pthread)
find_package(Threads)
add_executable(ex4 main.cpp Solver.h StringReverser.cpp StringReverser.h FileCacheManager.cpp FileCacheManager.h
        CacheManager.h ClientHandler.h MySerialServer.cpp MySerialServer.h MyTestClientHandler.cpp MyTestClientHandler.h
        Server.h State.cpp State.h Point.cpp Point.h Searchable.h Searcher.h MatrixProblem.cpp MatrixProblem.h)
target_link_libraries(ex4 ${CMAKE_THREAD_LIBS_INIT})