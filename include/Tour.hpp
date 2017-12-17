#ifndef Tour_HPP_INCLUDED
#define Tour_HPP_INCLUDED
#include<iostream>
#include"WorkUnit.hpp"
using namespace std;

class Tour : public WorkUnit
{
public:
    Tour(Time startOfWorkUnit, unsigned int minutes, Vehicle *vehicle, Staff *staff)
    :WorkUnit(startOfWorkUnit,minutes,vehicle,staff)
    {
    }
    void print()
    {
       cout<<"tour at "<<this->startOfWorkUnit<<": ";
       this->vehicle->print();
       cout<<"; ";
       this->staff->print();
       cout<<" (until ";
       cout<<this->endOfWorkUnit;
       cout<<")";
    }
};

#endif // Tour_HPP_INCLUDED
