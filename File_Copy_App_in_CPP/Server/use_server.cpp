
#include "server.hpp"

Server s1;

int main(int argc, const char* argv[] ){
    
    const char* filepath = argv[1];

    s1.do_work(filepath);

    return 0;
}