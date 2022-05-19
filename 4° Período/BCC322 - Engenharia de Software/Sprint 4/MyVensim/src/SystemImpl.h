#ifndef SYSTEMIMPL_H
#define SYSTEMIMPL_H

#include "System.h"

using namespace std;

class SystemImpl : public System{

    protected:
        string name; 
        double value; 
        SystemImpl& operator=(const SystemImpl& sys);

    public:
        SystemImpl (const SystemImpl& sys);

        friend class Flow;
        friend class ModelImpl; 
        friend class UnitSystem; 

       
        SystemImpl(string name = "", double value = 0.0);

        virtual ~SystemImpl();

        void setName(string sysName);

        string getName() const;
   
        void setValue(double sysValue);

        double getValue() const;     
};


#endif