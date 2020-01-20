//
// Created by orit on 14/01/2020.
//

#ifndef EX4_SEARCHER_H
#define EX4_SEARCHER_H

#include "Searchable.h"
#include "Solution.h"
#include "Solver.h"

using namespace std;

template <class P, class S>
class Searcher {
public:
    virtual S search(P searchable) = 0;
};
#endif //EX4_SEARCHER_H
