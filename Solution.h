//
// Created by yana on 14/01/2020.
//

#ifndef EX4_SOLUTION_H
#define EX4_SOLUTION_H
#include <vector>
using namespace std;
template <class T>
class Solution {
private:
    vector<T> sol;
    int numNodes;
public:
    void addSol(T sol) {
        this->sol.push_back(sol);
    }
    vector<T> getSol() {
        return this->sol;
    }
    void setNumOfNodes(int nodes) {
        this->numNodes = nodes;
    }
};


#endif //EX4_SOLUTION_H
