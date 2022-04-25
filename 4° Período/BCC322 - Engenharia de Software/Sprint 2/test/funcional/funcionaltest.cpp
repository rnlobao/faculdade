#include <iostream>

#include "funcionaltest.h" 
#include "../../src/System.h"
#include "../../src/Flow.h"
#include "../../src/Model.h"

using namespace std;

//Nesse arquivo temos as implementações dos testes funcionais onde cada teste cria seu cenário e o executa
//De acordo com a implementação do execute extendido da classe flow no arquivo .h

void exponentialFuncionalTest(){
    cout << "Teste exponencial" << endl;
    System* pop1 = new System("valor 1", 100);
    System* pop2 = new System("valor 2", 0);
    flowParaTesteExponencial* flowExponencial = new flowParaTesteExponencial("cresce exponencialmente", pop1, pop2);
    Model* expModel = new Model("Modelo Exponencial", 0.0);
    expModel->add(pop1);
    expModel->add(pop2);
    expModel->add(flowExponencial);
    expModel->execute(0, 100, 1);
    delete (expModel);
    cout << "Done" << endl;
}

void logisticalFuncionalTest(){
    cout << "Teste equacao logistica" << endl;
    System* p1 = new System("valor 1", 100);
    System* p2 = new System("valor 2", 10);
    flowParaTesteLogistico* logFlow = new flowParaTesteLogistico("cresce limitado", p1, p2);
    Model* logModel = new Model("Modelo Logistico", 0.0);
    logModel->add(p1);
    logModel->add(p2);
    logModel->add(logFlow);
    logModel->execute(0, 100, 1);
    delete(logModel);
    cout << "Done" << endl;
}

void complexFuncionalTest(){
    cout << "Teste modelo complexo" << endl;
    System* Q1 = new System("Q1", 100);
    System* Q2 = new System("Q2", 0);
    System* Q3 = new System("Q3", 100);
    System* Q4 = new System("Q4", 0);
    System* Q5 = new System("Q5", 0);
    bigTheoryFlowF* comFlowF = new bigTheoryFlowF("Fluxo f", Q1, Q2);
    bigTheoryFlowT* comFlowT = new bigTheoryFlowT("Fluxo t", Q2, Q3);
    bigTheoryFlowU* comFlowU = new bigTheoryFlowU("Fluxo u", Q3, Q4);
    bigTheoryFlowV* comFlowV = new bigTheoryFlowV("Fluxo v", Q4, Q1);
    bigTheoryFlowG* comFlowG = new bigTheoryFlowG("Fluxo g", Q1, Q3);
    bigTheoryFlowR* comFlowR = new bigTheoryFlowR("Fluxo r", Q2, Q5);
    Model* comModel = new Model("Modelo Complexo", 0.0);
    comModel->add(Q1);
    comModel->add(Q2);
    comModel->add(Q3);
    comModel->add(Q4);
    comModel->add(Q5);
    comModel->add(comFlowF);
    comModel->add(comFlowT);
    comModel->add(comFlowU);
    comModel->add(comFlowV);
    comModel->add(comFlowG);
    comModel->add(comFlowR);
    comModel->execute(0, 100, 1);
    delete(comModel);
    cout << "Done" << endl;
}