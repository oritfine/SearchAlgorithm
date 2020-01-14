//
// Created by orit on 12/01/2020.
//

#include "StringReverser.h"

template <class Solution,class Problem>

Solution StringReverser<Solution, Problem>::solve(Problem p) {
    string problem = to_string(p);
    string solution = "";
    for (int i = problem.size() - 1; i >= 0; i--) {
        solution += problem[i];
    }
    return (Solution) solution;
}
