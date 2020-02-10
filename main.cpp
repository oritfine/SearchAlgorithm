#include "OA.h"
#include "ClientHandler.h"
#include "MyClientHandler.h"
#include "Server.h"
#include "FileCacheManager.h"
#include "Searchable.h"
#include "Astar.h"
#include "MyParallelServer.h"

#define NUM_CLIENTS 15

int main(int argc, char* argv[]) {
    AbstSearcher<Searchable<State<Point*>*>*, Solution<State<Point*>*>*, State<Point*>*> *search = new Astar();
    Solver<Searchable<State<Point*>*>*, Solution<State<Point*>*>*> *solver = new OA<Searchable<State<Point*>*>*, Solution<State<Point*>*>*, State<Point*>*>(search);
    CacheManager<string , string> *cm = new FileCacheManager<string>();
    ClientHandler<Searchable<State<Point*>*> *, Solution<State<Point*>*>*, string, string>* c = new MyClientHandler(solver, cm);
    server_side::Server<Searchable<State<Point*>*>*, Solution<State<Point*>*>*, string, string> *server =  new MyParallelServer();
    if (argv[1] != NULL) {
        server->open(NUM_CLIENTS,atoi(argv[1]), c);
    }
    else {
        server->open(NUM_CLIENTS, 5700, c);
    }

    return 0;
};
