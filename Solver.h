//
// Created by orit on 12/01/2020.
//

#ifndef EX4_SOLVER_H
#define EX4_SOLVER_H

#include <string>
using namespace std;
template <class P, class S>

class Solver {
public:
    virtual S solve(P p) = 0;
    virtual string get_searcher_name() = 0;
};
#endif //EX4_SOLVER_H

