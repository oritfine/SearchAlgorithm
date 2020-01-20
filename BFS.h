//
// Created by orit on 17/01/2020.
//

#ifndef EX4_BFS_H
#define EX4_BFS_H

#include <string>
#include "AbstSearcher.h"
#include "Point.h"

class BFS: public AbstSearcher<Searchable<State<Point*>*>*, Solution<State<Point*>*>*, State<Point*>* > {
    queue<State<Point*>*> d;
    vector<State<Point*>*> closed;
public:
    Solution<State<Point*>*>* search(Searchable<State<Point*>*> *searchable);
    bool isInClosedList(State<Point*> *s);
    Solution<State<Point*>*>* backTrace(State<Point*> *goal);
};


#endif //EX4_BFS_H
