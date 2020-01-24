//
// Created by orit on 19/01/2020.
//

#include <map>
#include "Astar.h"

State<Point *> *Astar::get_state_min_f() {
    int size = open.size();
    int min = 0;
    State<Point *> *res = NULL;
    std::vector<State<Point *> *>::iterator it = open.begin();
    std::vector<State<Point *> *>::iterator it_erase = it;
    for (int i = 0; i < size; i++, it++) {
        int current_f_score = f_scores.find(open[i])->second;
        if (i == 0) {
            res = open[i];
            min = current_f_score;
            continue;
        }
        if (current_f_score < min) {
            res = open[i];
            min = current_f_score;
            it_erase = it;
        }
    }
    open.erase(it_erase);
    return res;
}

int Astar::get_heuristic(Point *current) {
    int x_res = abs(this->goal->getState()->get_x() - current->get_x());
    int y_res = abs(this->goal->getState()->get_y() - current->get_y());
    return x_res + y_res;
}

Solution<State<Point *> *>* Astar::search(Searchable<State<Point *> *> *searchable) {
    this->goal = searchable->getGoalState();
    State<Point *> *init = searchable->getInitialState();
    int g_score = init->getCostsThisFar();

    init->set_f_score(get_heuristic(init->getState()) + g_score);
    addToOpenList(searchable->getInitialState());
    int size = this->openListSize() > 0;
    while (size) {
        State<Point *> *n = popOpenList();
        n->set_f_score(get_heuristic(n->getState()));
        closed.push_back(n);
        if (searchable->isStateGoal(n)) {
            Solution<State<Point *> *> *back = backTrace(n);
            return back;
        }

        vector<State<Point *> *> neighbors = searchable->getAllPossibleStates(n);
        for (auto &neighbor : neighbors) {
            neighbor->set_f_score(get_heuristic(neighbor->getState()));
            int tentative_g_score = n->getCostsThisFar() + neighbor->getCost();
            int tentative_f_score = tentative_g_score + neighbor->get_f_score();
            int curr_f_score = neighbor->getCostsThisFar() + n->get_f_score();
            if (!isInOpenList(neighbor) && !isInClosedList(neighbor)) {
                (neighbor)->setCameFrom(n);
                (neighbor)->setCostsThisFar(n->getCostsThisFar());
                addToOpenList(neighbor);
            }
            else if (tentative_f_score < curr_f_score) {
                neighbor->setCameFrom(n);
                neighbor->setCostsThisFar(n->getCostsThisFar());
                this->updateOpenList();
            }
        }
        size = this->openListSize() > 0;
    }
    Solution<State<Point*>*>* back2;
    back2->PathNotFount();
    return back2;
}

bool Astar::isInClosedList(State<Point *> *s) {

    for (auto it = closed.begin(); it != closed.end(); ++it) {
        if (s->getState()->get_x() == (*it)->getState()->get_x()) {
            if (s->getState()->get_y() == (*it)->getState()->get_y()) {
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