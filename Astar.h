//
// Created by orit on 19/01/2020.
//

#ifndef EX4_ASTAR_H
#define EX4_ASTAR_H

#include <string>
#include <map>
#include "Point.h"
#include "AbstSearcher.h"

class Astar: public AbstSearcher<Searchable<State<Point*>*>*, Solution<State<Point*>*>*, State<Point*>* >  {
    struct compareA {
        bool operator()(State<Point *> *a, State<Point *> *b) {
            return a->getCostsThisFar() + a->get_h_score() > b->getCostsThisFar() + b->get_h_score();
        }
    };
private:
    vector<State<Point*>*> closed;
    State<Point*>* goal;
    priority_queue <State<Point*>*, vector<State<Point*>*>, compareA> open;
public:
    State<Point*>* popOpenList() override;
    bool isInOpenList(State<Point*>* t) override;
    void updateOpenList() override;
    Solution<State<Point*>*>* search(Searchable<State<Point*>*> *searchable) override;
    bool isInClosedList(State<Point*> *s);
    Solution<State<Point*>*>* backTrace(State<Point*> *goal);
    int get_heuristic(Point* current);
    string get_name() override;
    Astar* clone();
};


#endif //EX4_ASTAR_H
