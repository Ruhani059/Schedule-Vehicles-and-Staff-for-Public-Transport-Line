#ifndef Bus_HPP_INCLUDED
#define Bus_HPP_INCLUDED
#include<iostream>
#include"Vehicle.hpp"
using namespace std;

class Bus : public Vehicle
{
public:
    Bus(unsigned int no, string model,
            unsigned int hoursToNextMaintenance, unsigned int minutesForMaintenance)
            :Vehicle(no,model,hoursToNextMaintenance,minutesForMaintenance)
    {

    }
    void print()
    {
        cout<<"Bus ";
        Vehicle::print();
    }
};

#endif // Bus_HPP_INCLUDED
