//
// Created by yana on 25/01/2020.
//

#ifndef EX4_MYPARALLELSERVER_H
#define EX4_MYPARALLELSERVER_H

#include "Point.h"
#include "State.h"
#include "Searchable.h"
#include "Solution.h"
#include "Server.h"
#include <iostream>

class MyParallelServer: public server_side::Server<Searchable < State < Point *>*>*, Solution<State < Point *>*>*, string, string> {
private:
    sockaddr_in address{};
    bool to_stop = false;
public:
    void open(int numClients,int port, ClientHandler<Searchable<State<Point*>*>*, Solution<State<Point*>*>*, string, string> *c);
    void stop() override;
    void acceptClient(int socketfd, ClientHandler<Searchable<State<Point*>*>*, Solution<State<Point*>*>*, string, string> *c);
};


#endif //EX4_MYPARALLELSERVER_H
