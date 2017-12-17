//
// Created by Ruhani on 12/14/2017.
//
#include <iostream>
#include <conio.h>
#include "src/Task4.cpp"
#include "src/Task5.cpp"

int main()
{
    std::cout<<"Hello Ruhani"<<std::endl;
    int input;
    do{
        std::cout<<std::endl;
        std::cout<<"Welcome to Schedule-Vehicles-and-Staff-for-Public-Transport-Line Project"<<std::endl;
        std::cout<<"1 : Execute Task 4"<<std::endl;
        std::cout<<"2 : Execute Task 5"<<std::endl;
        std::cout<<"0 : Dismiss"<<std::endl<<std::endl;;
        std::cin>>input;
        switch (input) {
            case 1:
                Task4();
                break;
            case 2:
                Task5();
                break;
            default:
                break;
        }
    }while(input != 0);
    getch();
    return 0;
}

