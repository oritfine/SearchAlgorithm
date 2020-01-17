//
// Created by orit on 14/01/2020.
//

#ifndef EX4_MATRIXPROBLEM_H
#define EX4_MATRIXPROBLEM_H
#include <vector>
#include <string>
#include <list>
#include "State.h"
#include "Point.h"
#include "Searchable.h"
using namespace std;

class MatrixProblem: public Searchable<Point*> {
    vector<vector<State<Point*>*>> matrix;
    State<Point*> *initialState;
    State<Point*> *goalState;
public:
    MatrixProblem(list<string> input, int num_lines);
    void set_problem_states(string s, char sign);
    void createMatrix(list<string> input, int num_lines);
    State<Point*>* getInitialState();
    bool isStateGoal(State<Point*>* s);
    vector<State<Point*>*> getAllPossibleStates(State<Point*>* s);

};

#endif //EX4_MATRIXPROBLEM_H
