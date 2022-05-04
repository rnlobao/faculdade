#ifndef FUNCTIONAL_TEST
#define FUNCTIONAL_TEST

#include "../../src/System.h"
#include "../../src/Flow.h"

//Nesse arquivos temos as função de teste do Vensim apresentado que extendem de flow e implementam seu execute

class flowParaTesteExponencial : public Flow{
    public:
        flowParaTesteExponencial(string name, System* source, System* target): Flow(name, source, target){}
        double execute(){
            return 0.01 * getSource()->getValue();
        }
};

class flowParaTesteLogistico : public Flow{
    public:
        flowParaTesteLogistico(string name, System* source, System* target): Flow(name, source, target){}
        double execute(){
            return 0.01 * getTarget()->getValue() * (1 - getTarget()->getValue() / 70);
        }
};

class bigTheoryFlowF : public Flow{
    public:
        bigTheoryFlowF(string name, System* source, System* target): Flow(name, source, target){}
        double execute(){
            return 0.01 * getSource()->getValue();
        }
};

class bigTheoryFlowT : public Flow{
    public:
        bigTheoryFlowT(string name, System* source, System* target): Flow(name, source, target){}
        double execute(){
            return 0.01 * getSource()->getValue();
        }
};

class bigTheoryFlowU : public Flow{
    public:
        bigTheoryFlowU(string name, System* source, System* target): Flow(name, source, target){}
        double execute(){
            return 0.01 * getSource()->getValue();
        }
};

class bigTheoryFlowV : public Flow{
    public:
        bigTheoryFlowV(string name, System* source, System* target): Flow(name, source, target){}
        double execute(){
            return 0.01 * getSource()->getValue();
        }
};

class bigTheoryFlowG : public Flow{
    public:
        bigTheoryFlowG(string name, System* source, System* target): Flow(name, source, target){}
        double execute(){
            return 0.01 * getSource()->getValue();
        }
};
   
class bigTheoryFlowR: public Flow{
    public:
        bigTheoryFlowR(string name, System* source, System* target): Flow(name, source, target){}
        double execute(){
            return 0.01 * getSource()->getValue();
        }
};

void exponentialFuncionalTest();
void logisticalFuncionalTest();
void complexFuncionalTest();

#endif