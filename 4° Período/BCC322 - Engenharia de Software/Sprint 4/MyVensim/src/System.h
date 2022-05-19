#ifndef SYSTEM_H
#define SYSTEM_H

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class System{
    public:
        virtual ~System(){}
        virtual void setName(string sysName) = 0;
        virtual string getName() = 0;
        virtual void setValue(double sysValue) = 0;
        virtual double getValue() = 0;
};

#endif