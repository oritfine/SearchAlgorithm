//
// Created by yana on 15/01/2020.
//

#ifndef EX4_ABSTSEARCHER_H
#define EX4_ABSTSEARCHER_H
#include <queue>
#include <stack>
#include "Searcher.h"

template <class P, class S, class T>
class AbstSearcher: public Searcher<P, S>{
    struct compare {
        bool operator()(const T& a, const T& b) {
            return a > b;
        }
    };
private:
    int evaluatedNodes = 0;
    priority_queue <T, vector<T>, compare> openQueue;
protected:
    T popOpenList() {
        this->evaluatedNodes++;
       T t = this->openQueue.top();
        this->openQueue.pop();
        return t;
    }
    int openListSize() {
        return this->openQueue.size();
    }
    int getNumOfNodesEvaluated() {
        return this->evaluatedNodes;
    }
    void addToOpenList(T t) {
        this->openQueue.push(t);
    }
    bool isInOpenList(T t) {
        bool result = false;
        T temp;
        priority_queue <T, vector<T>, greater<T>> tmp;
        bool res = false;
        int size = this->openListSize();
        while (size > 0) {
            temp = this->openQueue.top();
            if (t == temp) {
                result = true;
                break;
            }
            this->openQueue.pop();
            tmp.push(temp);
            size = this->openListSize();
        }
        int sizeTemp = tmp.size();
        while (sizeTemp > 0) {
            temp = tmp.top();
            tmp.pop();
            this->openQueue.push(temp);
            sizeTemp = tmp.size();
        }
        return result;
    }
    virtual S search(P searchable) = 0;
    virtual string get_name() = 0;
};


#endif //EX4_ABSTSEARCHER_H
