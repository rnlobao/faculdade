#include "funcional_tests.h" 
#include <iostream>
#include <assert.h>
#include <cmath>

using namespace std;

void exponentialFuncionalTest(){
    cout << "Teste equacao exponencial" << endl;
    System* pop1 = new SystemImpl("Population 1", 100);
    System* pop2 = new SystemImpl("Population 2", 0);
    ExponencialFlow* expFlow = new ExponencialFlow("Unlimited Growth", pop1, pop2);
    Model* expModel = new ModelImpl("Exponential Model", 0.0);

    expModel->add(pop1);
    expModel->add(pop2);
    expModel->add(expFlow);
    expModel->execute(0,100,1);

    assert(fabs(pop1->getValue() - 36.6032) < 0.0001);
    assert(fabs(pop2->getValue() - 63.3968) < 0.0001);
    cout << "Passou" << endl;
    delete(pop1);
    delete(pop2);
    delete(expFlow);
    expModel->remove(pop1);
    expModel->remove(pop2);
    expModel->remove(expFlow);
    delete(expModel);    
}

void logisticalFuncionalTest(){
    cout << "Teste equacao logistica" << endl;
    System* p1 = new SystemImpl("Population 1", 100);
    System* p2 = new SystemImpl("Population 2", 10);
    LogisticFlow* logFlow = new LogisticFlow("Limited Growth", p1, p2);
    Model* logModel = new ModelImpl("Logistic Model", 0.0);;

    logModel->add(p1);
    logModel->add(p2);
    logModel->add(logFlow);
    logModel->execute(0, 100, 1);

    assert(fabs(p1->getValue() - 88.2167) < 0.0001);
    assert(fabs(p2->getValue() - 21.7833) < 0.0001);
    cout << "Passou" << endl;

    delete(p1);
    delete(p2);
    delete(logFlow);
    logModel->remove(p1);
    logModel->remove(p2);
    logModel->remove(logFlow);
    delete(logModel);
}

void complexFuncionalTest(){
    cout << "Teste modelo complexo" << endl;
    System* q1 = new SystemImpl("Q1", 100);
    System* q2 = new SystemImpl("Q2", 0);
    System* q3 = new SystemImpl("Q3", 100);
    System* q4 = new SystemImpl("Q4", 0);
    System* q5 = new SystemImpl("Q5", 0);
    ComplexFlowF* comFlowF = new ComplexFlowF("Flow f", q1, q2);
    ComplexFlowT* comFlowT = new ComplexFlowT("Flow t", q2, q3);
    ComplexFlowU* comFlowU = new ComplexFlowU("Flow u", q3, q4);
    ComplexFlowV* comFlowV = new ComplexFlowV("Flow v", q4, q1);
    ComplexFlowG* comFlowG = new ComplexFlowG("Flow g", q1, q3);
    ComplexFlowR* comFlowR = new ComplexFlowR("Flow r", q2, q5);
    Model* comModel = new ModelImpl("Complex Model", 0.0);

    comModel->add(q1);
    comModel->add(q2);
    comModel->add(q3);
    comModel->add(q4);
    comModel->add(q5);
    comModel->add(comFlowF);
    comModel->add(comFlowT);
    comModel->add(comFlowU);
    comModel->add(comFlowV);
    comModel->add(comFlowG);
    comModel->add(comFlowR);
    comModel->execute(0, 100, 1);

    assert(fabs(q1->getValue() - 31.8513) < 0.0001);
    assert(fabs(q2->getValue() - 18.4003) < 0.0001);
    assert(fabs(q3->getValue() - 77.1143) < 0.0001);
    assert(fabs(q4->getValue() - 56.1728) < 0.0001);
    assert(fabs(q5->getValue() - 16.4612) < 0.0001);
    cout << "Passou" << endl;

    delete(q1);
    delete(q2);
    delete(q3);
    delete(q4);
    delete(q5);
    delete(comFlowF);
    delete(comFlowT);
    delete(comFlowU);
    delete(comFlowV);
    delete(comFlowG);
    delete(comFlowR);
    comModel->remove(q1);
    comModel->remove(q2);
    comModel->remove(q3);
    comModel->remove(q4);
    comModel->remove(q5);
    comModel->remove(comFlowF);
    comModel->remove(comFlowT);
    comModel->remove(comFlowU);
    comModel->remove(comFlowV);
    comModel->remove(comFlowG);
    comModel->remove(comFlowR);
    delete(comModel);
}