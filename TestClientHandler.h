//
// Created by yana on 12/01/2020.
//

#ifndef EX4_TESTCLIENTHANDLER_H
#define EX4_TESTCLIENTHANDLER_H
#include "ClientHandler.h"
#include "Solver.h"
#include "CacheManager.h"

class TestClientHandler: public ClientHandler {
private:
    Solver<string, string> *solver;
    CacheManager<string, string> *cm;
public:
    TestClientHandler(Solver<string, string> *solver, CacheManager<string, string> *cm);
    void handleClient(int socket) override;
};


#endif //EX4_TESTCLIENTHANDLER_H
