//
// Created by yana on 14/01/2020.
//

#ifndef EX4_MYCLIENTHANDLER_H
#define EX4_MYCLIENTHANDLER_H

#include <string>
#include "Solver.h"
#include "CacheManager.h"
#include "ClientHandler.h"
#include "Point.h"
#include "MatrixProblem.h"
#include "Solution.h"

using namespace std;

class MyClientHandler : public ClientHandler<Searchable<State<Point*>*> *, Solution<State<Point*>*>*, string, string>{
public:
    MyClientHandler* clone() {
        MyClientHandler* c = new MyClientHandler(this->solver->clone(), this->cm);
        return c;
    }
    MyClientHandler(Solver<Searchable<State<Point*>*> *, Solution<State<Point*>*>*> *s, CacheManager<string, string> *mc);
    void handleClient(int socket) override;
    void addDirections(Solution<State<Point*>*>* s, State<Point*>* initial);
};


#endif //EX4_MYCLIENTHANDLER_H
