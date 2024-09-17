#ifndef __SERVER_HPP
#define __SERVER_HPP

#include <iostream>
#include <fstream>
#include <winsock2.h>

#define BUFFER_SIZE 1024
#define PORT        55555

class Server{
    public:
        Server();
        ~Server();
        void do_work(const char* file);

    private:
        void Server_connection();
        void send_file(const char* filepath);

        //const char* filepath = argv[1];
        SOCKET Serversocket;
        SOCKET acceptSocket;
        WSADATA wsaData;
        int wsaerr;

        char buffer[BUFFER_SIZE];
        
};

#endif