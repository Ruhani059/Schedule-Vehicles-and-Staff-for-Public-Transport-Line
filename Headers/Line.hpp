#ifndef Line_HPP_INCLUDED
#define Line_HPP_INCLUDED
#include <iostream>
#include"Time.hpp"
#include"Stop.hpp"
#include"Departuret.hpp"
using namespace std;

class Line
{
public:
    Line()
    {
        no=0;
        mondayToFriday=NULL;
        Saturday=NULL;
        SundaysAndHoliday=NULL;
    }
    Line(int i, Stop *t)
    {
        no=i;
        from=*t;
        mondayToFriday=NULL;
        Saturday=NULL;
        SundaysAndHoliday=NULL;
    }
    Departuret insrt(Departuret newh,Departuret *oldh)
    {
        newh.set_next(oldh);
        return newh;
    }
    char* get_from()
    {
        return from.get_text();
    }
    char* get_to()
    {
        Stop *p;
        p=&from;
        while(1) {
            if(p->get_next()==NULL) {
                break;
            }else {
                p=p->get_next();
            }
        }
        return p->get_text();
    }
    int get_duration()
    {
        Stop *p;
        p=&from;
        int duration=0;
        while(1) {
               //duration=duration+ p->get_Time();
            if(p->get_next()==NULL) {
                break;
            }else {
                p=p->get_next();
            }
        }
        duration=p->get_Time();
        return duration;
    }
    void addonMondaytoFriday(Departuret a)
    {
        insrt(a,mondayToFriday);
        mondayToFriday=&a;
    }
    void addonSaturday(Departuret a)
    {
        insrt(a,Saturday);
        Saturday=&a;
    }
    void addonSundayandPublicholiday(Departuret a)
    {
        insrt(a,SundaysAndHoliday);
        SundaysAndHoliday=&a;
    }

    void print_route()
    {
        cout<<"route of the Line "<<no<<":"<<endl;
        Stop *p;
        p=&from;
        while(1)
        {
            cout<<(p->get_Time())<<"\t"<<(p->get_text())<<endl;

            if(p->get_next()==NULL) {
                break;
            }else {
                p=p->get_next();
            }
        }
    }
    friend ostream &operator<<(ostream &output,Line l)
    {
        output<<"Line:\t\t"<<l.no<<endl<<"From:\t\t"<<l.get_from()<<endl<<"To:\t\t"<<l.get_to()<<endl<<"Duration:\t"<<l.get_duration()<<" min"<<endl;
        return output;
    }
    void set_depTime(int a,Departuret *b)
    {
        if(a==1) {
            Departuret *temp = new Departuret();
            temp = b;
            mondayToFriday=temp;
        }
        if(a==2) {
            Departuret *temp = new Departuret();
            temp = b;
            Saturday=temp;
        }
        if(a==3) {
            Departuret *temp = new Departuret();
            temp = b;
            SundaysAndHoliday=temp;
        }
    }
    void print_schedule(int type,Time t)
    {
        int found=0;
        if(type==1) {
            if(mondayToFriday==NULL) {
                cout<<"Sorry!No data available"<<endl;
                return;
            }
            cout<<"Line "<<no<<". Service on Monday to Friday:"<<endl;
            Time start;
            Time temp;
            Departuret t2;
            t2=*mondayToFriday;
            do{
               if(t2.get_leave()==t) {
                    start=t2.get_leave();
                    temp=t;
                    found=1;
                    break;
               }
               else t2=*t2.get_next();
            }while(t2.get_next());
            if(found) print_sc(from,temp);
        }
        if(type==2) {
                if(Saturday==NULL) {
                    cout<<"Sorry!No data available"<<endl;
                    return;
                }
            cout<<"Line "<<no<<". Service on Saturday:"<<endl;
            Time start;
            Time temp;
            Departuret t2;
            t2=*Saturday;
            cin.get();
            do{
               if(t2.get_leave()==t) {
                    start=t2.get_leave();
                    temp=t;
                    found=1;
                    break;
               }
               else t2=*t2.get_next();
            }while(t2.get_next());
            if(found) print_sc(from,temp);
        }
        if(type==3) {
                if(SundaysAndHoliday==NULL) {
                    cout<<"Sorry!No data available"<<endl;
                    return;
                }
            cout<<"Line "<<no<<". Service on Sunday and other holiday:"<<endl;
            Time start;
            Time temp;
            Departuret t2;
            t2=*SundaysAndHoliday;
            cin.get();
            do{
               if(t2.get_leave()==t) {
                    start=t2.get_leave();
                    temp=t;
                    found=1;
                    break;
               }
               else t2=*t2.get_next();
            }while(t2.get_next());
            if(found) print_sc(from,temp);
        }
    }
    void print_sc(Stop a,Time start)
    {
        Stop *p;
        p=&a;
        while(1) {
            cout<<"\t"<<(p->get_text())<<"\t"<<(start+(p->get_Time()))<<endl;

            if(p->get_next()==NULL) {
                break;
            }else {
                p=p->get_next();
            }
        }
    }
    void print_startTime(int i)
    {
        Departuret *temp;
        Departuret *flag;
        Time t;
        int j=0;
        if(i==1)
        {
            temp=mondayToFriday;
            cout<<"Time schedule for Monday to Friday is: "<<endl;
            do{
                j++;
                t=temp->get_leave();
                cout<<t<<"\t";
                temp=temp->get_next();
                if(!temp->get_next()) cout<<temp->get_leave()<<"\t";
                if(!(j%7)) cout<<endl;
             }while(temp->get_next());
        }
        if(i==2) {
                temp=Saturday;
                cout<<"Time schedule for Saturday is: "<<endl;
             do{
                j++;
                t=temp->get_leave();
                cout<<t<<"\t";
                temp=temp->get_next();
                if(!temp->get_next()) cout<<temp->get_leave()<<"\t";
                if(!(j%7)) cout<<endl;
             }while(temp->get_next());
        }
        if(i==3) {
                temp=SundaysAndHoliday;
                cout<<"\nTime schedule for Sunday and other holiday if: "<<endl;
             do{
                j++;
                t=temp->get_leave();
                cout<<t<<"\t";
                temp=temp->get_next();
                if(!temp->get_next()) cout<<temp->get_leave()<<"\t";
                if(!(j%7)) cout<<endl;
             }while(temp->get_next());
        }
    }
    void seT_no(int i)
    {
        no=i;
    }
    int geT_no()
    {
        return no;
    }
    void seT_from(Stop *t)
    {
       from =*t;
    }
    Departuret* get_mondaysToFridays()
    {
        return this->mondayToFriday;
    }
    Departuret* get_saturdays()
    {
        return this->Saturday;
    }
    Departuret* get_sundaysAndPublicHolidays()
    {
        return this->SundaysAndHoliday;
    }

private:
    int no;
    //int duration;
    //Stop to;
    Stop from;
    Departuret *mondayToFriday,*Saturday, *SundaysAndHoliday;
};

#endif // Line_HPP_INCLUDED

