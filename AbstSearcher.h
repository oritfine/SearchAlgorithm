//
// Created by yana on 15/01/2020.
//

#ifndef EX4_ABSTSEARCHER_H
#define EX4_ABSTSEARCHER_H
#include <queue>
#include <stack>
#include "Searcher.h"

template <class T>
class AbstSearcher: public Searcher<T>{
private:
    int evaluatedNodes = 0;
    priority_queue <State<T>*, vector<State<T>*>, greater<State<T>*>> openQueue;
protected:
    State<T>* popOpenList() {
        this->evaluatedNodes++;
        State<T>* t = this->openQueue.top();
        this->openQueue.pop();
        return t;
    }
    int openListSize() {
        return this->openQueue.size();
    }
    int getNumOfNodesEvaluated() {
        return this->evaluatedNodes;
    }
    void addToOpenList(State<T> *t) {
        this->openQueue.push(t);
    }
    bool isInOpenList(State<T> *t) {
        priority_queue <State<T>*, vector<State<T>*>, greater<State<T>*>> tmp;
        bool res = false;
        for (auto it = openQueue.begin(); it != openQueue.end(); ++it) {
            if (t == *it) {
                res = true;
                break;
            }
            tmp.push(this->openQueue.pop());
        }
        for (auto itTmp = tmp.begin(); itTmp != tmp.end(); ++itTmp) {
            this->openQueue.push(tmp.pop());
        }
        return res;
    }
    virtual Solution<State<T>*>* search(Searchable<T> *searchable) = 0;
};
#endif //EX4_ABSTSEARCHER_H
