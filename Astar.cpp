//
// Created by orit on 19/01/2020.
//

#include <map>
#include <iostream>
#include "Astar.h"

Astar * Astar::clone() {
    return new Astar();
}

State<Point *> * Astar::popOpenList() {
    this->evaluatedNodes++;
    State<Point *> * t = this->open.top();
    this->open.pop();
    return t;
}

bool Astar::isInOpenList(State<Point *> *t) {
    bool result = false;
    State<Point *>* temp;
    priority_queue <State<Point *>*, vector<State<Point *>*>, compareA> tmp;
    int size = this->open.size();
    while (size > 0) {
        temp = this->open.top();
        if (t == temp) {
            result = true;
            break;
        }
        this->open.pop();
        tmp.push(temp);
        size = this->open.size();
    }
    int sizeTemp = tmp.size();
    while (sizeTemp > 0) {
        temp = tmp.top();
        tmp.pop();
        this->open.push(temp);
        sizeTemp = tmp.size();
    }
    return result;
}

void Astar::updateOpenList() {
    vector<State<Point*>*> tmp;
    int size_queue = this->open.size();
    while (size_queue > 0) {
        tmp.push_back(this->open.top());
        this->open.pop();
        size_queue = this->open.size();
    }
    int size_vec = tmp.size();
    while (size_vec > 0) {
        this->open.push(tmp.back());
        tmp.pop_back();
        size_vec = tmp.size();
    }
}

int Astar::get_heuristic(Point *current) {
    int x_res = abs(this->goal->getState()->get_x() - current->get_x());
    int y_res = abs(this->goal->getState()->get_y() - current->get_y());
    return x_res + y_res;
}

Solution<State<Point *> *>* Astar::search(Searchable<State<Point *> *> *searchable) {
    this->goal = searchable->getGoalState();
    this->open.push(searchable->getInitialState());
    int size = !this->open.empty();
    while (size) {
        State<Point *> *n = popOpenList();
        n->set_h_score(get_heuristic(n->getState()));
        closed.push_back(n);
        if (searchable->isStateGoal(n)) {
            Solution<State<Point *> *> *back = backTrace(n);
            return back;
        }
        vector<State<Point *> *> neighbors = searchable->getAllPossibleStates(n);
        for (auto &neighbor : neighbors) {
            if (!isInOpenList(neighbor) && !isInClosedList(neighbor)) {
                (neighbor)->setCameFrom(n);
                neighbor->set_h_score(get_heuristic(neighbor->getState()));
                (neighbor)->setCostsThisFar(n->getCostsThisFar());
                this->open.push(neighbor);
            }
            else if (neighbor->getCostsThisFar() + neighbor->get_h_score() >
                      n->getCostsThisFar() + neighbor->getCost() + n->get_h_score()) {
                neighbor->setCameFrom(n);
                neighbor->set_h_score(get_heuristic(neighbor->getState()));
                neighbor->setCostsThisFar(n->getCostsThisFar());
                this->updateOpenList();
            }
        }
        size = !this->open.empty();
    }
    Solution<State<Point*>*>* back2;
    back2->PathNotFount();
    return back2;
}

bool Astar::isInClosedList(State<Point *> *s) {

    for (auto & it : closed) {
        if (s->getState()->get_x() == it->getState()->get_x()) {
            if (s->getState()->get_y() == it->getState()->get_y()) {
                return true;
            }
        }
    }
    return false;
}

Solution<State<Point *> *> *Astar::backTrace(State<Point *> *goal) {
    Solution<State<Point *> *> *sol = new Solution<State<Point *> *>();
    sol->addSol(goal);
    while (goal != NULL) {
        goal = goal->getCameFrom();
        sol->addSol(goal);
    }
    sol->setNumOfNodes(this->getNumOfNodesEvaluated());
    return sol;
}

string Astar::get_name() {
    return "A_STAR";
}