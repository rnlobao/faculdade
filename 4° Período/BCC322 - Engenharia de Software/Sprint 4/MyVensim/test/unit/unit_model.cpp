#include "unit_model.h"
#include <assert.h>

using namespace std;

// Function for Model class's constructor unit test.
void unit_model_constructor(){
    cout << "TEST 1 - Default constructor of the Model class without passing parameters" << endl;

    Model* model1 =  new ModelImpl();

    // Making assertion to verify if the name property was initialized with the default data.
    assert(model1->getName() == "");
    // Making assertion to verify if the time property was initialized with the default data.
    assert(model1->getTime() == 0.0);

    cout << GREEN << "OK!" << RESET << endl;
    cout << "TEST 2 - Default constructor of the Model class with passing parameters" << endl;

    System* system1 = new SystemImpl("System 1");
    System* system2 = new SystemImpl("System 2");

    vector<System*> systems;
    
    systems.push_back(system1);
    systems.push_back(system2);
    
    ExponencialFlow* flow1 = new ExponencialFlow("Flow 1");
    Model* model2 = new ModelImpl("Test Model", 1.0);

    model2->add(system1);
    model2->add(system2);
    model2->add(flow1);    
    
    // Making assertion to verify if the name property was initialized with the parameter specified.
    assert(model2->getName() == "Test Model");
    // Making assertion to verify if the time property was initialized with the parameter specified.
    assert(model2->getTime() == 1.0);
    // Making assertion to verify if the Flow object was added to the Model's flows parameter.
    assert((*(model2->beginFlows()))->getName() == "Flow 1");    
   
    int counter = 0;    
    for (auto sys = model2->beginSystems(); sys != model2->endSystems(); ++sys){
        // Making assertion to verify if the systems were added to the systems property.
        assert((*sys)->getName() == systems[counter]->getName());
        counter++;
    }

    cout << GREEN << "OK!" << RESET << endl;
}

// Function for the Model class' destructor unit test.
void unit_model_destructor(){
    cout << "TEST 3 - Default destructor of the Model class" << endl;
    
    double vmBefore, vmAfter, rss;

    // Getting the memory usage previous to the creation of a model.
    memory_usage(vmBefore, rss);
    
    System* system1 = new SystemImpl("System 1");
    System* system2 = new SystemImpl("System 2");
    ExponencialFlow* flow1 = new ExponencialFlow("Flow 1");
    Model* model = new ModelImpl("Test Model", 1.0);

    model->add(system1);
    model->add(system2);
    model->add(flow1);

    delete model;

    // Getting the memory usage after the creation and destruction of a Flow object.
    memory_usage(vmAfter, rss);

    // Making assertion to verify if the memory usage after the creation and deletion
    // is the same as before the creation of Model object.
    assert(vmBefore == vmAfter);

    cout << GREEN << "OK!" << RESET << endl;
}

// Function for the Model class' getName() method unit test.
void unit_model_getName(){
    cout << "TEST 4 - Model class's getName() method" << endl;
    
    Model* model = new ModelImpl("Test Model", 0.0);
    
    // Making assertion to verify if the method returns the Model class name and if it's
    // equal to the parameter previously passed.
    assert(model->getName() == "Test Model");

    cout << GREEN << "OK!" << RESET << endl;
}

// Function for the Model class' setName() method unit test.
void unit_model_setName(){
    cout << "TEST 5 - Model class's setName() method" << endl;

    Model* model = new ModelImpl();
    model->setName("Test Model");
    
    // Making assertion to verify if the data of the name property has been altered.
    assert(model->getName() == "Test Model");

    cout << GREEN << "OK!" << RESET << endl;
}

// Function for the Model class' getTime() method unit test.
void unit_model_getTime(){
    cout << "TEST 6 - Model class's getTime() method" << endl;

    Model* model = new ModelImpl("Test Model", 0.0);

    // Making assertion to verify if the method returns the Model class time and if it's
    // equal to the parameter previously passed.
    assert(model->getTime() == 0.0);

    cout << GREEN << "OK!" << RESET << endl;
}

// Function for the Model class' setTime() method unit test.
void unit_model_setTime(){
    cout << "TEST 7 - Model class's setTime() method" << endl;

    Model* model = new ModelImpl("Test Model", 0.0);
    model->setTime(1.0);

    // Making assertion to verify if the data of the time property has been altered.
    assert(model->getTime() == 1.0);

    cout << GREEN << "OK!" << RESET << endl;
}

