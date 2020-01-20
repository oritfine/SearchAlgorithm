//
// Created by orit on 14/01/2020.
//

#ifndef EX4_STATE_H
#define EX4_STATE_H
#include <math.h>
#include <stdint.h>
#include <inttypes.h>
#include <string>
using namespace std;
typedef enum {NOT = -1, DOWN, UP, RIGHT, LEFT} Direction;

template <class T>
class State {
    T state;
    int cost{};
    int allCostsThisFar;
    State<T>* cameFrom = NULL;
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
    State(T state, int costVal) {
        this->state = state;
        if (costVal != -1) {
            this->cost = costVal;
        }
        else {
            this->cost = INFINITY;
        }
        this->allCostsThisFar = costVal;
    }
    bool operator==(const State& st) {
        return this->state == st.state;
    }
    bool operator!=(const State& st) {
        return this->state != st.state;
    }
    bool operator>(const State& st) {
        //return st.allCostsThisFar > this->allCostsThisFar;
        return this->allCostsThisFar > st.allCostsThisFar;
    }
    bool operator<(const State& st) {
        //return st.allCostsThisFar < this->allCostsThisFar;
        return this->allCostsThisFar < st.allCostsThisFar;
    }
    bool operator>=(const State& st) {
        return this->allCostsThisFar >= st.allCostsThisFar;
    }
    bool operator<=(const State& st) {
        return this->allCostsThisFar <= st.allCostsThisFar;
    }
    int getCost() {
        return this->cost;
    }
    void setCameFrom(State<T>* state1) {
        if (this->cameFrom != NULL) {
            this->allCostsThisFar = this->cost;
        }
        this->cameFrom = state1;
    }
    void setCost(int new_cost) {
        this->cost = new_cost;
    }
    void setCostsThisFar(int CostsThisFar) {
        this->allCostsThisFar += CostsThisFar;
    }
    void setDir(Direction direction) {
        this->dir = direction;
    }
    int getCostsThisFar() {
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
