#include "StringReverser.h"
#include "ClientHandler.h"
#include "TestClientHandler.h"
#include "Server.h"
#include "MySerialServer.h"
#include "FileCacheManager.h"
#include "MatrixProblem.h"

int main(/*int argc, char* argv[]*/) {
//    list<string> lines = {"3, 1, 2, 8, 1, 4, 7, 9, 3, 7, 3, 6, 6, 6, 3, 9, 9, 3, 9, 3, 3, 7, 5,12, 2, 8, 2, 2, 5, 4, 9, 8, 5, 3, 2, 6, 4\n",
//                            "12, 1, 9, 5, 9, 2, 6,12, 3, 4,12,-1,12, 7, 9, 2, 1, 2, 2, 4, 6,12, 2, 2, 2, 3, 4, 1, 4, 4, 2, 4,12, 6, 2, 5, 6\n",
//                            "0,0\n","1,36\n","end"};
//    MatrixProblem* matrix = new MatrixProblem(lines, 2);
    Solver<string, string> *solver = new StringReverser();
    CacheManager<string, string> *cm = new FileCacheManager<string, string>();
    ClientHandler *c = new TestClientHandler(solver, cm);
    server_side::Server *server =  new MySerialServer();
    //server->open(atoi(argv[0]), c);
    server->open(5600, c);
    return 0;
};
