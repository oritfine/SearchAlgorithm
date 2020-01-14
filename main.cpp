#include "StringReverser.h"
#include "ClientHandler.h"
#include "MyTestClientHandler.h"
#include "Server.h"
#include "MySerialServer.h"
#include "FileCacheManager.h"

int main(/*int argc, char* argv[]*/) {
    Solver<string, string> *solver = new StringReverser();
    CacheManager<string, string> *cm = new FileCacheManager<string, string>();
    ClientHandler *c = new MyTestClientHandler(solver, cm);
    server_side::Server *server =  new MySerialServer();
    //server->open(atoi(argv[0]), c);
    server->open(5600, c);
    return 0;
};
