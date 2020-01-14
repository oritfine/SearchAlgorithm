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
    State<T> getInitialState();
    bool isStateGoal(State<T> s);
    vector<State<T>> getAllPossibleStates(State<T> s);
};
#endif //EX4_SEARCHABLE_H
