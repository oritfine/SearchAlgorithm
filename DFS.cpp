//
// Created by yana on 20/01/2020.
//

#include "DFS.h"
Solution<State<Point *> *> * DFS::search(Searchable<State<Point *> *> *searchable) {
    while (!d.empty()) {
        d.pop();
    }
    this->closed.clear();
    Solution<State<Point*>*> *back;
    this->d.push(searchable->getInitialState());
    int size = d.size();
    int counter = 1;
    while (size > 0) {
        State<Point*> *n = d.top();
        d.pop();
        closed.push_back(n);
        if (searchable->isStateGoal(n)) {
            back = backTrace(n);
            back->setNumOfNodes(counter);
            return back;
        }
        vector<State<Point*>*> neighbors = searchable->getAllPossibleStates(n);
        for (auto & neighbor : neighbors) {
            if (!isInClosedList(neighbor) && !isInD(neighbor)) {
                counter++;
                (neighbor)->setCameFrom(n);
                d.push(neighbor);
            }
        }
        size = d.size();
    }
    back->PathNotFount();
    return back;
}


bool DFS::isInClosedList(State<Point *> *s) {
    for (auto it = closed.begin(); it != closed.end(); ++it) {
        if (s->getState()->get_x() == (*it)->getState()->get_x()) {
            if (s->getState()->get_y() == (*it)->getState()->get_y()) {
                return true;
            }
        }
    }
    return false;
}

bool DFS::isInD(State<Point *> *s) {
    bool result = false;
    stack<State<Point*>*> tmp;
    State<Point *> *temp;
    int size = this->d.size();
    while (size > 0) {
        temp = this->d.top();
        if (s == temp) {
            result = true;
            break;
        }
        this->d.pop();
        tmp.push(temp);
        size = this->d.size();
    }
    int sizeTemp = tmp.size();
    while (sizeTemp > 0) {
        temp = tmp.top();
        tmp.pop();
        this->d.push(temp);
        sizeTemp = tmp.size();
    }
    return result;
}


Solution<State<Point *> *> * DFS::backTrace(State<Point *> *goal) {
    int sum = 0;
    Solution<State<Point*>*> *sol = new Solution<State<Point*>*>();
    sol->addSol(goal);
    while (goal != NULL) {
        goal = goal->getCameFrom();
        sol->addSol(goal);
    }
    vector<State<Point*>*> tmp = sol->getSol();
    int size = tmp.size();
    for (int i = size - 3; i >= 0; i--) {
        sum += tmp[i+1]->getCost();
        tmp[i]->setCostsThisFar(sum);
    }
    sol->setNumOfNodes(this->getNumOfNodesEvaluated());
    return sol;
}

string DFS::get_name() {
    return "DFS";
}