//
// Created by yana on 14/01/2020.
//

#include "MyClientHandler.h"
#include "MatrixProblem.h"
#include <iostream>
#include <unistd.h>
#include <cstring>
#include <sys/socket.h>

#define MAXREAD 256
using namespace std;

MyClientHandler::MyClientHandler(Solver<Searchable<State<Point *> *> *, Solution<State<Point *> *> *> *s,
                                 CacheManager<string, string> *mc) {
    this->solver = s;
    this->cm = mc;
}

void MyClientHandler::addDirections(Solution<State<Point *> *> *s, State<Point *> *initial) {
    vector<State<Point *> *> temp = s->getSol();
    int size = temp.size();
    for (int i = size - 2; i >= 1; i--) {
        double x = temp[i]->getState()->get_x();
        double y = temp[i]->getState()->get_y();
        double x_next = temp[i - 1]->getState()->get_x();
        double y_next = temp[i - 1]->getState()->get_y();
        if (x > x_next) {
            temp[i]->setDir(UP);
        } else if (x < x_next) {
            temp[i]->setDir(DOWN);
        } else if (y > y_next) {
            temp[i]->setDir(LEFT);
        } else {
            temp[i]->setDir(RIGHT);
        }
    }
}

void MyClientHandler::handleClient(int socket) {
    int line_counter = 0;
    hash<std::string> str_hash;
    int i = 0, valread;
    list<string> linesOfMatrix;
    string str = "", readyLine = "", to_send = "", id_for_matrix = "";
    char buffer[MAXREAD];
    while (readyLine.compare("end\n") != 0) {
        while (str.find('\n') == string::npos) {
            bzero(buffer, MAXREAD);
            valread = read(socket, buffer, MAXREAD);
            id_for_matrix.append(buffer); // to create its id, save all the matrix for the hash
            str.append(buffer);
        }
        readyLine = str.substr(0, str.find('\n'));
        readyLine += '\n';
        linesOfMatrix.push_back(readyLine);
        line_counter++;
        str.erase(0, str.find('\n') + 1);
    }
    line_counter -= 3;
    Searchable<State<Point *> *> *matrix = new MatrixProblem(linesOfMatrix, line_counter);
    string key_matrix = to_string(str_hash(id_for_matrix)) + this->solver->get_searcher_name();
    to_send = cm->get(key_matrix);
    if (to_send.empty()) {
        Solution<State<Point *> *> *sol = this->solver->solve(matrix);
        if (!sol->returnIfPathFound()) {
            to_send = "Path Not Found";
        }
        else {
            addDirections(sol, matrix->getInitialState());
            vector<State<Point *> *> temp = sol->getSol();
            int size = temp.size();
            for (int i = size - 2; i >= 1; i--) {
                switch (temp[i]->getDir()) {
                    case UP:
                        to_send += "Up ";
                        break;
                    case DOWN:
                        to_send += "Down ";
                        break;
                    case LEFT:
                        to_send += "Left ";
                        break;
                    case RIGHT:
                        to_send += "Right ";
                        break;
                    default:
                        break;
                }
                to_send += "(" + to_string(temp[i - 1]->getCostsThisFar()) + ")";
                if (i != 1) {
                    to_send += ", ";
                }
            }
        }
        cout << sol->getNumOfNodes() << endl;
        cm->insert(key_matrix, to_send);
    }
    const char *c = to_send.c_str();
    send(socket, c, strlen(c), 0);
    close(socket);
}