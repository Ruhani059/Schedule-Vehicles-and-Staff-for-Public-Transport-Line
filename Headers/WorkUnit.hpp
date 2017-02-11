#ifndef WorkUnit_HPP_INCLUDED
#define WorkUnit_HPP_INCLUDED
#include<iostream>
#include"Time.hpp"
#include"Vehicle.hpp"
#include"Staff.hpp"
using namespace std;

class WorkUnit
{
protected:
    Time startOfWorkUnit;   //store the Time a planned/done work unit lasts.
    Time endOfWorkUnit;
    Vehicle *vehicle;   //driven or maintained during a work unit.
    Staff *staff;    //drive or maintain a Vehicle in a work unit.
public:
    WorkUnit(Time startOfWorkUnit, unsigned int minutes, Vehicle *vehicle, Staff *staff)
//    : startOfWorkUnit(startOfWorkUnit)
    {
        this->startOfWorkUnit = startOfWorkUnit;
        this->endOfWorkUnit = this->startOfWorkUnit + minutes;
        this->vehicle = vehicle;
        this->staff = staff;
    }
    virtual void print()
    {
    }
};

#endif // WorkUnit_HPP_INCLUDED
