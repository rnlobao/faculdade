#ifndef FLOW_H
#define FLOW_H

#include "./system.h"

using namespace std;

class Flow{
    public:
        friend class Model;
        friend class ModelImpl; 
        friend class UnitFlow; 
        
        virtual ~Flow(){}
        virtual double execute() = 0;
        virtual string getName() const = 0;
        virtual void setName(string flowName) = 0;
        virtual System* getSource() const = 0;
        virtual void setSource(System* sourceSys) = 0;
        virtual void clearSource() = 0;
        virtual System* getTarget() const = 0;
        virtual void setTarget(System* targetSys) = 0;
        virtual void clearTarget() = 0;
};

#endif