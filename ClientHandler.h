//
// Created by yana on 12/01/2020.
//

#ifndef EX4_CLIENTHANDLER_H
#define EX4_CLIENTHANDLER_H
class ClientHandler {
public:
    virtual void handleClient(int socket) = 0;
};


#endif //EX4_CLIENTHANDLER_H
