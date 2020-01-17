//
// Created by orit on 12/01/2020.
//

#ifndef EX4_SOLVER_H
#define EX4_SOLVER_H

template <class P, class T>

class Solver {
public:
    virtual Solution<T> solve(P p) = 0;
};
#endif //EX4_SOLVER_H

