#include "OA.h"
#include "ClientHandler.h"
#include "MyClientHandler.h"
#include "Server.h"
#include "MySerialServer.h"
#include "FileCacheManager.h"
#include "Searchable.h"
#include "BestFS.h"
#include "BFS.h"
#include "DFS.h"


int main(/*int argc, char* argv[]*/) {
    AbstSearcher<Searchable<State<Point*>*>*, Solution<State<Point*>*>*, State<Point*>*> *search = new BestFS();
    Solver<Searchable<State<Point*>*>*, Solution<State<Point*>*>*> *solver = new OA<Searchable<State<Point*>*>*, Solution<State<Point*>*>*, State<Point*>*>(search);
    CacheManager<string , string> *cm = new FileCacheManager<string>();
    ClientHandler<Searchable<State<Point*>*> *, Solution<State<Point*>*>*, string, string>* c = new MyClientHandler(solver, cm);
    server_side::Server<Searchable<State<Point*>*>*, Solution<State<Point*>*>*, string, string> *server =  new MySerialServer();
    //server->open(atoi(argv[0]), c);
    server->open(5700, c);
    return 0;
};
