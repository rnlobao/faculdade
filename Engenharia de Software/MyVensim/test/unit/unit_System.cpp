#include <assert.h>
#include "unit_System.h" 

using namespace std;

void unit_system_constructor(){
    cout << "System constructor" << endl;
    System* system1 = new SystemImpl();
    assert(system1->getName() == "");
    assert(system1->getValue() == 0.0);
    cout << "Done" << endl;
    delete(system1);

    cout << "System constructor with parameters" << endl; 
    System* system2 = new SystemImpl("Test1", 1.0);
    assert(system2->getName() == "Test1");
    assert(system2->getValue() == 1.0);
    cout << "Done"<< endl;
    delete(system2);
}

void unit_system_getName(){
    cout << "System getName()" << endl;
    System* system = new SystemImpl("Test System", 10.0);
    assert(system->getName() == "Test System");
    cout << "Done" << endl;
}

void unit_system_setName(){
    cout << "System setName()" << endl;
    System* system = new SystemImpl("Test System", 10.0);
    system->setName("Altered Name");
    assert(system->getName() == "Altered Name");
    cout << "Done" << endl;
}

void unit_system_getValue(){
    cout << "System getValue()" << endl;
    System* system = new SystemImpl("Test System", 10.0);
    assert(system->getValue() == 10.0);
    cout << "Done" << endl;
}

void unit_system_setValue(){
    cout << "System setValue()" << endl;
    System* system = new SystemImpl("Test System", 10.0);
    system->setValue(20.0);
    assert(system->getValue() == 20.0);
    cout << "Done" << endl;
}

void run_unit_tests_system(){
    UnitSystem* unit_sys = new UnitSystem();
    unit_system_constructor();
    unit_system_getName();
    unit_system_setName();
    unit_system_getValue();
    unit_system_setValue();
    delete(unit_sys);
}