#ifndef UNIT_FLOW
#define UNIT_FLOW

#include "../../src/SystemImpl.h"
#include "../../src/FlowImpl.h"

using namespace std;

class UnitFlow{

    public:
        UnitFlow(){}
        ~UnitFlow(){}

        void unit_flow_copy_constructor();
        void unit_flow_assingmentOperator();

};

class ExponencialFlow : public FlowImpl{
    public:
      
        ExponencialFlow(string name = "", System* source = NULL, System* target = NULL): FlowImpl(name, source, target){}
        
        double execute(){
            if (getSource() != NULL){
                return (0.01 * getSource()->getValue());
            }
            else{
                return 0;
            }
        }
};

void unit_flow_constructor();

void unit_flow_destructor();

void unit_flow_getName();

void unit_flow_setName();

void unit_flow_getSource();

void unit_flow_setSource();

void unit_flow_clearSource();

void unit_flow_getTarget();

void unit_flow_setTarget();

void unit_flow_clearTarget();

void unit_flow_execute();

void run_unit_tests_flow();

#endif