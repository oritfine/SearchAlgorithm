//
// Created by yana on 12/01/2020.
//

#include <sys/socket.h>
#include <rpc/types.h>
#include <iostream>
#include <thread>
#include <mutex>
#include <unistd.h>
#include "MySerialServer.h"
#include "ClientHandler.h"

using namespace std;
void MySerialServer::open(int port, ClientHandler<Searchable<State<Point*>*>*, Solution<State<Point*>*>*, string, string> *c) {
    int socketfd = socket(AF_INET, SOCK_STREAM, 0);
    if (socketfd == -1) {
        //error
        std::cerr << "Could not create a socket" << std::endl;
    }
    //bind socket to IP address
    // we first need to create the sockaddr obj.
    //sockaddr_in address; //in means IP4
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY; //give me any IP allocated for my machine
    address.sin_port = htons(port);
    //we need to convert our number
    // to a number that the network understands.

    //the actual bind command
    if (bind(socketfd, (struct sockaddr *) &address, sizeof(address)) == -1) {
        std::cerr << "Could not bind the socket to an IP" << std::endl;
    }
    //making socket listen to the port
    if (listen(socketfd, 5) == -1) { //can also set to SOMAXCON (max connections)
        std::cerr << "Error during listening command" << std::endl;
    } else {
        std::cout << "Server is now listening ..." << std::endl;
    }
    auto *t1 = new thread(&MySerialServer::acceptClient, this, socketfd, c);
    t1->join();
}

void MySerialServer::stop() {
    this->to_stop = true;
}

void MySerialServer::acceptClient(int socketfd, ClientHandler<Searchable<State<Point*>*>*, Solution<State<Point*>*>*, string, string> *c) {
    struct timeval timeout;
    int rc;
    fd_set master_set;
    while (!this->to_stop) {
        int addrSize = sizeof(address);
        timeout.tv_sec  = 30;
        timeout.tv_usec = 0;
        FD_ZERO(&master_set);
        FD_SET(socketfd, &master_set);
        rc = select(socketfd + 1, &master_set, NULL, NULL, &timeout);
        if (rc > 0) {
            int client_socket = accept(socketfd, (struct sockaddr *) &address, (socklen_t *) &addrSize);
            if (client_socket == -1) {
                std::cerr << "Error accepting client" << std::endl;
            } else {
                std::cout << "Someone connected to server" << std::endl;
            }
            c->handleClient(client_socket);
        }
        else {
            this->stop();
            break;
        }
    }
    if (this->to_stop) {
        close(socketfd);
    }
}


