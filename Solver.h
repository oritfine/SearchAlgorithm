//
// Created by orit on 12/01/2020.
//

#ifndef EX4_SOLVER_H
#define EX4_SOLVER_H

template <class Solution, class Problem>

class Solver {
public:
    virtual Solution solve(Problem p) = 0;
};
#endif //EX4_SOLVER_H

