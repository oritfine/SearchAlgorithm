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
    virtual State<T>* getInitialState() = 0;
    virtual bool isStateGoal(State<T>* s) = 0;
    virtual vector<State<T>*> getAllPossibleStates(State<T>* s) = 0;
};
#endif //EX4_SEARCHABLE_H
