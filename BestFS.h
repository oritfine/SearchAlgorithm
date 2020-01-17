//
// Created by yana on 14/01/2020.
//

#ifndef EX4_BESTFS_H
#define EX4_BESTFS_H

#include <string>
#include "AbstSearcher.h"

template <class T>
class BestFS: public AbstSearcher<T> {
    vector<State<T>*> closed;
public:

    Solution<State<T>*>* search(Searchable<T> *searchable) {
        addToOpenList(searchable->getInitialState());
        int size;
        size = this->openListSize() > 0;
        while(size) {
            State<T> *n = this->popOpenList();
            closed.push_back(n);
            if (searchable->isStateGoal(n)) {
                Solution<string>* back = backTrace(n);
                return back;
            }
            vector<State<T> *> neighbors = searchable->getAllPossibleStates(n);
            for (auto it = neighbors.begin(); it != neighbors.end(); ++it) {
                State<T>* fit = *it;
                if (!isInOpenList(fit) && !isInClosedList(fit)) {
                    (fit)->setCameFrom(n);
                    (fit)->setCostsThisFar(n);
                    addToOpenList(fit);
                }
                else if (fit <= n) {
                    if (!isInOpenList(fit)) {
                        addToOpenList(fit);
                    }
                    else {
                        fit->setCameFrom(n->getCameFrom());
                        fit->setCostsThisFar(n);
                    }
                }
            }
            size = this->openListSize() > 0;
        }
    }

    bool isInClosedList(State<T> *s) {
        for (auto it = closed.begin(); it != closed.end(); ++it) {
            if (s == *it) {
                return true;
            }
        }
        return false;
    }

    Solution<string>* backTrace(State<T> *goal) {
        Solution<State<T>*> *sol = new Solution<State<T>*>*;
        sol->addSol(goal);
        while (goal != NULL) {
            goal = goal->getCameFrom();
            sol->addSol(goal);
        }
        return sol;
    }
};


#endif //EX4_BESTFS_H
