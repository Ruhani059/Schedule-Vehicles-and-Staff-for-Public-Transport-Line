#ifndef Maintenace_HPP_INCLUDED
#define Maintenace_HPP_INCLUDED
#include<iostream>
#include"WorkUnit.hpp"
using namespace std;

class Maintenace : public WorkUnit
{
public:
    Maintenace(Time startOfWorkUnit, unsigned int minutes, Vehicle *vehicle, Staff *staff)
    :WorkUnit(startOfWorkUnit,minutes,vehicle,staff)
    {
    }
    void print()
    {
       cout<<"maintenance for ";
       this->vehicle->print();
       cout<<" by ";
       this->staff->print();
       cout<<" from "<<this->startOfWorkUnit;
       cout<<" (until "<<this->endOfWorkUnit<<")";
    }
};

#endif // Maintenace_HPP_INCLUDED
