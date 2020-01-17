//
// Created by yana on 14/01/2020.
//

#include "MyClientHandler.h"
#include <iostream>
#include <unistd.h>
#include <cstring>
#include <sys/socket.h>
#define MAXREAD 256
using namespace std;

MyClientHandler::MyClientHandler(Solver<string, string> *s, CacheManager<string, string> *mc) {
    this->solver = s;
    this->cm = mc;
}

void MyClientHandler::handleClient(int socket) {
    int line_counter = 0;
    int i = 0, valread;
    string solution;
    list<string> linesOfMatrix;
    char buffer[MAXREAD];
    string str = "", readyLine = "";
    while (str.find("end") == string::npos) {
        while (str.find('\n') == string::npos) {
            valread = read(socket, buffer, MAXREAD);
            str.append(buffer);
        }
        readyLine = str.substr(0, str.find('\n'));
        linesOfMatrix.push_back(readyLine);
        line_counter++;
        str.erase(0, str.find('\n') + 1);
        valread = read(socket, buffer, MAXREAD);
        str.append(buffer);
    }
    line_counter -= 3;

    // function that checks if the solution exists in the cache
    //solution = cm->get(readyLine);
    // if not - go to the solver
   // if (solution.empty()) {
        //solution = solver->solve(readyLine);
        //cm->insert(readyLine, solution);
    //}
    const char *c = solution.c_str();
    send(socket, c, strlen(c), 0);
    close(socket);
}