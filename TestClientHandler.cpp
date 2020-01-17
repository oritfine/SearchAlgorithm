//
// Created by yana on 12/01/2020.
//
#include <iostream>
#include <unistd.h>
#include <cstring>
#include <sys/socket.h>
#include "TestClientHandler.h"
#define MAXREAD 256
using namespace std;

TestClientHandler::TestClientHandler(Solver<string, string> *s, CacheManager<string, string> *mc) {
    this->solver = s;
    this->cm = mc;
}

void TestClientHandler::handleClient(int socket) {
    int i = 0, valread;
    string solution;
    char buffer[MAXREAD];
    string str = "", readyWord = "";
    while (str.find("end") == string::npos) {
        while (str.find('\n') == string::npos) {
            valread = read(socket, buffer, MAXREAD);
            str.append(buffer);
        }
        readyWord = str.substr(0, str.find('\n'));
        // function that checks if the solution exists in the cache
        solution = cm->get(readyWord);
        // if not - go to the solver
        if (solution.empty()) {
            solution = solver->solve(readyWord);
            cm->insert(readyWord, solution);
        }
        const char *c = solution.c_str();
        send(socket, c, strlen(c), 0);
        str.erase(0, str.find('\n') + 1);
        valread = read(socket, buffer, MAXREAD);
        str.append(buffer);
    }
    close(socket);
}