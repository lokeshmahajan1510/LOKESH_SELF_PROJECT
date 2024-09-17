#ifndef __CLIENT_HPP
#define __CLIENT_HPP

#include <iostream>
#include <winsock2.h>
#include <fstream>

#define SERVER_IP "132.186.183.91"
#define PORT      6623
#define BUFFER_SIZE 1024

class Client{

    public:
        Client();
        ~Client();
        void do_work(const char*);

    private:

        void Client_Connection();
        void recv_file(const char*);


        SOCKET clientSocket;
        WSAData wsaData;
        int wserr;
        char buffer[BUFFER_SIZE];
        int bytesreceived;


};

#endif