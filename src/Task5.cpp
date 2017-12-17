#include<iostream>
#include<string.h>
#include "../include/Stop.hpp"
#include "../include/Departuret.hpp"
#include "../include/Line.hpp"
#include "../include/LineSchedule.hpp"

using namespace std;

void Task5(){

    Line VRR[1000];
    Departuret *mm, *nn;
    mm = &m1;
    nn = &n1;
    Time t();
    routedatawrite();
    depTimewrite();

    VRR[933].seT_no(933);
    VRR[933].seT_from(&s1);
    VRR[933].set_depTime(1,nn);
    VRR[933].set_depTime(2,mm);

    Line *Line1;
    Line1 = &VRR[933];
    LineSchedule ls(Line1,10,20,480,1920);
    ls.print_workUnits();
    ls.print_statistics();
}
