#include <assert.h>
#include "unit_System.h" 

using namespace std;

void unit_system_constructor(){
    cout << "System constructor" << endl;
    System* system1 = new System();
    assert(system1->getName() == "");
    assert(system1->getValue() == 0.0);
    delete(system1);
    cout << "Done" << endl;

    cout << "System constructor with parameters" << endl; 
    System* system2 = new System("Test1", 1.0);
    assert(system2->getName() == "Test1");
    assert(system2->getValue() == 1.0);
    delete(system2);
    cout << "Done"<< endl;
}

void UnitSystem::unit_system_copy_constructor(){
    cout << "System copy constructor" << endl;
    SystemImpl* system1 = new SystemImpl("Test System", 10.0);
    System* system2 = new SystemImpl(*system1);
    system1->setName("Original Test System");
    system1->setValue(20.0);
    assert(system2->getName() == "Test System");
    assert(system2->getValue() == 10.0);
    assert(system1 != system2);
    cout << "Done" << endl;
}

void UnitSystem::unit_system_assingmentOperator(){
    cout << "System assignment operator" << endl;
    SystemImpl* system1 = new SystemImpl("Test System", 10.0);
    SystemImpl* system2 = new SystemImpl();
    *system2 = *system1;
    system1->setName("Original Test System");
    system1->setValue(100.0);
    assert(system2->getName() == "Test System");
    assert(system2->getValue() == 10.0);
    cout << "Done" << endl;
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
    unit_sys->unit_system_copy_constructor();
    unit_system_destructor();
    unit_system_getName();
    unit_system_setName();
    unit_system_getValue();
    unit_system_setValue();
    unit_sys->unit_system_assingmentOperator();
    delete(unit_sys);
}