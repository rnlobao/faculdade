#include "unit_Model.h"
#include <assert.h>

using namespace std;

void unit_model_constructor(){
    cout << "Model constructor" << endl;
    Model* model1 =  new ModelImpl();
    assert(model1->getName() == "");
    assert(model1->getTime() == 0.0);
    cout << "Done" << endl;
    delete(model1);

    cout << "Model constructor with parameters" << endl;
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
    assert(model2->getName() == "Test Model");
    assert(model2->getTime() == 1.0);
    assert((*(model2->beginFlows()))->getName() == "Flow 1");    
    int counter = 0;    
    for (auto sys = model2->beginSystems(); sys != model2->endSystems(); ++sys){
        assert((*sys)->getName() == systems[counter]->getName());
        counter++;
    }
    cout << "Done" << endl;
    delete(system1);
    delete(system2);
    delete(flow1);
    model2->remove(system1);
    model2->remove(system2);
    model2->remove(flow1); 
    delete(model2);
}

void unit_model_getName(){
    cout << "Model getName()" << endl;
    Model* model = new ModelImpl("Test Model", 0.0);
    assert(model->getName() == "Test Model");
    cout << "Done" << endl;
    delete(model);
}

void unit_model_setName(){
    cout << "Model setName()" << endl;
    Model* model = new ModelImpl();
    model->setName("Test Model");
    assert(model->getName() == "Test Model");
    cout << "Done" << endl;
    delete(model);
}

void unit_model_getTime(){
    cout << "Model getTime()" << endl;
    Model* model = new ModelImpl("Test Model", 0.0);
    assert(model->getTime() == 0.0);
    cout << "Done" << endl;
    delete(model);
}

void unit_model_setTime(){
    cout << "Model setTime()" << endl;
    Model* model = new ModelImpl("Test Model", 0.0);
    model->setTime(1.0);
    assert(model->getTime() == 1.0);
    cout << "Done" << endl;
    delete(model);
}

void unit_model_incrementTime(){
    cout << "Model incrementTime()" << endl;
    Model* model = new ModelImpl("Test Model", 1.0);
    model->incrementTime(1.0);
    assert(model->getTime() == 2.0);
    cout << "Done" << endl;
    delete(model);
}

void unit_model_addSystem(){
    cout << "Model addSystem()" << endl;
    System* system = new SystemImpl("System 1");
    Model* model = new ModelImpl("Test Model", 1.0);
    model->add(system);
    assert((*(model->beginSystems()))->getName() == system->getName());
    cout << "Done" << endl;
    model->remove(system);
    delete(model);
    delete(system);
}

void unit_model_removeSystem(){
    cout << "Model removeSystem()" << endl;
    System* system = new SystemImpl("System 1");
    Model* model = new ModelImpl("Test Model", 1.0);
    model->add(system);
    model->remove(system);
    assert(model->beginSystems() == model->endSystems());
    cout << "Done" << endl;
    delete(model);
    delete(system);
}

void unit_model_addFlow(){
    cout << "Model addFlow()" << endl;
    ExponencialFlow* flow = new ExponencialFlow("Flow 1");
    Model* model = new ModelImpl("Test Model", 1.0);
    model->add(flow);
    assert((*(model->beginFlows()))->getName() == flow->getName());
    cout << "Done" << endl;
    model->remove(flow);
    delete(model);
    delete(flow);
}

void unit_model_removeFlow(){
    cout << "Model removeFlow()" << endl;
    ExponencialFlow* flow = new ExponencialFlow("Flow 1");
    Model* model = new ModelImpl("Test Model", 1.0);
    model->add(flow);
    model->remove(flow);
    assert(model->beginFlows() == model->endFlows());
    cout << "Done" << endl;
    delete(model);
    delete(flow);
}

void unit_model_execute(){
    cout << "Model execute()" << endl;
    System* pop1 = new SystemImpl("Population 1", 100.0);
    System* pop2 = new SystemImpl("Population 2", 0.0);
    ExponencialFlow* expFlow = new ExponencialFlow("Unlimited Growth", pop1, pop2);
    Model* expModel = new ModelImpl("Exponential Model", 0.0);
    expModel->add(pop1);
    expModel->add(pop2);
    expModel->add(expFlow);
    assert(pop1->getName() == "Population 1");
    assert(pop2->getName() == "Population 2");
    assert(expFlow->getName() == "Unlimited Growth");
    assert(expModel->getName() == "Exponential Model");
    assert(abs(pop1->getValue() - 100.0) < 0.0001);
    assert(abs(pop2->getValue() - 0.0) < 0.0001);
    assert(abs(expModel->getTime() - 0.0) < 0.0001);
    expModel->execute(0, 100, 1);
    assert(abs(pop1->getValue() - 36.6032) < 0.0001);
    assert(abs(pop2->getValue() - 63.3968) < 0.0001);
    assert(abs(expModel->getTime() - 100.0) < 0.0001);
    cout << "Done" << endl;
    delete(pop1);
    delete(pop2);
    delete(expFlow);
    expModel->remove(pop1);
    expModel->remove(pop2);
    expModel->remove(expFlow);
    delete(expModel);
}

void run_unit_tests_model(){
    unit_model_constructor();
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