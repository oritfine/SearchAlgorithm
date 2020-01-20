//
// Created by yana on 12/01/2020.
//

#ifndef EX4_CLIENTHANDLER_H
#define EX4_CLIENTHANDLER_H
#include "CacheManager.h"
#include "Solver.h"

template <class P, class S, class Key, class Value>
class ClientHandler {
protected:
    Solver<P,S> *solver;
    CacheManager<Key, Value> *cm;
public:
    virtual void handleClient(int socket) = 0;
};


#endif //EX4_CLIENTHANDLER_H
