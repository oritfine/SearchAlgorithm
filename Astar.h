//
// Created by orit on 19/01/2020.
//

#ifndef EX4_ASTAR_H
#define EX4_ASTAR_H

#include <string>
#include <map>
#include "Point.h"
#include "AbstSearcher.h"
//
//class Astar: public AbstSearcher<Searchable<State<Point*>*>*, Solution<State<Point*>*>*, State<Point*>* > {
//
//};
//template <class P, class S, class T>
//class Astar: public AbstSearcher<P, S, T >  {
//private:
//    vector<State<Point*>*> closed;
//    vector<State<Point*>*> open;
//    map<State<Point*>*, int> f_scores;
//    State<Point*>* goal;
//public:
//    Solution<State<Point*>*>* search(Searchable<State<Point*>*> *searchable) override;
//    bool isInClosedList(State<Point*> *s);
//    bool isInOpenList(T s);
//    Solution<State<Point*>*>* backTrace(State<Point*> *goal);
//    int get_heuristic(Point* current);
//    State<Point*>* get_state_min_f();
//};
class Astar: public AbstSearcher<Searchable<State<Point*>*>*, Solution<State<Point*>*>*, State<Point*>* >  {
private:
    vector<State<Point*>*> closed;
    vector<State<Point*>*> open;
    map<State<Point*>*, int> f_scores;
    State<Point*>* goal;
public:
    Solution<State<Point*>*>* search(Searchable<State<Point*>*> *searchable) override;
    bool isInClosedList(State<Point*> *s);
    Solution<State<Point*>*>* backTrace(State<Point*> *goal);
    int get_heuristic(Point* current);
    State<Point*>* get_state_min_f();
    string get_name();
};


#endif //EX4_ASTAR_H
