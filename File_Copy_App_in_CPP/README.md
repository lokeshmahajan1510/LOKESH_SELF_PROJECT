# This is application for copying file from one location to another location in same machine with the help of WINSOCK API'S

- On Server side ip address as 0.0.0.0
- On Client side ip address as <your_PC_ip>

#for RUNNING THIS APPLICATION
- For server : 
    g++ server.cpp use_server.cpp -o server -lws2_32
    ./server.exe <PATH_of_Targeted_FILE>

- For Client :
    g++ client.cpp use_client.cpp -o client -lws2_32
    ./client.exe <Path_of_location_where_to_copy>
    
    
