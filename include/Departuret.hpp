#ifndef Departuret_HPP_INCLUDED
#define Departuret_HPP_INCLUDED
#include<iostream>
#include"Time.hpp"
using namespace std;

class Departuret{
public:
    Departuret()
    {
        next=NULL;
    }
    Departuret(int h,int m)
    {
        leave.hour=h;
        leave.minute=m;
        leave.day_min=h*60+m;
        next=NULL;
    }
    Time get_leave()
    {
        return leave;
    }
    Departuret* get_next()
    {
        return next;
    }
    void set_next(Departuret * b)
    {
        next=b;
    }
private:
    Time leave;
    Departuret *next;
};


#endif // Departuret_HPP_INCLUDED
