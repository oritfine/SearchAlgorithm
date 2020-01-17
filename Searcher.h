//
// Created by orit on 14/01/2020.
//

#ifndef EX4_SEARCHER_H
#define EX4_SEARCHER_H

#include "Searchable.h"
#include "Solution.h"
#include "Solver.h"

using namespace std;

template <class T>
class Searcher {
public:
    virtual Solution<State<T>*>* search(Searchable<T> *searchable) = 0;
};
#endif //EX4_SEARCHER_H
