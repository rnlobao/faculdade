#ifndef SYSTEM_H
#define SYSTEM_H

#include <string>

using namespace std;

class System{

    protected:
        string name;
        double value; 

    public:
        friend class Flow;
        friend class Model; 

        System(string name = "", double value = 0.0):name(name), value(value){}
        virtual ~System(){}
        void setName(string sysName);
        string getName();
        void setValue(double sysValue);
        double getValue();
    private:
        System (const System& sys);
        System& operator=(const System& sys);
};

#endif