//
// Created by orit on 14/01/2020.
//

#ifndef EX4_STATE_H
#define EX4_STATE_H
typedef enum {NOT = -1, DOWN, UP, RIGHT, LEFT} Direction;
using namespace std;
template <class T>
class State {
    T state;
    double cost;
    State<T> *cameFrom;
    Direction dir;

public:
    State(const State<T> &s) {
        this->state = s->state;
        this->cost = s->cost;
        this->cameFrom = s->cameFrom;
        this->dir = s->dir;
    }
    State(T state, double val) {
        this->state = state;
        this->cost = val;
    }
    bool Equals(State<T> s) {
        return state.Equals(s.state);
    }
    T getState() {
        return state;
    }

};

#endif //EX4_STATE_H
