//
// Created by orit on 14/01/2020.
//

#ifndef EX4_STATE_H
#define EX4_STATE_H

template <class T>
class State {
    T state;
    double cost;
    State<T> cameFrom;

public:
    State(T state) {
        this->state = state;
    }
    bool Equals(State<T> s) {
        return state.Equals(s.state);
    }
};

#endif //EX4_STATE_H
