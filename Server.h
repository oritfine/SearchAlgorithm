//
// Created by yana on 12/01/2020.
//

#ifndef EX4_SERVER_H
#define EX4_SERVER_H

#include "ClientHandler.h"
#include <sys/socket.h>
#include <rpc/types.h>

namespace server_side {
    template <class P, class S, class Key, class Value>
    class Server {
    public:
        virtual void open(int port, ClientHandler<P, S, Key, Value> *c) = 0;
        virtual void stop() = 0;
    };
}

#endif //EX4_SERVER_H
