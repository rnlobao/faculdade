#include <assert.h>
#include "unit_system.h" 

using namespace std;

// Function for System class's constructor unit test.
void unit_system_constructor(){
    cout << "TEST 1 - Default constructor of the System class without passing parameters" << endl;
    
    System* system1 = new SystemImpl();
    // Making assertion to verify if the name property was initialized with the default data.
    assert(system1->getName() == "");
    // Making assertion to verify if the value property was initialized with the default data. 
    assert(system1->getValue() == 0.0);

    cout << GREEN << "OK!" << RESET << endl;

    cout << "TEST 2 - Default constructor of the System class with passing parameters" << endl; 
    
    System* system2 = new SystemImpl("Test System", 10.0);
    // Making assertion to verify if the name property was initialized with the parameter specified.
    assert(system2->getName() == "Test System");
    // Making assertion to verify if the value property was initialized with the parameter specified. 
    assert(system2->getValue() == 10.0);

    cout << GREEN << "OK!"<< RESET << endl;
}

// Function for System class's copy constructor unit test.
void UnitSystem::unit_system_copy_constructor(){
    cout << "TEST 3 - Copy constructor of the System class" << endl;
    
    SystemImpl* system1 = new SystemImpl("Test System", 10.0);
    System* system2 = new SystemImpl(*system1);
    system1->setName("Original Test System");
    system1->setValue(20.0);

    // Making assertion to verify if the name property was copied before the original's alteration.
    assert(system2->getName() == "Test System");
    // Making assertion to verify if the value property was copied before the original's alteration.
    assert(system2->getValue() == 10.0);
    // Making assertion to verify if the System objects aren't pointing to the same memory.
    assert(system1 != system2);

    cout << GREEN << "OK!" << RESET << endl;
}

// Function for the System class' destructor unit test.
void unit_system_destructor(){
    cout << "TEST 4 - Default destructor of the System class" << endl;
    
    double vmBefore, vmAfter, rss;

    // Getting the memory usage previous to the creation of a system.
    memory_usage(vmBefore, rss);
    
    System* system = new SystemImpl("Test System", 10.0);
    delete system;

    // Getting the memory usage after the creation and destruction of a System object.
    memory_usage(vmAfter, rss);

    // Making assertion to verify if the memory usage after the creation and deletion
    // is the same as before the creation of System object.
    assert(vmBefore == vmAfter);

    cout << GREEN << "OK!" << RESET << endl;
}

// Function for System class' method getName() unit test.
void unit_system_getName(){
    cout << "TEST 5 - System class's getName() method" << endl;
    
    System* system = new SystemImpl("Test System", 10.0);

    // Making assertion to verify if the method returns the System class name and if it's
    // equal to the parameter previously passed. 
    assert(system->getName() == "Test System");

    cout << GREEN << "OK!" << RESET << endl;
}

// Function for System class' method setName() unit test.
void unit_system_setName(){
    cout << "TEST 6 - System class's setName() method" << endl;
    
    System* system = new SystemImpl("Test System", 10.0);
    system->setName("Altered Name");

    // Making assertion to verify if the data of the name property has been altered.
    assert(system->getName() == "Altered Name");

    cout << GREEN << "OK!" << RESET << endl;
}

// Function for System class' method getValue() unit test.
void unit_system_getValue(){
    cout << "TEST 7 - System class's getValue() method" << endl;

    System* system = new SystemImpl("Test System", 10.0);

    // Making assertion to verify if the method returns the System class value and if it's
    // equal to the parameter previously passed.
    assert(system->getValue() == 10.0);

    cout << GREEN << "OK!" << RESET << endl;
}

// Function for System class' method setValue() unit test.
void unit_system_setValue(){
    cout << "TEST 8 - System class's setValue() method" << endl;

    System* system = new SystemImpl("Test System", 10.0);
    system->setValue(20.0);
    
    // Making assertion to verify if the data of the value property has been altered.
    assert(system->getValue() == 20.0);

    cout << GREEN << "OK!" << RESET << endl;
}

// Function for System class' assingment operator unit test.
void UnitSystem::unit_system_assingmentOperator(){
    cout << "TEST 9 - System class assignment operator" << endl;
    
    SystemImpl* system1 = new SystemImpl("Test System", 10.0);
    SystemImpl* system2 = new SystemImpl();
    *system2 = *system1;

    system1->setName("Original Test System");
    system1->setValue(100.0);

    // Making assertion to verify if the name property was assigned.
    assert(system2->getName() == "Test System");
    // Making assertion to verify if the value property was assigned.
    assert(system2->getValue() == 10.0);

    cout << GREEN << "OK!" << RESET << endl;
}

// Function for System class' "+" operator unit test.
void unit_system_sumOperator(){
    SystemImpl* sys1 = new SystemImpl("Population 1", 100.0);
    SystemImpl* sys2 = new SystemImpl("Population 2", 10.0);

    cout << "TEST 10 - System class sum operator" << endl;
    assert(((*sys1) + (*sys2)) == 110);
    assert(((*sys1) + 20.0) == 120);

    cout << GREEN << "OK!" << RESET << endl;
}

// Function for System class' "-" operator unit test.
void unit_system_minusOperator(){
    SystemImpl* sys1 = new SystemImpl("Population 1", 100.0);
    SystemImpl* sys2 = new SystemImpl("Population 2", 10.0);

    cout << "TEST 11 - System class subtraction operator" << endl;
    assert(((*sys1) - (*sys2)) == 90);
    assert(((*sys1) - 20.0) == 80);

    cout << GREEN << "OK!" << RESET << endl;
}

// Function for System class' "*" operator unit test.
void unit_system_timesOperator(){
    SystemImpl* sys1 = new SystemImpl("Population 1", 100.0);
    SystemImpl* sys2 = new SystemImpl("Population 2", 10.0);

    cout << "TEST 12 - System class multiplication operator" << endl;
    assert(((*sys1) * (*sys2)) == 1000);
    assert(((*sys1) * 20.0) == 2000);

    cout << GREEN << "OK!" << RESET << endl;
}

// Function for System class' "/" operator unit test.
void unit_system_divisionOperator(){
    SystemImpl* sys1 = new SystemImpl("Population 1", 100.0);
    SystemImpl* sys2 = new SystemImpl("Population 2", 10.0);

    cout << "TEST 13 - System class division operator" << endl;
    assert(((*sys1) / (*sys2)) == 10);
    assert(((*sys1) / 20.0) == 5);

    cout << GREEN << "OK!" << RESET << endl;
}

// Function to run all the System class' unit tests.
void run_unit_tests_system(){

    UnitSystem* unit_sys = new UnitSystem();

    // Calling all the System class' unit test functions.
    unit_system_constructor();
    unit_sys->unit_system_copy_constructor();
    unit_system_destructor();
    unit_system_getName();
    unit_system_setName();
    unit_system_getValue();
    unit_system_setValue();
    unit_sys->unit_system_assingmentOperator();
    unit_system_sumOperator();
    unit_system_minusOperator();
    unit_system_timesOperator();
    unit_system_divisionOperator();

    delete(unit_sys);
}