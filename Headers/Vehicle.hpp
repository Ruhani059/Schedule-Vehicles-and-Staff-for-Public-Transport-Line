#ifndef Vehicle_HPP_INCLUDED
#define Vehicle_HPP_INCLUDED
#include<iostream>
#include"Time.hpp"
using namespace std;

class Vehicle {
private:
    unsigned int no;
    string model;
    bool needsMaintenance;
    unsigned int drivingMinutes;
    const unsigned int hoursToNextMaintenance;
    const unsigned int minutesForMaintenance;
    Time endOfLastWorkUnitInShift;
public:
    Vehicle(unsigned int no, string model,
            unsigned int hoursToNextMaintenance, unsigned int minutesForMaintenance)
            : hoursToNextMaintenance(hoursToNextMaintenance),
            minutesForMaintenance(minutesForMaintenance)
    {
        this->no = no;
        this->model = model;
        this->drivingMinutes = 0;
        this->needsMaintenance = false;
        endOfLastWorkUnitInShift = Time(0,0);

    }
    unsigned int get_no()
    {
        return this->no;
    }
    string get_model()
    {
        return this->model;
    }
    unsigned int get_drivingMinutes()
    {
        return this->drivingMinutes;
    }
    unsigned int get_minutesForMaintenance()
    {
        return this->minutesForMaintenance;
    }
    Time get_endOfLastWorkUnitInShift()
    {
        return this->endOfLastWorkUnitInShift;
    }

    void set_endOfLastWorkUnitInShift(Time clock_Time)
    {
        endOfLastWorkUnitInShift = clock_Time;
    }
    void addDrivingMinutes(unsigned int minutes)
    {
        this->drivingMinutes += minutes;
        if(this->drivingMinutes/60 >= this->hoursToNextMaintenance)
        {
            this->needsMaintenance = true;
        }
    }
    void maintenanceDone()
    {
        this->needsMaintenance= false;
        this->drivingMinutes = 0;
    }
    void print_statistics()
    {
        cout<<" ("<<this->model<<") driving Time: ";
        if(this->drivingMinutes/60<10)  cout<<"0"<<this->drivingMinutes/60;
        else cout<<this->drivingMinutes/60;
        cout<<":";
        if(this->drivingMinutes%60<10)  cout<<"0"<<this->drivingMinutes%60;
        else  cout<<this->drivingMinutes%60;
//        cout<<" ("<<this->model<<") driving Time: "<<this->drivingMinutes;
        if(this->needsMaintenance)
        {
            cout<<"(*)";
        }
//        cout<<"\t"<<this->hoursToNextMaintenance;
    }
    virtual void print()
    {
        cout<<this->no;
//        this->print_statistics();
    }
};

#endif // Vehicle_HPP_INCLUDED
