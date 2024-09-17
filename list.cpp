

#include "list.hpp"

void stack::stack_init(){

int choice;
std::cout<<"!!!!WELCOME TO STACK CONTAINER!!!!\n";
do{
    std::cout<<"Menu: \n";
    std::cout<<"\tpress 1) Display\n\tpress 2) Push\n\tpress 3) POP\n\tpress 0) EXIT\n";
    std::cin>>choice;

switch (choice)
{
    case 1: stack::display();
        break;
            
    case 2: 
        int val;
        if(is_full()){
            std::cout<<"stack is overflow\n";
        }else{
            std::cout<<"Enter value to push on stack : ";
            std::cin>>val;
            stack::push(val);
        }
        break;

    case 3: if(is_empty()){
                std::cout<<"Stack is Empty\n";
            }else{
                int pop = stack::pop();
                std::cout<<"POP element is "<<pop<<std::endl;
            }
        break;
    
    case 0:
        std::cout<<"!!!Thanks for your Time!!!\n";
        break;

    default:
        std::cout<<"invalid input!!!\n";
        break;
    }

    }while(choice != 0);
}

int stack::is_full(){
    if(top == SIZE-1)
        return 1;
    else
        return 0;
}

int stack::is_empty(){
    if(top == -1)
        return 1;
    else
        return 0;
}

void stack::push(int val){
    if(top == SIZE - 1)
        std::cout<<"stack is overflow\n";
    else{
        top++;
        arr[top] = val;
    }
}

int stack::pop(){
    int pop;
    if(top == -1)
        std::cout<<"Stack is Empty!!!\n";
    else{
        pop = arr[top];
        arr[top] = 0;
        top--;
    }
    return pop;
}

void stack::display(){
    std::cout<<"Stack Elements : \n";

    for(int i = SIZE - 1; i >=0; --i){
        std::cout<<arr[i]<<std::endl;
    }
}

