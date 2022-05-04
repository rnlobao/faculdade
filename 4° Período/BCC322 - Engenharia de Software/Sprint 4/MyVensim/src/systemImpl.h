#ifndef SYSTEMIMPL_H
#define SYSTEMIMPL_H

#include "system.h"

using namespace std;

//! Class SystemImpl
/**
* This Class represents a SystemImpl in the General Systems Theory implemented in this code.
*/
class SystemImpl : public System{

    protected:
        string name; /*!< This attribute contains a name for the SystemImpl. */
        double value; /*!< This attribute contains the actual value of the SystemImpl. */

        /*!
            This is the copy constructor for the SystemImpl Class.
            \param sys the SystemImpl that is going to be cloned.
        */
        // SystemImpl (const SystemImpl& sys);

        /*!
            This is the overloaded assignment operator for the SystemImpl Class.
        */
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
        double operator+(const SystemImpl& sys);
        double operator+(const double& valueSys);
        double operator-(const SystemImpl& sys);
        double operator-(const double& valueSys);
        double operator*(const SystemImpl& sys);
        double operator*(const double& valueSys);
        double operator/(const SystemImpl& sys);
        double operator/(const double& valueSys);

};


double operator+(const double& valueSys, const SystemImpl& sys);
double operator-(const double& valueSys, const SystemImpl& sys);
double operator*(const double& valueSys, const SystemImpl& sys);
double operator/(const double& valueSys, const SystemImpl& sys);

#endif