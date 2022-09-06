#include "SystemImpl.h"

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

double SystemImpl::getValue() const {
    return value;
}

