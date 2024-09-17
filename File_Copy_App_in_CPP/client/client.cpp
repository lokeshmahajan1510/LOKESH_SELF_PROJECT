#include "client.hpp"

Client::Client(){
    Client_Connection();
}

Client::~Client(){
    closesocket(clientSocket);
    WSACleanup();
}       

void Client::do_work(const char* file){
    recv_file(file);
}

void Client::Client_Connection(){

    //1) initialize WSA variable

    WORD wVersionRequested = MAKEWORD(2, 2);
    wserr = WSAStartup(wVersionRequested, &wsaData);

    // 2) Check for initialization success
    if(wserr != 0){
        std::cout<<"The winsock dll not found "<<std::endl;
    }else{
        std::cout<<"The Winsock dll found "<<std::endl;
        std::cout<<"The status : "<<wsaData.szSystemStatus <<std::endl;
    }

    // 3) Create a Socket

    //SOCKET clientSocket;
    clientSocket = INVALID_SOCKET;
    clientSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    // 4) Check for SOCKET creation success

    if(clientSocket == INVALID_SOCKET){
        std::cout<<"Error at socket() : "<<WSAGetLastError() <<std::endl;
        WSACleanup();
    }else{
        std::cout<<"Socket Created Successfully......"<<std::endl;
    }

    // 5) Connect to the Server
    sockaddr_in clientService;
    clientService.sin_family = AF_INET;
    clientService.sin_addr.s_addr = inet_addr(SERVER_IP);
    clientService.sin_port = htons(PORT);

    // 6) Use the connect function
    if(connect(clientSocket, reinterpret_cast<SOCKADDR*>(&clientService), sizeof(clientService)) == SOCKET_ERROR){

        std::cout<<"Client : connect() - failed to connect: "<<WSAGetLastError() <<std::endl;
        WSACleanup();
    }else{
        std::cout<<"Client : Connect() Successfully  to Server...."<<std::endl;
        std::cout<<"Client : Can start sending and receiving data..."<<std::endl;
    }

}

void Client::recv_file(const char* filepath){

    std::ofstream file(filepath, std::ios::binary);
    if(!file.is_open()){
        std::cerr<<"filed to open file\n";
        closesocket(clientSocket);
        WSACleanup();
    }

    
    while((bytesreceived = recv(clientSocket, buffer, BUFFER_SIZE, 0))> 0){
        file.write(buffer,bytesreceived);
    }
    if(bytesreceived == SOCKET_ERROR){
        std::cerr<<"Received failed\n";
    }else{
        std::cout<<"File received successfully\n";
    }

    file.close();
    closesocket(clientSocket);
    WSACleanup();

}