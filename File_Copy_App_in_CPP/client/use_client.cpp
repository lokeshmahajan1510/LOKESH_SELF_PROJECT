#include "client.hpp"

Client c1;

int main(int argc, const char* argv[]){

    const char* filepath = argv[1];
    c1.do_work(filepath);

    return 0;
}