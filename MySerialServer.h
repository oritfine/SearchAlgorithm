//
// Created by yana on 12/01/2020.
//

#ifndef EX4_MYSERIALSERVER_H
#define EX4_MYSERIALSERVER_H

#include <iostream>
#include "Server.h"
#include "ClientHandler.h"
#include "Searchable.h"
#include "Solution.h"
#include "Point.h"

using namespace std;

class MySerialServer: public server_side::Server<Searchable<State<Point*>*>*, Solution<State<Point*>*>*, string, string> {
private:
    sockaddr_in address{};
    volatile bool to_stop = false;
public:
    void open(int numClients, int port, ClientHandler<Searchable<State<Point*>*>*, Solution<State<Point*>*>*, string, string> *c);

    void stop();

    void acceptClient(int socketfd, ClientHandler<Searchable<State<Point*>*>*, Solution<State<Point*>*>*, string, string> *c);


};


#endif //EX4_MYSERIALSERVER_H
