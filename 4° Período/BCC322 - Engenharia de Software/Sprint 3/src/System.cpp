#include "System.h"
using namespace std;

void System::setName(string sysName)
{
    this->name = sysName;
}

string System::getName() 
{
    return this->name;
}

void System::setValue(double sysValue)
{
    this->value = sysValue;
}

double System::getValue() 
{
    return this->value;
}

System::System(const System &sys)
{
    name = sys.name;
    value = sys.value;
}

System& System::operator=(const System &sys)
{
    if (this == &sys)
    {
        return *this;
    }
    name = sys.name;
    value = sys.value;
    return *this;
}