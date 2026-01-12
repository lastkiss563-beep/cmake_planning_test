#include<iostream>
#include "process.h"
using std::cout, std::endl;

void Process::planProcess()
{
    cout << "this is panning process" << endl;
    my_map.mapInfo();
    cout << "planning success1" << endl;
}