#include "server.hpp"

Server::Server(){
    Server_connection();
}

Server::~Server(){

    closesocket(acceptSocket);
    closesocket(Serversocket);
    WSACleanup();
}

void Server::do_work(const char* file){
    send_file(file);
}

void Server::Server_connection(){

    // 1) initialize WSA variable

    WORD winsockversion = MAKEWORD(2, 2);
    wsaerr = WSAStartup(winsockversion, &wsaData);

    // 2) check for initialisation success

    if(wsaerr != 0){
        std::cout<<"The Winsock dll not found!"<<std::endl;
    }else{
        std::cout<<"The winsock dll found\n"<<std::endl;
        std::cout<<"The status: "<<wsaData.szSystemStatus<<std::endl;
    }


    Serversocket = INVALID_SOCKET;
    Serversocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    if(Serversocket == INVALID_SOCKET){
        std::cout<<"Error at socket() : "<<WSAGetLastError()<<std::endl;
        WSACleanup();
    }else{
        std::cout<<"Socket created successfully"<<std::endl;
    }

    // 3) bind the socket

    sockaddr_in service;
    service.sin_family = AF_INET;
    //service.sin_addr.s_addr = inet_addr("132.186.183.91");
    service.sin_addr.s_addr = inet_addr("0.0.0.0");
    service.sin_port = htons(6623);

    if(bind(Serversocket, reinterpret_cast<SOCKADDR*>(&service), sizeof(service)) == SOCKET_ERROR){
        std::cout<<"bind() failed : "<<WSAGetLastError()<<std::endl;
        closesocket(Serversocket);
        WSACleanup();
    }else{
        std::cout<<"bind() is ok!"<<std::endl;
    }

    // 4) Listen for incomming connection

    if(listen(Serversocket, 1) == SOCKET_ERROR){
        std::cout<<"listen() : Error listening on socket: "<< WSAGetLastError()<<std::endl;
    }else{
        std::cout<<"Listen() is ok! I'm waiting for new connection...."<<std::endl;
    }

    // 5) Accept incomming connection

    acceptSocket = accept(Serversocket, nullptr, nullptr);

    if(acceptSocket == INVALID_SOCKET){
        std::cout<<"accept failed : "<<WSAGetLastError() <<std::endl;
        WSACleanup();
    }else{
        std::cout<<"accept() is OK!"<<std::endl;
    }
}

void Server::send_file(const char* filepath){

    std::ifstream file(filepath, std::ios::binary);
    if(!file.is_open()){
        std::cerr<<"Failed to open file\n";
        closesocket(acceptSocket);
        closesocket(Serversocket);
        WSACleanup();
    }

    while (!file.eof())
    {
        file.read(buffer, BUFFER_SIZE);
        int bytesread = file.gcount();
        int bytesSent = send(acceptSocket, buffer, bytesread, 0);
        if(bytesSent  == SOCKET_ERROR){
            std::cerr<<"Send failed\n";
            break;
        }
    }
    std::cout<<"file sent successfully"<<std::endl;

    file.close();
    closesocket(acceptSocket);
    closesocket(Serversocket);
    WSACleanup();
}

