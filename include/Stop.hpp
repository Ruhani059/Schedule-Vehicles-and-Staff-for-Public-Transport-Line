#ifndef Stop_HPP_INCLUDED
#define Stop_HPP_INCLUDED
#include<iostream>
#include"Time.hpp"
#include<string.h>
using namespace std;

class Stop
{
public:
    Stop()
    {
        Time_to_reach=0;
        strcpy(text,"\0");
        next=NULL;
    }
    Stop(const char b[],int a)
    {
        Time_to_reach=a;
        strcpy(text,b);
        next=NULL;
    }
    void set_name(const char *a)
    {
        strcpy(text,a);
        strcat(text,"\0");
    }
    void set_reacht(int t)
    {
        Time_to_reach=t;
    }
    void set_next(Stop *n)
    {
        next=n;
    }
    char* get_text()
    {
        return this->text;
    }
    int get_Time()
    {
        return this->Time_to_reach;
    }
    Stop* get_next()
    {
        return next;
    }
private:
    int Time_to_reach;
    char text[255];
    Stop *next;
};

#endif // Stop_HPP_INCLUDED
