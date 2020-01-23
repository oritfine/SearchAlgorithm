#include "AbstSearcher.h"
#include "BestFS.h"
Solution<State<Point *> *> * BestFS::search(Searchable<State<Point *> *> *searchable) {
    addToOpenList(searchable->getInitialState());
    int size;
    Solution<State<Point*>*>* back;
    size = this->openListSize() > 0;
    while(size) {
        State<Point*> *n = this->popOpenList();
        closed.push_back(n);
        if (searchable->isStateGoal(n)) {
            back = backTrace(n);
            return back;
        }
        vector<State<Point*> *> neighbors = searchable->getAllPossibleStates(n);
        for (auto & neighbor : neighbors) {
            if (!isInOpenList(neighbor) && !isInClosedList(neighbor)) {
                (neighbor)->setCameFrom(n);
                (neighbor)->setCostsThisFar(n->getCostsThisFar());
                addToOpenList(neighbor);
            }
            else if (neighbor->getCostsThisFar() >= n->getCostsThisFar() + neighbor->getCost()) {
//                if (!isInOpenList(neighbor) && !isInClosedList(neighbor)) {
//                    addToOpenList(neighbor);
//                }
//                else {
                    neighbor->setCameFrom(n);
                    neighbor->setCostsThisFar(n->getCostsThisFar());
                ////}
            }
        }
        size = this->openListSize() > 0;
    }
    back->PathNotFount();
    return back;
}



bool BestFS::isInClosedList(State<Point *> *s) {
    for (auto it = closed.begin(); it != closed.end(); ++it) {
        if (s->getState()->get_x() == (*it)->getState()->get_x()) {
            if (s->getState()->get_y() == (*it)->getState()->get_y()) {
                return true;
            }
        }
    }
    return false;
}


Solution<State<Point *> *> * BestFS::backTrace(State<Point *> *goal) {
    Solution<State<Point*>*>* sol = new Solution<State<Point*>*>();
    sol->addSol(goal);
    while (goal != NULL) {
        goal = goal->getCameFrom();
        sol->addSol(goal);
    }
    sol->setNumOfNodes(this->getNumOfNodesEvaluated());
    return sol;
}

string BestFS::get_name() {
    return "BestFS";
}