// Function for the Model class' incrementTime() method unit test.
void unit_model_incrementTime(){
    cout << "TEST 8 - Model class's incrementTime() method" << endl;

    Model* model = new ModelImpl("Test Model", 1.0);
    model->incrementTime(1.0);
    
    // Making assertion to verify if the data of the time property has been incremented.
    assert(model->getTime() == 2.0);

    cout << GREEN << "OK!" << RESET << endl;
}

// Function for the Model class' addSystem() method unit test.
void unit_model_addSystem(){
    cout << "TEST 9 - Model class's addSystem() method" << endl;
    
    System* system = new SystemImpl("System 1");

    Model* model = new ModelImpl("Test Model", 1.0);
    model->add(system);

    // Making assertion to verify if the system has been added to the systems property.
    assert((*(model->beginSystems()))->getName() == system->getName());

    cout << GREEN << "OK!" << RESET << endl;
}

// Function for the Model class' removeSystem() method unit test.
void unit_model_removeSystem(){
    cout << "TEST 10 - Model class's removeSystem() method" << endl;

    System* system = new SystemImpl("System 1");

    Model* model = new ModelImpl("Test Model", 1.0);
    model->add(system);
    model->remove(system);
    
    // Making assertion to verify if the system has been removed from the systems property.
    assert(model->beginSystems() == model->endSystems());

    cout << GREEN << "OK!" << RESET << endl;
}

// Function for the Model class' addFlow() method unit test.
void unit_model_addFlow(){
    cout << "TEST 11 - Model class's addFlow() method" << endl;

    ExponencialFlow* flow = new ExponencialFlow("Flow 1");
    Model* model = new ModelImpl("Test Model", 1.0);
    model->add(flow);
    
    // Making assertion to verify if the flow has been added to the flows property.
    assert((*(model->beginFlows()))->getName() == flow->getName());

    cout << GREEN << "OK!" << RESET << endl;
}

// Function for the Model class' removeFlow() method unit test.
void unit_model_removeFlow(){
    cout << "TEST 12 - Model class's removeFlow() method" << endl;

    ExponencialFlow* flow = new ExponencialFlow("Flow 1");
    Model* model = new ModelImpl("Test Model", 1.0);
    model->add(flow);
    model->remove(flow);

    // Making assertion to verify if the system has been removed from the systems property.
    assert(model->beginFlows() == model->endFlows());

    cout << GREEN << "OK!" << RESET << endl;
}

// Function for the Model class' execute() method unit test.
void unit_model_execute(){
    cout << "TEST 13 - Model class's execute() method" << endl;
    
    System* pop1 = new SystemImpl("Population 1", 100.0);
    System* pop2 = new SystemImpl("Population 2", 0.0);
    ExponencialFlow* expFlow = new ExponencialFlow("Unlimited Growth", pop1, pop2);
    Model* expModel = new ModelImpl("Exponential Model", 0.0);
    
    expModel->add(pop1);
    expModel->add(pop2);
    expModel->add(expFlow);

    // Making assertions for the unit test before execution
    assert(pop1->getName() == "Population 1");
    assert(pop2->getName() == "Population 2");
    assert(expFlow->getName() == "Unlimited Growth");
    assert(expModel->getName() == "Exponential Model");

    assert(abs(pop1->getValue() - 100.0) < 0.0001);
    assert(abs(pop2->getValue() - 0.0) < 0.0001);
    assert(abs(expModel->getTime() - 0.0) < 0.0001);

    expModel->execute(0, 100, 1);

    // Making assertions for the unit test after execution
    assert(abs(pop1->getValue() - 36.6032) < 0.0001);
    assert(abs(pop2->getValue() - 63.3968) < 0.0001);
    assert(abs(expModel->getTime() - 100.0) < 0.0001);

    cout << GREEN << "OK!" << RESET << endl;
}

// Function to run all the Model class' unit tests.
void run_unit_tests_model(){
    
    // Calling all the Model class' unit test functions.
    unit_model_constructor();
    unit_model_destructor();
    unit_model_getName();
    unit_model_setName();
    unit_model_getTime();
    unit_model_setTime();
    unit_model_incrementTime();
    unit_model_addSystem();
    unit_model_removeSystem();
    unit_model_addFlow();
    unit_model_removeFlow();
    unit_model_execute();

}