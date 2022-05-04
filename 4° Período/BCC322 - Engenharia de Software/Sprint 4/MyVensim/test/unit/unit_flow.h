#ifndef UNIT_FLOW
#define UNIT_FLOW

#include "../../src/systemImpl.h"
#include "../../src/flowImpl.h"

#define RESET "\033[0m"  /* Escape sequence to reset color output to default. */
#define GREEN "\033[32m" /* Escape sequence to a green color output. */
using namespace std;

//! Unit tests 
/**
* Creation of the unit tests for the Flow class.
*/

class UnitFlow{

    public:
        UnitFlow(){}
        ~UnitFlow(){}
        
        /*!
          Function prototype for the Flow class' copy constructor unit test.
        */
        void unit_flow_copy_constructor();
        /*!
          Function prototype for the Flow class' assingment operator unit test.
        */
        void unit_flow_assingmentOperator();

};

//! Class ExponencialFlow
/**
* This Class represents a flow with limitless growth, and is used in the Exponencial Model test.
*/
class ExponencialFlow : public FlowImpl{
    public:
        /*!
            This is a more elaborated constructor for the ExponencialFlow Class.
            \param name the name of the ExponencialFlow Class.
            \param source a pointer to the source system of the ExponencialFlow Class.
            \param target a pointer to the target system of the ExponencialFlow Class.
        */
        ExponencialFlow(string name = "", System* source = NULL, System* target = NULL): FlowImpl(name, source, target){}
        
        /*!
            A method created by the user, that contains an equation that will be executed by the exponencial model.                        
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

/*!
  Function prototype for the Flow class' constructor unit test.
*/
void unit_flow_constructor();

/*!
  Function prototype for the Flow class' destructor unit test.
*/
void unit_flow_destructor();

/*!
  Function prototype for the Flow class' method getName() unit test.
*/
void unit_flow_getName();

/*!
  Function prototype for the Flow class' method setName() unit test.
*/
void unit_flow_setName();

/*!
  Function prototype for the Flow class' method getSource() unit test.
*/
void unit_flow_getSource();

/*!
  Function prototype for the Flow class' method setSource() unit test.
*/
void unit_flow_setSource();

/*!
  Function prototype for the Flow class' method clearSource() unit test.
*/
void unit_flow_clearSource();

/*!
  Function prototype for the Flow class' method getTarget() unit test.
*/
void unit_flow_getTarget();

/*!
  Function prototype for the Flow class' method setTarget() unit test.
*/
void unit_flow_setTarget();

/*!
  Function prototype for the Flow class' method clearTarget() unit test.
*/
void unit_flow_clearTarget();

/*!
  Function prototype for the Flow class' method execute() unit test.
*/
void unit_flow_execute();

/*!
  Function prototype for the function that runs all the unit tests of the Flow class.
*/
void run_unit_tests_flow();

#endif