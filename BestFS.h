//
// Created by yana on 14/01/2020.
//

#ifndef EX4_BESTFS_H
#define EX4_BESTFS_H

#include <iostream>
#include <string>
#include "AbstSearcher.h"
#include "Point.h"
using namespace std;
class BestFS: public AbstSearcher<Searchable<State<Point*>*>*, Solution<State<Point*>*>*, State<Point*>* > {
    vector<State<Point*>*> closed;
public:
    Solution<State<Point*>*>* search(Searchable<State<Point*>*> *searchable);
    bool isInClosedList(State<Point*> *s);
    Solution<State<Point*>*>* backTrace(State<Point*> *goal);
    string get_name();

};


#endif //EX4_BESTFS_H
