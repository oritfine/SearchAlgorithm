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
    priority_queue <T, vector<T>, compare> openQueue;
protected:
    int evaluatedNodes = 0;
    virtual T popOpenList() {
        this->evaluatedNodes++;
       T t = this->openQueue.top();
        this->openQueue.pop();
        return t;
    }
    virtual int openListSize() {
        return this->openQueue.size();
    }
    virtual int getNumOfNodesEvaluated() {
        return this->evaluatedNodes;
    }
    virtual void addToOpenList(T t) {
        this->openQueue.push(t);
    }

    virtual bool isInOpenList(T t) {
        bool result = false;
        T temp;
        priority_queue <T, vector<T>, compare> tmp;
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
    virtual void updateOpenList() {
        vector<T> tmp;
        int size_queue = openListSize();
        while (size_queue > 0) {
            tmp.push_back(openQueue.top());
            openQueue.pop();
            size_queue = openListSize();
        }
        int size_vec = tmp.size();
        while (size_vec > 0) {
            openQueue.push(tmp.back());
            tmp.pop_back();
            size_vec = tmp.size();
        }
    }

    virtual S search(P searchable) = 0;
    virtual string get_name() = 0;
};


#endif //EX4_ABSTSEARCHER_H
