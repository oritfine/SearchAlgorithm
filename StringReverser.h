//
// Created by orit on 12/01/2020.
//

#ifndef EX4_STRINGREVERSER_H
#define EX4_STRINGREVERSER_H

#include <string>
#include "Solver.h"

using namespace std;

template <class Solution, class Problem>
class StringReverser: public Solver<Solution, Problem> {
public:
    Solution solve(Problem p);
};

#endif //EX4_STRINGREVERSER_H
