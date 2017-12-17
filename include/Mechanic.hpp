#ifndef Mechanic_HPP_INCLUDED
#define Mechanic_HPP_INCLUDED
#include<iostream>
#include"Staff.hpp"
using namespace std;

class Mechanic : public Staff
{
public:
    Mechanic(){}
    Mechanic(unsigned int no, string name):Staff(no, name, 35)
    {

    }
    void print ()
    {
        cout<<"Mechanic ";
        Staff::print();
    }
};

#endif // Mechanic_HPP_INCLUDED
