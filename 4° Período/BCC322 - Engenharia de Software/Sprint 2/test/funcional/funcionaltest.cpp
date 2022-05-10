#include <iostream>

#include "funcionaltest.h" 
#include "../../src/System.h"
#include "../../src/Flow.h"
#include "../../src/Model.h"
#include <assert.h>
#include <cmath>

using namespace std;

void exponentialFuncionalTest(){
    cout << "Teste equacao exponencial" << endl;
    System pop1("valor 1", 100);
    System pop2("valor 2", 0);
    flowParaTesteExponencial myFlow("cresce exponencialmente", &pop1, &pop2);
    Model myModel("Modelo Exponencial", 0.0);
    myModel.add(&myFlow);
    myModel.add(&pop1);
    myModel.add(&pop2);
    myModel.execute(0, 100, 1);

    assert(fabs(pop1.getValue() - 36.6032) < 0.0001);
    assert(fabs(pop2.getValue() - 63.3968) < 0.0001);
    cout << "Passou" << endl;
}

void logisticalFuncionalTest(){
    cout << "Teste equacao logistica" << endl;
    System p1("valor 1", 100);
    System p2("valor 2", 10);
    flowParaTesteLogistico myFlow("cresce limitado", &p1, &p2);
    Model myModel("Modelo Logistico", 0.0);
    myModel.add(&p1);
    myModel.add(&p2);
    myModel.add(&myFlow);
    myModel.execute(0, 100, 1);

    assert(fabs(p1.getValue() - 88.2167) < 0.0001);
    assert(fabs(p2.getValue() - 21.7833) < 0.0001);
    cout << "Passou" << endl;
}

void complexFuncionalTest(){
    cout << "Teste modelo complexo" << endl;
    System Q1("Q1", 100);
    System Q2("Q2", 0);
    System Q3("Q3", 100);
    System Q4("Q4", 0);
    System Q5("Q5", 0);
    bigTheoryFlowF comFlowF("Fluxo f", &Q1, &Q2);
    bigTheoryFlowT comFlowT("Fluxo t", &Q2, &Q3);
    bigTheoryFlowU comFlowU("Fluxo u", &Q3, &Q4);
    bigTheoryFlowV comFlowV("Fluxo v", &Q4, &Q1);
    bigTheoryFlowG comFlowG("Fluxo g", &Q1, &Q3);
    bigTheoryFlowR comFlowR("Fluxo r", &Q2, &Q5);
    Model comModel("Modelo Complexo", 0.0);
    comModel.add(&Q1);
    comModel.add(&Q2);
    comModel.add(&Q3);
    comModel.add(&Q4);
    comModel.add(&Q5);
    comModel.add(&comFlowF);
    comModel.add(&comFlowT);
    comModel.add(&comFlowU);
    comModel.add(&comFlowV);
    comModel.add(&comFlowG);
    comModel.add(&comFlowR);
    comModel.execute(0, 100, 1);

    assert(fabs(Q1.getValue() - 31.8513) < 0.0001);
    assert(fabs(Q2.getValue() - 18.4003) < 0.0001);
    assert(fabs(Q3.getValue() - 77.1143) < 0.0001);
    assert(fabs(Q4.getValue() - 56.1728) < 0.0001);
    assert(fabs(Q5.getValue() - 16.4612) < 0.0001);
    cout << "Passou" << endl;
}