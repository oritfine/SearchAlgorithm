//
// Created by orit on 14/01/2020.
//

#ifndef EX4_STATE_H
#define EX4_STATE_H

#include <string>
using namespace std;
typedef enum {NOT = -1, DOWN, UP, RIGHT, LEFT} Direction;

template <class T>
class State {
    T state;
    double cost{};
    double allCostsThisFar;
    State<T>* cameFrom;
    Direction dir;
public:
    explicit State(const State<T> &t) {
        this->state = t.state;
        this->dir = t.dir;
        this->cameFrom = t.cameFrom;
        this->cost = t.cost;
        this->allCostsThisFar = t.allCostsThisFar;
    }
    explicit State(T state) {
        this->state = state;
    }
    State(T state, double costVal) {
        this->state = state;
        this->cost = costVal;
        this->allCostsThisFar = cost;
    }
    bool operator==(const State& st) {
        return this->state == st.state;
    }
    bool operator!=(const State& st) {
        return this->state != st.state;
    }
    bool operator>(const State& st) {
        return this->allCostsThisFar > st.allCostsThisFar;
    }
    bool operator<(const State& st) {
        return this->allCostsThisFar < st.allCostsThisFar;
    }
    bool operator>=(const State& st) {
        return this->allCostsThisFar >= st.allCostsThisFar;
    }
    bool operator<=(const State& st) {
        return this->allCostsThisFar <= st.allCostsThisFar;
    }
    double getCost() {
        return this->cost;
    }
    void setCameFrom(State<T>* state1) {
        this->cameFrom = state1;
    }
    void setCost(double new_cost) {
        this->cost = new_cost;
    }
    void setCostsThisFar(double CostsThisFar) {
        this->allCostsThisFar += CostsThisFar;
    }
    void setDir(Direction direction) {
        this->dir = direction;
    }
    double getCostsThisFar() {
        return this->allCostsThisFar;
    }
    State<T>* getCameFrom() {
        return this->cameFrom;
    }
    Direction getDir() {
        return this->dir;
    }
    T getState() {
        return this->state;
    }
};

#endif //EX4_STATE_H
