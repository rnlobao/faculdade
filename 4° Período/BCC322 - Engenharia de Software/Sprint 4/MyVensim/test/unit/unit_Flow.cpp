#include "unit_Flow.h"
#include <assert.h>

void unit_flow_constructor() {
    cout << "Flow Constructor" << endl;
    ExponencialFlow* flow1 = new ExponencialFlow();
    assert(flow1->getName() == "");
    assert(flow1->getSource() == NULL);
    assert(flow1->getTarget() == NULL);
    cout << "Done" << endl;

    cout << "Flow constructor with parameters" << endl;
    System* source = new SystemImpl("Test System 1", 5.0);
    System* target = new SystemImpl("Test System 2", 10.0);
    ExponencialFlow* flow2 = new ExponencialFlow("Flow 2", source, target);
    assert(flow2->getName() == "Flow 2");
    assert(flow2->getSource() == source);
    assert(flow2->getTarget() == target);
    cout << "Done" << endl;
}

void UnitFlow::unit_flow_copy_constructor() { 
    cout << "Flow copy constructor" << endl;
    System* sys1 = new SystemImpl("Sys 1", 5.0);
    System* sys2 = new SystemImpl("Sys 2", 6.0);
    ExponencialFlow* flow1 = new ExponencialFlow("Flow 1");
    Flow* flow2 = new ExponencialFlow(*flow1); 
    flow1->setName("Original Flow 1");
    flow1->setSource(sys1);
    flow1->setTarget(sys2);
    assert(flow2->getName() == "Flow 1");
    assert(flow2->getSource() == NULL); 
    assert(flow2->getTarget() == NULL);
    cout << "Done" << endl;
} 

void UnitFlow::unit_flow_assingmentOperator(){
    cout << "Flow assignment operator" << endl;
    System* sys1 = new SystemImpl("Sys 1", 5.0);
    System* sys2 = new SystemImpl("Sys 2", 6.0);
    ExponencialFlow* flow1 = new ExponencialFlow("Flow 1");
    ExponencialFlow* flow2 = new ExponencialFlow();
    *flow2 = *flow1;
    flow1->setName("Original Flow 1");
    flow1->setSource(sys1);
    flow1->setTarget(sys2);
    assert(flow2->getName() == "Flow 1");
    assert(flow2->getSource() == NULL);
    assert(flow2->getTarget() == NULL);
    cout << "Done" << endl;
}

void unit_flow_getName() {
    cout << "Flow getName()" << endl;
    ExponencialFlow* flow = new ExponencialFlow("Flow 1");
    assert(flow->getName() == "Flow 1");
    cout << "Done" << endl;
}

void unit_flow_setName() {
    cout << "Flow setName()" << endl;
    ExponencialFlow* flow = new ExponencialFlow();
    flow->setName("Test Flow");
    assert(flow->getName() == "Test Flow");
    cout << "Done" << endl;
}

void unit_flow_getSource(){
    cout << "Flow getSource()" << endl;
    System* system = new SystemImpl("Test System");
    ExponencialFlow* flow = new ExponencialFlow("Flow 1", system);
    assert(flow->getSource()->getName() == "Test System");
    cout << "Done" << endl;
}

void unit_flow_setSource(){
    cout << "Flow setSource()" << endl;
    System* system = new SystemImpl("Test System");
    ExponencialFlow* flow1 = new ExponencialFlow("Flow 1");
    flow1->setSource(system);
    assert(flow1->getSource()->getName() == "Test System");
    cout << "Done" << endl;
}

void unit_flow_clearSource(){
    cout << "Flow clearSource()" << endl;
    System* system = new SystemImpl("Test System");
    ExponencialFlow* flow1 = new ExponencialFlow("Flow 1",system);
    flow1->clearSource();
    assert(flow1->getSource() == NULL);
    cout << "Done" << endl;
}

void unit_flow_getTarget(){
    cout << "Flow getTarget()" << endl;
    System* system = new SystemImpl("Test System"); 
    ExponencialFlow* flow = new ExponencialFlow("Flow 1",NULL,system);    
    assert(flow->getTarget()->getName() == "Test System");
    cout << "Done" << endl;
}

void unit_flow_setTarget(){
    cout << "Flow setTarget()" << endl;
    System* system = new SystemImpl("Test System");
    ExponencialFlow* flow = new ExponencialFlow("Flow 1");
    flow->setTarget(system);
    assert(flow->getTarget()->getName() == "Test System");
    cout << "Done" << endl;
}

void unit_flow_clearTarget(){
    cout << "Flow clearTarget()" << endl;
    System* system = new SystemImpl("Test System");
    ExponencialFlow* flow = new ExponencialFlow("Flow", NULL, system); 
    flow->clearTarget();
    assert(flow->getTarget() == NULL);
    cout << "Done" << endl;
}

void unit_flow_execute(){
    cout << "Flow execute()" << endl;
    System* system1 = new SystemImpl("Test System 1", 10.0);
    System* system2 = new SystemImpl("Test System 2", 0.0);
    ExponencialFlow* flow = new ExponencialFlow("Flow", system1, system2);
    system2->setValue(flow->execute());
    assert(abs(flow->getTarget()->getValue() - 0.1) < 0.01);
    cout << "Done" << endl;
}

void run_unit_tests_flow() {
    UnitFlow* unit_flow = new UnitFlow();
    unit_flow_constructor();  
    unit_flow->unit_flow_copy_constructor();
    unit_flow_destructor(); 
    unit_flow_getName();
    unit_flow_setName();
    unit_flow_getSource();
    unit_flow_setSource();
    unit_flow_clearSource();
    unit_flow_getTarget();
    unit_flow_setTarget();
    unit_flow_clearTarget();
    unit_flow->unit_flow_assingmentOperator();
    unit_flow_execute();
    delete(unit_flow);
}