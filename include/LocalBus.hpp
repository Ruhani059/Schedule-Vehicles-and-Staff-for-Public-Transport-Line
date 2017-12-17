#ifndef LocalBus_HPP_INCLUDED
#define LocalBus_HPP_INCLUDED
#include<iostream>
#include"Bus.hpp"
using namespace std;

class LocalBus : public Bus
{
public:
    LocalBus(unsigned int no, string model,
            unsigned int hoursToNextMaintenance, unsigned int minutesForMaintenance)
            :Bus(no,model,hoursToNextMaintenance,minutesForMaintenance)
    {

    }

    void print()
    {
        cout<<"local ";
        Bus::print();
    }
};

#endif // LocalBus_HPP_INCLUDED
