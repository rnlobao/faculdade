#ifndef FUNCTIONAL_TEST
#define FUNCTIONAL_TEST

#include "../../src/SystemImpl.h"
#include "../../src/FlowImpl.h"
#include "../../src/ModelImpl.h"

class flowParaTesteExponencial : public FlowImpl {
    public:
        flowParaTesteExponencial(string name, System* source, System* target): FlowImpl(name, source, target){}
        double execute(){
            return 0.01 * getSource()->getValue();
        }
};

class flowParaTesteLogistico : public FlowImpl{
    public:
        flowParaTesteLogistico(string name, System* source, System* target): FlowImpl(name, source, target){}
        double execute(){
            return 0.01 * getTarget()->getValue() * (1 - getTarget()->getValue() / 70);
        }
};

class bigTheoryFlowF : public FlowImpl{
    public:
        bigTheoryFlowF(string name, System* source, System* target): FlowImpl(name, source, target){}
        double execute(){
            return 0.01 * getSource()->getValue();
        }
};

class bigTheoryFlowT : public FlowImpl{
    public:
        bigTheoryFlowT(string name, System* source, System* target): FlowImpl(name, source, target){}
        double execute(){
            return 0.01 * getSource()->getValue();
        }
};

class bigTheoryFlowU : public FlowImpl{
    public:
        bigTheoryFlowU(string name, System* source, System* target): FlowImpl(name, source, target){}
        double execute(){
            return 0.01 * getSource()->getValue();
        }
};

class bigTheoryFlowV : public FlowImpl{
    public:
        bigTheoryFlowV(string name, System* source, System* target): FlowImpl(name, source, target){}
        double execute(){
            return 0.01 * getSource()->getValue();
        }
};

class bigTheoryFlowG : public FlowImpl{
    public:
        bigTheoryFlowG(string name, System* source, System* target): FlowImpl(name, source, target){}
        double execute(){
            return 0.01 * getSource()->getValue();
        }
};
   
class bigTheoryFlowR: public FlowImpl{
    public:
        bigTheoryFlowR(string name, System* source, System* target): FlowImpl(name, source, target){}
        double execute(){
            return 0.01 * getSource()->getValue();
        }
};

void exponentialFuncionalTest();
void logisticalFuncionalTest();
void complexFuncionalTest();

#endif