#ifndef Time_HPP_INCLUDED
#define Time_HPP_INCLUDED
#include<iostream>
using namespace std;

class Time {
public:
    int minute;
    int hour;
    int day_min;
    bool next_day;
    Time(void)
    {
        this->minute=0;
        this->hour=0;
        this->day_min=0;
        this->next_day=false;
    }
    Time(int h,int m)
    {
        this->hour=h;
        this->minute=m;
        this->day_min=this->hour*60+this->minute;
        this->next_day=false;
    }
    void Time_add(int a,int b){
        this->hour=a;
        this->minute=b;
        this->day_min=this->hour*60+this->minute;
    }
    void print()
    {
        cout<<this->hour<<":"<<this->minute;
    }
    Time operator+(const int& m )
    {
        Time t;
        int h;
        h=this->minute+m;
        if(h>59)
        {
            t.hour=this->hour+h/60;
            t.minute=h%60;
        }
        else
        {
            t.hour=this->hour;
            t.minute=h;
        }
        this->day_min=this->hour*60+this->minute;
        if(t.hour>=24)
        {
            t.hour -=24;
            t.next_day=true;
        }
        return t;
    }
    int operator>(const Time&b)
    {
        int o;
        if (this->day_min>b.day_min) o=1;
        else o=0;
        return o;
    }
    int operator<(const Time&b)
    {
        int o;
        if (this->day_min<b.day_min) o=1;
        else o=0;
        return o;
    }
    int operator==(const Time&b)
    {
        int o;
        if (this->day_min==b.day_min) o=1;
        else o=0;
        return o;
    }
    void operator=(const Time&b)
    {
        this->hour=b.hour;
        this->minute=b.minute;
        this->day_min=b.day_min;
        return;
    }
    friend istream &operator>>(istream &input,Time &t)
    {
        input >>t.hour>>t.minute;
        t.day_min=t.hour*60+t.minute;
        return input;
    }
    friend ostream &operator<<(ostream &output,const Time t)
    {
        if(t.hour<10) output<<"0"<<t.hour;
        else output<<t.hour;
        output<<":";
        if(t.minute<10) output<<"0"<<t.minute;
        else output<<t.minute;
        if(t.next_day)
        {
            output<<"+";
        }
        return output;
    }
};

#endif // Time_HPP_INCLUDED
