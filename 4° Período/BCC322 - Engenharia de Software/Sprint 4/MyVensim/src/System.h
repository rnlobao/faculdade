#ifndef SYSTEM_H
#define SYSTEM_H

#include <iostream>
#include <string>
#include <ios>
#include <fstream>

using namespace std;

class System{

    public:
        virtual ~System(){}
        virtual void setName(string sysName) = 0;
        virtual string getName() const = 0;
        virtual void setValue(double sysValue) = 0;
        virtual double getValue() const = 0;
        double operator+(const System& sys);
        double operator+(const double& valueSys);
        double operator-(const System& sys);
        double operator-(const double& valueSys);
        double operator*(const System& sys);
        double operator*(const double& valueSys);
        double operator/(const System& sys);
        double operator/(const double& valueSys);

};


double operator+(const double& valueSys, const System& sys);
double operator-(const double& valueSys, const System& sys);
double operator*(const double& valueSys, const System& sys);
double operator/(const double& valueSys, const System& sys);

#endif