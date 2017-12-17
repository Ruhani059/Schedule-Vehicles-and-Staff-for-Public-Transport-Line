#ifndef Tram_HPP_INCLUDED
#define Tram_HPP_INCLUDED
#include<iostream>
#include"Vehicle.hpp"
using namespace std;

class Tram : public Vehicle
{
public:
    Tram(unsigned int no, string model,
            unsigned int hoursToNextMaintenance, unsigned int minutesForMaintenance)
            :Vehicle(no,model,hoursToNextMaintenance,minutesForMaintenance)
    {

    }
    void print()
    {
        cout<<"Tram ";
        Vehicle::print();
    }
};

#endif // Tram_HPP_INCLUDED
