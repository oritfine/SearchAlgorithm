//
// Created by orit on 14/01/2020.
//

#ifndef EX4_SEARCHER_H
#define EX4_SEARCHER_H

#include "Searchable.h"

using namespace std;

template <class T, class S>
class Searcher {
public:
    S search(Searchable<T> searchable);
};
#endif //EX4_SEARCHER_H
