#ifndef FLOW_H
#define FLOW_H

#include <string>
#include "./System.h"

using namespace std;

class Flow{
    protected:
        string name;
        System* source; 
        System* target; 
    public:
        friend class Model; 
        Flow(){};
        Flow(string name = "", System* source = NULL, System* target = NULL):name(name), source(source), target(target){}
        virtual ~Flow(){}
        virtual double execute() = 0;
        string getName();
        void setName(string flowName);
        System* getSource();
        void setSource(System* sourceSys);
        void clearSource();
        System* getTarget();
        void setTarget(System* targetSys);
        void clearTarget();
    private:
        Flow (const Flow& flow);
        Flow& operator=(const Flow& flow);
};

#endif