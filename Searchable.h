//
// Created by orit on 14/01/2020.
//

#ifndef EX4_SEARCHABLE_H
#define EX4_SEARCHABLE_H
#include "State.h"
#include <vector>
using namespace std;

template <class T>
class Searchable {
public:
    virtual T getGoalState() = 0;
    virtual T getInitialState() = 0;
    virtual bool isStateGoal(T s) = 0;
    virtual vector<T> getAllPossibleStates(T s) = 0;
};
#endif //EX4_SEARCHABLE_H
