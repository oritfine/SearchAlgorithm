//
// Created by orit on 12/01/2020.
//

#include "StringReverser.h"


string StringReverser::solve(string p) {
    string solution = "";
    for (int i = p.size() - 1; i >= 0; i--) {
        solution += p[i];
    }
    return solution;
}

string StringReverser::get_searcher_name() {
    return "stringReverser";
}
