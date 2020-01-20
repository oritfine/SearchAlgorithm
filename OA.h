//
// Created by orit on 17/01/2020.
//

#ifndef EX4_OA_H
#define EX4_OA_H


#include "Searcher.h"
// Problem - the matrix , Solution - , Algorithm - bfs,dfs..
template <class P, class S, class T>
class OA: public Solver<P, S>{
    Searchable<T> *searchable;
    Searcher<P, S> *searcher;
public:
    OA (Searcher<P, S> *searcher1) {
        this->searcher = searcher1;
    }
    void set_searcher(Searcher<P, S> *searcher1) {
        this->searcher = searcher1;
    }

    void set_searchable(Searchable<T> *searchable1) {
        this->searchable = searchable1;
    }

    Searcher<P, S>* get_searcher() {
        return this->searcher;
    }

    Searchable<T>* get_searchable() {
        return this->searchable;
    }

    S solve(Searchable<T> *p) {
        this->set_searchable(p);
        return this->searcher->search(this->searchable);
    }
};


#endif //EX4_OA_H
