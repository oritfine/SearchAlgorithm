//
// Created by orit on 17/01/2020.
//

#ifndef EX4_BFS_H
#define EX4_BFS_H

#include <string>
#include "AbstSearcher.h"

template <class T>
class BFS: public AbstSearcher<T> {
    vector<State<T>*> closed;
public:

    Solution<State<T>*>* search(Searchable<T> *searchable) {
    }

};


#endif //EX4_BFS_H
