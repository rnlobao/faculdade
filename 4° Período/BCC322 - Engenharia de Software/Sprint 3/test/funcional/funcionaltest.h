#ifndef FUNCTIONAL_TEST
#define FUNCTIONAL_TEST

#include "../../src/System.h"
#include "../../src/Flow.h"


/**
 * @brief Flow for exponencial test
 * 
 */
class flowParaTesteExponencial : public Flow{
    public:
        flowParaTesteExponencial(string name, System* source, System* target): Flow(name, source, target){}
        double execute(){
            return 0.01 * getSource()->getValue();
        }
};

/**
 * @brief Flow for logistical test
 * 
 */
class flowParaTesteLogistico : public Flow{
    public:
        flowParaTesteLogistico(string name, System* source, System* target): Flow(name, source, target){}
        double execute(){
            return 0.01 * getTarget()->getValue() * (1 - getTarget()->getValue() / 70);
        }
};

/**
 * @brief Flow for complex F
 * 
 */
class bigTheoryFlowF : public Flow{
    public:
        bigTheoryFlowF(string name, System* source, System* target): Flow(name, source, target){}
        double execute(){
            return 0.01 * getSource()->getValue();
        }
};

/**
 * @brief Flow for complex T
 * 
 */
class bigTheoryFlowT : public Flow{
    public:
        bigTheoryFlowT(string name, System* source, System* target): Flow(name, source, target){}
        double execute(){
            return 0.01 * getSource()->getValue();
        }
};

/**
 * @brief Flow for complex U
 * 
 */
class bigTheoryFlowU : public Flow{
    public:
        bigTheoryFlowU(string name, System* source, System* target): Flow(name, source, target){}
        double execute(){
            return 0.01 * getSource()->getValue();
        }
};

/**
 * @brief Flow for complex V
 * 
 */
class bigTheoryFlowV : public Flow{
    public:
        bigTheoryFlowV(string name, System* source, System* target): Flow(name, source, target){}
        double execute(){
            return 0.01 * getSource()->getValue();
        }
};

/**
 * @brief Flow for complex G
 * 
 */
class bigTheoryFlowG : public Flow{
    public:
        bigTheoryFlowG(string name, System* source, System* target): Flow(name, source, target){}
        double execute(){
            return 0.01 * getSource()->getValue();
        }
};

/**
 * @brief Flow for complex R
 * 
 */
class bigTheoryFlowR: public Flow{
    public:
        bigTheoryFlowR(string name, System* source, System* target): Flow(name, source, target){}
        double execute(){
            return 0.01 * getSource()->getValue();
        }
};

/**
 * @brief Exponential test
 * 
 */
void exponentialFuncionalTest();
/**
 * @brief Logistical test
 * 
 */
void logisticalFuncionalTest();
/**
 * @brief Complex test
 * 
 */
void complexFuncionalTest();

#endif