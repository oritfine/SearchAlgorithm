//
// Created by yana on 14/01/2020.
//

#ifndef EX4_SOLUTION_H
#define EX4_SOLUTION_H
#include <list>
using namespace std;
template <class T>
class Solution {
private:
    list<T> sol;
public:
    void addSol(T sol) {
        this->sol.push_back(sol);
    }
    list<T> getSol() {
        return this->sol;
    }
};


#endif //EX4_SOLUTION_H
