#ifndef UNIT_FLOW
#define UNIT_FLOW

#include "../../src/SystemImpl.h"
#include "../../src/FlowImpl.h"

using namespace std;

/**
 * @brief Unittest class
 * 
 */
class UnitFlow{

    public:
        /**
         * @brief Construct a new Unit Flow object
         * 
         */
        UnitFlow(){}
        /**
         * @brief Destroy the Unit Flow object
         * 
         */
        ~UnitFlow(){}
};

/**
 * @brief Exponencial Model test
 * 
 */
class ExponencialFlow : public FlowImpl{
    public:
      
        /**
         * @brief Construct a new Exponencial Flow object
         * 
         * @param name name in flow
         * @param source source in flow
         * @param target target in flow
         */
        ExponencialFlow(string name = "", System* source = NULL, System* target = NULL): FlowImpl(name, source, target){}
        /**
         * @brief execute to test
         * 
         * @return double 
         */
        double execute(){
            if (getSource() != NULL){
                return (0.01 * getSource()->getValue());
            }
            else{
                return 0;
            }
        }
};

/**
 * @brief unit test contructor
 * 
 */
void unit_flow_constructor();
/**
 * @brief unit test get name
 * 
 */
void unit_flow_getName();
/**
 * @brief unit test set name
 * 
 */
void unit_flow_setName();
/**
 * @brief unit test get source
 * 
 */
void unit_flow_getSource();
/**
 * @brief unit test set source
 * 
 */
void unit_flow_setSource();
/**
 * @brief unit test clear
 * 
 */
void unit_flow_clearSource();
/**
 * @brief unit test get target
 * 
 */
void unit_flow_getTarget();
/**
 * @brief unit test set target
 * 
 */
void unit_flow_setTarget();
/**
 * @brief unit test clear target
 * 
 */
void unit_flow_clearTarget();
/**
 * @brief unit test execute
 * 
 */
void unit_flow_execute();
/**
 * @brief all unit tests
 * 
 */
void run_unit_tests_flow();

#endif