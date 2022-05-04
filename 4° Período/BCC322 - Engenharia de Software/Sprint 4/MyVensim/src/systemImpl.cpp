#include "systemImpl.h"

using namespace std;

SystemImpl::SystemImpl (const SystemImpl& sys){
    if (this == &sys){
        return;
    }
    
    name = sys.getName();
    value = sys.getValue();           
}

SystemImpl& SystemImpl::operator=(const SystemImpl& sys){
    if (this == &sys){
        return *this;
    }

    setName(sys.getName());
    setValue(sys.getValue());          

    return *this;
}

SystemImpl::SystemImpl(string name, double value):name(name), value(value){}

SystemImpl::~SystemImpl(){}

void SystemImpl::setName(string sysName){
    name = sysName;
}

string SystemImpl::getName() const {
    return name;
}    

void SystemImpl::setValue(double sysValue){
    value = sysValue;
}

double SystemImpl::getValue() const{
    return value;
}

double SystemImpl::operator+(const SystemImpl& sys){
    if (this == &sys){
        return 2.0 * getValue();
    }

    return getValue() + sys.getValue();
}

double SystemImpl::operator+(const double& valueSys){
    return valueSys + getValue();
}


double operator+(const double& valueSys, const SystemImpl& sys){
    return sys.getValue() + valueSys;
}

double  SystemImpl::operator-(const SystemImpl& sys){
    if (this == &sys){
        return 0.0;
    }

    return getValue() - sys.getValue();
}

double SystemImpl::operator-(const double& valueSys){
    return getValue() - valueSys;
}

double operator-(const double& valueSys, const SystemImpl& sys){
    return valueSys - sys.getValue();
}

double SystemImpl::operator*(const SystemImpl& sys){
    if (this == &sys){
        return getValue() * sys.getValue();
    }

    return getValue() * sys.getValue();
}

double SystemImpl::operator*(const double& valueSys){
    return getValue() * valueSys;
}

double operator*(const double& valueSys, const SystemImpl& sys){
    return valueSys * sys.getValue();
}

double SystemImpl::operator/(const SystemImpl& sys){
    if (this == &sys){
        return 1.0;
    }

    return getValue() / sys.getValue();
}

double SystemImpl::operator/(const double& valueSys){
    return getValue() / valueSys;
}

double operator/(const double& valueSys, const SystemImpl& sys){
    return valueSys / sys.getValue();
}