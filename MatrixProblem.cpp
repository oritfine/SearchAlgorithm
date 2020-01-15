//
// Created by orit on 14/01/2020.
//

#include "MatrixProblem.h"
State<Point *> * MatrixProblem::getInitialState() {
    return this->initialState;
}

bool MatrixProblem::isStateGoal(State<Point *> *s) {
    if (s == this->goalState) {
        return true;
    }
    return false;
}

vector<State<Point *> *> MatrixProblem::getAllPossibleStates(State<Point *> *s) {
    vector<State<Point *> *> result;
    int num_lines = matrix.size();
    int num_cols = matrix.front().size();
    int x = s->getState()->get_x();
    int y = s->getState()->get_y();
    if (x == 0) {
        State<Point*> *down = new State<Point*>(*matrix[x][y + 1]);
        result.push_back(down);
        //down, right
        if (y == 0) {
            State<Point*> *right = new State<Point*>(*matrix[x + 1][y]);
            result.push_back(right);
            //down, right
        } else if (y == num_cols) {
            State<Point*> *left = new State<Point*>(*matrix[x - 1][y]);
            result.push_back(left);
            // down, left
        } else {
            State<Point*> *right = new State<Point*>(*matrix[x + 1][y]);
            State<Point*> *left = new State<Point*>(*matrix[x - 1][y]);
            result.push_back(right);
            result.push_back(left);
            // down, right, left
        }
    }
    if (x == num_lines) {
        State<Point*> *up = new State<Point*>(*matrix[x][y - 1]);
        result.push_back(up);
        if (y == 0) {
            State<Point*> *right = new State<Point*>(*matrix[x + 1][y]);
            result.push_back(right);
            // up, right
        } else if (y == num_cols) {
            State<Point*> *left = new State<Point*>(*matrix[x - 1][y]);
            result.push_back(left);
            // up, left
        } else {
            State<Point*> *right = new State<Point*>(*matrix[x + 1][y]);
            State<Point*> *left = new State<Point*>(*matrix[x - 1][y]);
            result.push_back(right);
            result.push_back(left);
            // up, right, left
        }
    } else {
        State<Point*> *up = new State<Point*>(*matrix[x][y - 1]);
        State<Point*> *down = new State<Point*>(*matrix[x][y + 1]);
        State<Point*> *right = new State<Point*>(*matrix[x + 1][y]);
        State<Point*> *left = new State<Point*>(*matrix[x - 1][y]);
        result.push_back(up);
        result.push_back(down);
        result.push_back(right);
        result.push_back(left);
        // up, down, right, left
    }
    return result;
}

MatrixProblem::MatrixProblem(list<string> input, int num_lines) {
    createMatrix(input, num_lines);
}

void MatrixProblem::createMatrix(list<string> input, int num_lines) {
    int row = 0;
    for (list<string>::iterator it = input.begin(); it != input.end(); ++it) {

        vector<State<Point*>*> line_vector;
        string tmp = *it;
        string string_line = "";

        // remove all spaces from string
        for ( int i = 0; i < tmp.size(); i++) {
            if (tmp[i] == ' ') {
                continue;
            }
            string_line += tmp[i];
        }

        int col = 0;
        while (string_line.find('\n') != string::npos){
            string string_val = string_line.substr(0, string_line.find(","));
            float val = stof(string_val);
            Point *p = new Point(row, col);
            State<Point*> *state = new State<Point*>(p, val);
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
        /*for ( int i = 0; i < string_line.size(); i++) {

           if (string_line[i] == ',' || string_line[i] == ' ') {
               continue;
           }
           Point *p = new Point(row, col);
           State<Point*> *state = new State<Point>(p, );
           line.push_back(state);
           col++;
        }*/

}
