#ifndef Driver_HPP_INCLUDED
#define Driver_HPP_INCLUDED
#include<iostream>
#include"Staff.hpp"
using namespace std;

class Driver : public Staff
{
public:
    Driver(){}
    Driver(unsigned int no, string name):Staff(no, name)
    {

    }
    void print ()
    {
        cout<<"Driver ";
        Staff::print();
    }
};

#endif // Driver_HPP_INCLUDED
