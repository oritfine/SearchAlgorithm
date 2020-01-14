//
// Created by yana on 12/01/2020.
//

#ifndef EX4_MYTESTCLIENTHANDLER_H
#define EX4_MYTESTCLIENTHANDLER_H
#include "ClientHandler.h"
#include "Solver.h"
#include "CacheManager.h"

class MyTestClientHandler: public ClientHandler {
private:
    Solver<string, string> *solver;
    CacheManager<string, string> *cm;
public:
    MyTestClientHandler(Solver<string, string> *solver, CacheManager<string, string> *cm);
    void handleClient(int socket) override;
};


#endif //EX4_MYTESTCLIENTHANDLER_H
