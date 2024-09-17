#ifndef _LIST_HPP
#define _LIST_HPP

#include <iostream>

#define SIZE 5

class stack{
    public:
        stack(){
            top = -1;
            for(int i = 0; i < SIZE; i++){
                arr[i] = 0;
            }
        }    
        void stack_init();

    private:
        int top;
        int arr[SIZE];

        int is_full();
        int is_empty();
        void push(int val);
        int pop();
        void display();
    };


#endif

