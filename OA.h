//
// Created by orit on 17/01/2020.
//

#ifndef EX4_OA_H
#define EX4_OA_H


#include "Searcher.h"
// Problem - the matrix , Solution - , Algorithm - bfs,dfs..
template <class P, class T, class A>
class OA: public Solver<P,T>{
    Searchable<P> *searchable;
    Searcher<A> *searcher;
public:
    OA();
    void set_searcher(Searcher<A> searcher1) {
        this->searcher = searcher1;
    }

    void set_searchable(Searchable<P> searchable1) {
        this->searcher = searchable1;
    }

    Searcher<A> get_searcher() {
        return this->searcher;
    }

    Searchable<P> get_searchable() {
        return this->searchable;
    }

    Solution<T> solve(P p) {
        return this->searcher->search(this->searchable);
    }
};


#endif //EX4_OA_H
