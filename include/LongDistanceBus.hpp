#ifndef LongDistanceBus_HPP_INCLUDED
#define LongDistanceBus_HPP_INCLUDED
#include<iostream>
#include"Bus.hpp"
using namespace std;

class LongDistanceBus : public Bus
{
public:
    LongDistanceBus(unsigned int no, string model,
            unsigned int hoursToNextMaintenance, unsigned int minutesForMaintenance)
            :Bus(no,model,hoursToNextMaintenance,minutesForMaintenance)
    {

    }

    void print()
    {
        cout<<"long distance ";
        Bus::print();
    }

} ;

#endif // LongDistanceBus_HPP_INCLUDED
