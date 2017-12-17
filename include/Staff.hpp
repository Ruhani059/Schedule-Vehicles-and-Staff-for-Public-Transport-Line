#ifndef Staff_HPP_INCLUDED
#define Staff_HPP_INCLUDED
#include<iostream>
#include"Time.hpp"
using namespace std;

class Staff
{
private:
    unsigned int no;
    string name;
    bool BusLicense;    // storing whether the person of Staff has a respective driving license
    bool TramLicense;
    unsigned int minutesWorkingShift;   //the count of already done working minutes within a shift work
    unsigned int minutesWorkingWeek;    //the count of already done working minutes within a working week
    unsigned int maxMinutesWorkingWeek; //the count of the minutes to work within a whole working week
    Time endOfLastWorkUnitInShift;  //Time until when the last work unit given in a shift work will last
public:
    Staff(){}
    Staff(unsigned int no, string name, unsigned int minutesWorkingWeek = 40)
    {
        this->no = no;
        this->name = name;
//        this->minutesWorkingWeek = minutesWorkingWeek;
    }
    unsigned int get_no()
    {
        return this->no;
    }
    unsigned int get_minutesInWorkingShift()
    {
        return this->minutesWorkingShift;
    }
    unsigned int get_minutesInWorkingWeek()
    {
        return this->minutesWorkingWeek;
    }
    unsigned int get_maxMinutesInWorkingWeek()
    {
        return this->maxMinutesWorkingWeek;
    }
    Time get_endOfLastWorkUnitInShift()
    {
        return this->endOfLastWorkUnitInShift;
    }
    void set_endOfLastWorkUnitInShift (Time clock_Time)
    {
        this->endOfLastWorkUnitInShift = clock_Time;
    }
    void addWorkingMinutes (unsigned int minutes)
    {
        this->minutesWorkingShift += minutes;
        this->minutesWorkingWeek += minutes;
    }
    void newWorkingShift()
    {
        this->minutesWorkingShift = 0;
        //setting clock Time 00:00 to endOfLastWorkUnitInShift
        Time tempTime(0,0);
        this->endOfLastWorkUnitInShift = tempTime;
    }
    bool hasBusLicense()
    {
        return this->BusLicense;
    }
    bool hasTramLicense()
    {
        return this->TramLicense;
    }
    void setBusLicense()
    {
        this->BusLicense = true;
    }
    void setTramLicense()
    {
        this->TramLicense = true;
    }
    void unsetBusLicense()
    {
        this->BusLicense = false;
    }
    void unsetTramLicense()
    {
        this->TramLicense = false;
    }
    void print_statistics()
    {
        cout<<" working Time: shift ";

        if(this->minutesWorkingShift/60<10)  cout<<"0"<<this->minutesWorkingShift/60;
        else cout<<this->minutesWorkingShift/60;
        cout<<":";
        if(this->minutesWorkingShift%60<10)  cout<<"0"<<this->minutesWorkingShift%60;
        else  cout<<this->minutesWorkingShift%60;

        cout<<", week ";
        if(this->minutesWorkingWeek/60<10)  cout<<"0"<<this->minutesWorkingWeek/60;
        else cout<<this->minutesWorkingWeek/60;
        cout<<":";
        if(this->minutesWorkingWeek%60<10)  cout<<"0"<<this->minutesWorkingWeek%60;
        else  cout<<this->minutesWorkingWeek%60;
    }
    virtual void print()
    {
        cout<<this->no<<" "<<this->name<<"\t";
    }
};

#endif // Staff_HPP_INCLUDED
