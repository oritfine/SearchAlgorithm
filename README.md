# Search Algorithm
This is our second milestone of the project. Our goals are:
* Creating a *Server* according to the SOLID principles.
* Implementing *ClientHandler* class that handles clients by "translating" a client's problem to a form that our server can solve.
* Creating graph solvers to a given problem using known search algorithms.

## About The Project
 The process of the project is as follows:
 1. A client connects to the *Server*.
 2. The *Server* gets an input of the problem and pass it to the *ClientHandler* to solve.
 3. The *ClientHandler* first checks if the solution exists in the *FileCacheManager* and returns it.
 4. When there is no solution in the *FileCacheManager*, the *ClientHandler* uses the *Solver* to create one.
 5. The new solution is inserted to the cache's memory and returned to the *Server* and back to the client.

 The *Server* and *ClientHandler* don't have any information about the problem and therfore we use dependicy injection and
object adapter design patterns. Our *OA* implements the *Solver* interface and transforms the problem to a graph form 
which we can work with in the implementaion of the algorithms.

 We created two types of servers to run the program:
 1. Serial Server - can listen to multiple clients but only deals with a single problem at a time.
 2. Parallel Server - can listen to multiple clients and deals with multiple problems at a time.

## About The Algorithms
Out *OA* (object adapter) that used as a *Solver* is injected with a certain problem and certain algorithm that solves the problem.
The algorithms define the problem as reaching from the *initial state* to the *goal state* by using a *cost function* of the graph.
The algorithms implemented in our code are:
1. A Star - the algorithm used in the main program.
2. Best First Search
3. Breadth First Search
4. Depth First Search

In order to choose the best algorithm to our main program we conducted an empirical experiment that examines which algorithm have the cheapest 
cost to reach the goal state. Accroding to the conclusions ot the experiment we chose A Star to be the algorithm in the main program.
The full results and conclusions of our experiment is added as a PDF file in this repository. 
