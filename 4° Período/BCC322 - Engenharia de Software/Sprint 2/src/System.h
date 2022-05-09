#ifndef SYSTEM_H
#define SYSTEM_H

#include <string>

using namespace std;

class System {
    protected:
        string name;
        double value;

    public:
        friend class Flow;
        friend class Model;

        System(string name = "", double value = 0.0):name(name), value(value){}
 
        virtual ~System(){}

        void setName(string sysName){
            name = sysName;
        }

        string getName() const {
            return name;
        }    

        void setValue(double sysValue){
            value = sysValue;
        }

        double getValue() const{
            return value;
        }  

    private:
        System (const System& s){
            name = s.getName();
            value = s.getValue();
        }

        System& operator=(const System& s){
            if (this == &s){
                return *this;
            }

            name = s.getName();
            value = s.getValue();  

            return *this;
        }
};

#endif