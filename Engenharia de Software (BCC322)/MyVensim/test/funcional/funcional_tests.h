#ifndef FUNCTIONAL_TEST
#define FUNCTIONAL_TEST

#include "../../src/SystemImpl.h"
#include "../../src/FlowImpl.h"
#include "../../src/ModelImpl.h"

/**
 * @brief Flow to exponencial
 * 
 */
class ExponencialFlow : public FlowImpl {
    public:
        /**
         * @brief Construct a new Exponencial Flow object
         * 
         * @param name name in exponencial flow
         * @param source source in exponencial flow
         * @param target target in exponencial flow
         */
        ExponencialFlow(string name, System* source, System* target): FlowImpl(name, source, target){}
        /**
         * @brief execute exponencial
         * 
         * @return double 
         */
        double execute(){
            return 0.01 * getSource()->getValue();
        }
};

/**
 * @brief Flow to logistic
 * 
 */
class LogisticFlow : public FlowImpl{
    public:
        /**
         * @brief Construct a new Logistic Flow object
         * 
         * @param name name in logistic flow
         * @param source source in logistic flow
         * @param target target in logistic flow
         */
        LogisticFlow(string name, System* source, System* target): FlowImpl(name, source, target){}
        /**
         * @brief execute logistic
         * 
         * @return double 
         */
        double execute(){
            return 0.01 * getTarget()->getValue() * (1 - getTarget()->getValue() / 70);
        }
};

/**
 * @brief Flow in complexF
 * 
 */
class ComplexFlowF : public FlowImpl{
    public:
        /**
         * @brief Construct a new Complex Flow F object
         * 
         * @param name name in ComplexF flow
         * @param source source in ComplexF flow
         * @param target target in ComplexF flow
         */
        ComplexFlowF(string name, System* source, System* target): FlowImpl(name, source, target){}
        /**
         * @brief execute complexF
         * 
         * @return double 
         */
        double execute(){
            return 0.01 * getSource()->getValue();
        }
};

/**
 * @brief Flow in complexT
 * 
 */
class ComplexFlowT : public FlowImpl{
    public:
        /**
         * @brief Construct a new Complex Flow T object
         * 
         * @param name name in ComplexT flow
         * @param source source in ComplexT flow
         * @param target target in ComplexT flow
         */
        ComplexFlowT(string name, System* source, System* target): FlowImpl(name, source, target){}
        /**
         * @brief execute complexT
         * 
         * @return double 
         */
        double execute(){
            return 0.01 * getSource()->getValue();
        }
};

/**
 * @brief Flow in complexU
 * 
 */
class ComplexFlowU : public FlowImpl{
    public:
        /**
         * @brief Construct a new Complex Flow U object
         * 
         * @param name name in complexU
         * @param source source in complexU
         * @param target target in complexU
         */
        ComplexFlowU(string name, System* source, System* target): FlowImpl(name, source, target){}
        /**
         * @brief execute in complexU
         * 
         * @return double 
         */
        double execute(){
            return 0.01 * getSource()->getValue();
        }
};

/**
 * @brief Flow in complexV
 * 
 */
class ComplexFlowV : public FlowImpl{
    public:
        /**
         * @brief Construct a new Complex Flow V object
         * 
         * @param name name in complexV
         * @param source source in complexV
         * @param target target in complexV
         */
        ComplexFlowV(string name, System* source, System* target): FlowImpl(name, source, target){}
        /**
         * @brief execute in complexV
         * 
         * @return double 
         */
        double execute(){
            return 0.01 * getSource()->getValue();
        }
};

/**
 * @brief Flow in complexG
 * 
 */
class ComplexFlowG : public FlowImpl{
    public:
        /**
         * @brief Construct a new Complex Flow G object
         * 
         * @param name name in complexG
         * @param source souce in complexG
         * @param target target in complexG
         */
        ComplexFlowG(string name, System* source, System* target): FlowImpl(name, source, target){}
        /**
         * @brief execute in complexG
         * 
         * @return double 
         */
        double execute(){
            return 0.01 * getSource()->getValue();
        }
};

/**
 * @brief Flow in ComplexR
 * 
 */
class ComplexFlowR: public FlowImpl{
    public:
        /**
         * @brief Construct a new Complex Flow R object
         * 
         * @param name name in ComplexR
         * @param source source in ComplexR
         * @param target target in ComplexR
         */
        ComplexFlowR(string name, System* source, System* target): FlowImpl(name, source, target){}
        /**
         * @brief execute in ComplexR
         * 
         * @return double 
         */
        double execute(){
            return 0.01 * getSource()->getValue();
        }
};
/**
 * @brief exponencial Funcional Test
 * 
 */
void exponentialFuncionalTest();
/**
 * @brief logistical funcional test
 * 
 */
void logisticalFuncionalTest();
/**
 * @brief complex funcional test
 * 
 */
void complexFuncionalTest();

#endif