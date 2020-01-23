cmake_minimum_required(VERSION 3.15)
project(ex4)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS -pthread)
find_package(Threads)
add_executable(ex4 main.cpp Solver.h StringReverser.cpp StringReverser.h FileCacheManager.cpp FileCacheManager.h
        CacheManager.h ClientHandler.h MySerialServer.cpp MySerialServer.h TestClientHandler.cpp TestClientHandler.h
        Server.h State.cpp State.h Point.cpp Point.h Searchable.h Searcher.h MyClientHandler.cpp MyClientHandler.h
        Solution.cpp Solution.h BestFS.cpp BestFS.h AbstSearcher.h
        MatrixProblem.cpp MatrixProblem.h BFS.cpp BFS.h OA.cpp OA.h DFS.cpp DFS.h A_star.cpp A_star.h)
target_link_libraries(ex4 ${CMAKE_THREAD_LIBS_INIT})