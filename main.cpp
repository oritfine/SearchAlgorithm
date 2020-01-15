#include <list>
#include "StringReverser.h"
#include "ClientHandler.h"
#include "MyTestClientHandler.h"
#include "Server.h"
#include "MySerialServer.h"
#include "FileCacheManager.h"
#include "MatrixProblem.h"

int main(/*int argc, char* argv[]*/) {
    list<string> example = {"8,2,8,6,8,2,12,2,4,1,9,9,5,12,1,1,1,2,7,3,1,6,9,3,9,7,7,9,5,6,4,5,1,6,-1,1,7\n",
                            "4,12,2,3,2,5,2,1,12,2,4,5,4,3,3,4,12,2,3,9,6,9,1,6,7,7,5,8,7,2,-1,3,2,5,-1,9,2\n"};
    Searchable<Point*> *matrix = new MatrixProblem(example, 2);
    Solver<string, string> *solver = new StringReverser();
    CacheManager<string, string> *cm = new FileCacheManager<string, string>();
    ClientHandler *c = new MyTestClientHandler(solver, cm);
    server_side::Server *server =  new MySerialServer();
    //server->open(atoi(argv[0]), c);
    server->open(5600, c);
    return 0;
};
