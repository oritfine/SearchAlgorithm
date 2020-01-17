//
// Created by yana on 14/01/2020.
//

#ifndef EX4_MYCLIENTHANDLER_H
#define EX4_MYCLIENTHANDLER_H

#include <string>
#include "Solver.h"
#include "CacheManager.h"
#include "ClientHandler.h"
using namespace std;

class MyClientHandler : public ClientHandler{
private:
    Solver<string, string> *solver;
    CacheManager<string, string> *cm;
public:
    MyClientHandler(Solver<string, string> *solver, CacheManager<string, string> *cm);
    void handleClient(int socket) override;
};


#endif //EX4_MYCLIENTHANDLER_H
