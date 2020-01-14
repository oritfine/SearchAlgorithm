//
// Created by orit on 12/01/2020.
//

#ifndef EX4_STRINGREVERSER_H
#define EX4_STRINGREVERSER_H

#include <string>
#include "Solver.h"

using namespace std;

class StringReverser: public Solver<string, string> {
public:
    string solve(string p) override;
};

#endif //EX4_STRINGREVERSER_H
