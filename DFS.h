//
// Created by yana on 20/01/2020.
//

#ifndef EX4_DFS_H
#define EX4_DFS_H
#include <string>
#include "AbstSearcher.h"
#include "Point.h"

class DFS: public AbstSearcher<Searchable<State<Point*>*>*, Solution<State<Point*>*>*, State<Point*>* > {
private:
    stack<State<Point*>*> d;
    vector<State<Point*>*> closed;
public:
    Solution<State<Point*>*>* search(Searchable<State<Point*>*> *searchable);
    bool isInClosedList(State<Point*> *s);
    Solution<State<Point*>*>* backTrace(State<Point*> *goal);
    bool isInD(State<Point*> *s);
    string get_name();
};


#endif //EX4_DFS_H
