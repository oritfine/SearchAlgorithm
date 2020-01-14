//
// Created by yana on 12/01/2020.
//

#ifndef EX4_MYSERIALSERVER_H
#define EX4_MYSERIALSERVER_H

#include "Server.h"
#include "ClientHandler.h"

class MySerialServer: public server_side::Server {
private:
    sockaddr_in address{};
    volatile bool to_stop = false;
public:
    void open(int port, ClientHandler *c) override;
    void acceptClient(int socketfd, ClientHandler *c);
    void stop();
};


#endif //EX4_MYSERIALSERVER_H
