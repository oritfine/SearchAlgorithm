//
// Created by orit on 14/01/2020.
//

#include "MatrixProblem.h"
MatrixProblem::MatrixProblem(list<string> input, int num_lines) {
    createMatrix(input, num_lines);
}

State<Point *> * MatrixProblem::getInitialState() {
    return this->initialState;
}

State<Point *> * MatrixProblem::getGoalState() {
    return this->initialState;
}

bool MatrixProblem::isStateGoal(State<Point*> *s) {

    if (s->getState()->get_x() == this->goalState->getState()->get_x()) {
        if (s->getState()->get_y() == this->goalState->getState()->get_y()) {
            return true;
        }
    }
    return false;
}

vector<State<Point *> *> MatrixProblem::getAllPossibleStates(State<Point *> *s) {
    vector<State<Point *> *> result;
    int num_lines = matrix.size();
    int num_cols = matrix.front().size();
    int x = s->getState()->get_x();
    int y = s->getState()->get_y();
    if (x + 1 < num_lines) {
        State<Point *> *down = this->matrix[x + 1][y];
        if (down->getCostsThisFar() != -1) {
            result.push_back(down);
        }
    }
    if (x - 1 >= 0) {
        State<Point *> *up = this->matrix[x - 1][y];
        if (up->getCostsThisFar() != -1) {
            result.push_back(up);
        }
    }
    if (y - 1 >= 0) {
        State<Point *> *left = this->matrix[x][y - 1];
        if (left->getCostsThisFar() != -1) {
            result.push_back(left);
        }
    }
    if (y + 1 < num_cols) {
        State<Point *> *right = this->matrix[x][y + 1];
        if (right->getCostsThisFar() != -1) {
            result.push_back(right);
        }
    }
    return result;
}

void MatrixProblem::set_problem_states(string s, char sign) {
    string string_x = s.substr(0, s.find(","));
    double x = stod(string_x);
    s.erase(0, s.find(",") + 1);
    string string_y = s.substr(0, s.find(","));
    double y = stod(string_y);
    State<Point*> *state = matrix[x][y];
    state->setDir(NOT);
    if (sign == 'i') {
        this->initialState = state;
        state->setCameFrom(NULL);
    } else {
        this->goalState = state;
//        double cost =matrix[x][y]->getCost();
//        goalState->setCost(cost);
    }
}

void MatrixProblem::createMatrix(list<string> input, int num_lines) {
    int row = 0;
    for (list<string>::iterator it = input.begin(); it != input.end(); ++it) {
        vector<State<Point*>*> line_vector;
        string tmp = *it;
        string string_line = "";

        // remove all spaces from string
        for (char i : tmp) {
            if (i == ' ') {
                continue;
            }
            string_line += i;
        }

        if (row == num_lines) {
            set_problem_states(tmp, 'i'); // set initial state
            row++;
            continue;
        } else if ( row == num_lines + 1) {
            set_problem_states(tmp, 'g'); // set goal state
            return;
        }

        int col = 0;
        while (string_line.find('\n') != string::npos){
            string string_val = string_line.substr(0, string_line.find(","));
            int val = stod(string_val);
            Point *p = new Point(row, col);
            State<Point*> *state = new State<Point*>(p, val);
            state->setDir(NOT);
            line_vector.push_back(state);
            string_line.erase(0, string_line.find(",") + 1);
            if (string_val[string_line.size() - 1] == '\n') {
                string_line = "";
            }
            col++;
        }
        this->matrix.push_back(line_vector);
        row++;
    }
}
