#ifndef LineSchedule_HPP_INCLUDED
#define LineSchedule_HPP_INCLUDED
#include<iostream>
#include"Line.hpp"
#include"Vehicle.hpp"
#include"Bus.hpp"
#include"LocalBus.hpp"
#include"LongDistanceBus.hpp"
#include"Tram.hpp"
#include"Staff.hpp"
#include"Driver.hpp"
#include"Mechanic.hpp"
#include"WorkUnit.hpp"
#include"Tour.hpp"
#include"Maintenace.hpp"

using namespace std;

class LineSchedule
{
private:
    const int maxVehicles;
    const int maxStaff;
    const int maxMinutesInWorkingShift;
    const int maxWorkUnits;

    int vehicles;
    int persons;
    int workUnits;

    Line *linePointer;
    Vehicle *vehiclePointer[10];
    Staff *staffPointer[20];
    WorkUnit *workUnitPointer[1920];
public:
    LineSchedule(Line *line,int maxVehicles = 10, int maxStaff = 20,
                 int maxMinutesInWorkingShift = 480, int maxWorkUnits = 1980)
        :maxVehicles(maxVehicles),maxStaff(maxStaff),
        maxMinutesInWorkingShift(maxMinutesInWorkingShift),
        maxWorkUnits(maxWorkUnits)
    {
        linePointer = line;

        cout<<*linePointer<<endl;
        linePointer->print_route();
        cout<<endl;
        linePointer->print_startTime(1);
        cout<<endl<<endl;
        linePointer->print_startTime(2);
        cout<<endl<<endl;

        vehicles = this->maxVehicles;
        persons = this->maxStaff;
        workUnits = this->maxWorkUnits;


        //Vehicle Declaration
        string nameVehicle [] = {"MAN Lion's City", "MAN Lion's Coach", "Siemens Avenio"};

        for(int i=0;i<vehicles;i++)
        {
            //innitialising LocalBus
            if(i<vehicles-2)
            {
                LocalBus *tempBus = new LocalBus(i+100,"MAN Lion's City",100,60);
                vehiclePointer[i] = tempBus;
            }
            //initialising LongDistanceBus
            if(i==vehicles-2)
            {
                LongDistanceBus *tempBus = new LongDistanceBus(i+100,"MAN Lion's Coach",1500,90);
                vehiclePointer[i] = tempBus;
            }
            //initialising Tram
            if(i==vehicles-1)
            {
                Tram *tempBus = new Tram(i+100,"Siemens Avenio",6000,120);
                vehiclePointer[i] = tempBus;
            }

        }

        //Staff Declearation
        string nameStaff [] = {"Jack Fix", "Jo Repair", "Tina Quick", "Jim Street", "Max Hurry",
            "Maria Slow", "Mia Wheel", "Lea Rocket", "Michael Run", "Sara Rapid",
            "Alan Speed", "Ben Unhasty", "Nicole Fast", "Robert Rush", "Lucy Power",
            "John Drive", "George Beam", "Sam Jumper", "Tony Metro", "Lara Hasty"};

        for(int i = 0 ; i< persons; i++)
        {
            if(i < 2)   // two mechanics
            {
                Mechanic *tempStaff = new Mechanic(i+5001,nameStaff[i]);
                staffPointer[i] = tempStaff;
            }
            else        // 18 drivers
            {
                Driver *tempStaff = new Driver(i+999,nameStaff[i]);
                staffPointer[i] = tempStaff;
            }
        }

        //WorkUnit Section
        Time startingTime(07,30);
        for(int i=0;i<=vehicles;i++)
        {
            //local Bus maintenance
            if(i<vehicles-2)
            {
                Vehicle *vh = vehiclePointer[i];
                Staff *st = staffPointer[0];
                st->addWorkingMinutes(vh->get_minutesForMaintenance());
                st->newWorkingShift();

                Maintenace *mtemp = new Maintenace(startingTime, vh->get_minutesForMaintenance(),vh,st);

                startingTime = startingTime + vh->get_minutesForMaintenance();
                workUnitPointer[i] = mtemp;
            }
            //LongDistanceBus Maintanace
            if(i == vehicles-2)
            {
                Vehicle *vh = vehiclePointer[i];
                Staff *st = staffPointer[0];
                st->addWorkingMinutes(vh->get_minutesForMaintenance());
                st->newWorkingShift();
                startingTime.Time_add(07,30);

                Maintenace *mtemp = new Maintenace(startingTime, vh->get_minutesForMaintenance(),vh,st);

                startingTime = startingTime + vh->get_minutesForMaintenance();
                workUnitPointer[i] = mtemp;
            }
            //Tram maintenance
            if(i == vehicles-1)
            {
                Vehicle *vh = vehiclePointer[i];
                Staff *st = staffPointer[1];
                st->addWorkingMinutes(vh->get_minutesForMaintenance());
                st->newWorkingShift();
                startingTime.Time_add(07,30);

                Maintenace *mtemp = new Maintenace(startingTime, vh->get_minutesForMaintenance(),vh,st);

                startingTime = startingTime + vh->get_minutesForMaintenance();
                workUnitPointer[i] = mtemp;
            }

        }

        int BusIdMonday[] = {100,101,102,100,101,103,
                            102,104,100,101,103,102,104,100,101,103,102,104,100,101,103,102,104,100,101,103,102,104,100,101,103,
                            102,104,100,101,103,102,104,100,101,103,102,104,100,101,103,102,104,100,101,103,102,104,100,101,103,
                            102,104,100,101,102,100,101,102,100,101};

        int DriverIdMonday[] = {1,2,3,1,2,4,
                            3,5,1,2,4,3,5,1,2,4,3,5,1,2,4,3,5,1,2,4,
                            3,5,6,7,4,8,5,6,7,9,
                            8,10,6,7,9,8,10,6,7,9,8,10,6,7,9,8,10,6,7,9,
                            8,10,11,9,10,11,12,13,11,12};

        int travelDuration = 74;    //74 minute;

        cout<<"which Line (0 or > 1000 end): ";

        int currentIndexOfWorkUnitPointer = 9;
        for (int day=0;day<5;day++)
        {
            Departuret *temp = linePointer->get_mondaysToFridays();
            int BusIDIndex=100,DriverIDIndex=1,sizeD=66,increment=0;

            do{
                Time t=temp->get_leave();
                temp=temp->get_next();

                Vehicle *vh = vehiclePointer[BusIdMonday[increment]-100];

                Staff *st = staffPointer[DriverIdMonday[increment]+DriverIDIndex];

                Tour *mtemp = new Tour(t,travelDuration,vh,st);

                vh->addDrivingMinutes(travelDuration);
                st->addWorkingMinutes(travelDuration);
                st->newWorkingShift();
                workUnitPointer[++currentIndexOfWorkUnitPointer] = mtemp;

                increment++;
            }while(temp);
            cout<<"day schedule finished"<<endl;
        }

        int BusIdSaturday[] = {100,101,102,100,101,102,100,101,102,100,101,102,100,101,102,100,101,102,
                                100,101,102,100,101,102,100,101,102,100,101,102,100,101,102,
                                100,101,102,100,101,102};
        int DriverIdSaturday[] = {1,2,3,1,2,3,4,5,6,
                                    4,5,6,7,8,9,7,8,9,10,11,12,
                                    10,11,12,13,11,12,13,11,12,13,11,12,13,11,12,13,14,15};

        Departuret *temp = linePointer->get_saturdays();
        int BusIDIndex=100,DriverIDIndex=1,sizeD=39,increment=0;

        do{
            Time t=temp->get_leave();
            temp=temp->get_next();

            Vehicle *vh = vehiclePointer[BusIdSaturday[increment]-100];

            Staff *st = staffPointer[DriverIdSaturday[increment] + DriverIDIndex];

            Tour *mtemp = new Tour(t,travelDuration,vh,st);

            vh->addDrivingMinutes(travelDuration);
            st->addWorkingMinutes(travelDuration);
            st->newWorkingShift();

            workUnitPointer[++currentIndexOfWorkUnitPointer] = mtemp;
            increment++;

        }while(temp);
        cout<<"day schedule finished"<<endl;

    }
    void print_workUnits()
    {
        cout<<"\nWORK UNITS\n==========\n\n";
        for(int i=0;i<379;i++)
        {
            WorkUnit *temp = workUnitPointer[i];
            temp->print();
            cout<<endl;
        }

    }
    void print_statistics()
    {
        cout<<"\nWEEK STATISTICS\n===============\n\n";
        cout<<"Vehicles\n========\n";
        for(int i=0;i<vehicles;i++)
        {
            Vehicle *temp = vehiclePointer[i];
            temp->print();
            temp->print_statistics();
            cout<<endl;
        }

        cout<<"\nStaff\n=====\n";
        for(int i=0;i<persons;i++)
        {
            Staff *temp = staffPointer[i];
            temp->print();
            temp->print_statistics();
            cout<<endl;
        }
    }
};



#endif // LineSchedule_HPP_INCLUDED
