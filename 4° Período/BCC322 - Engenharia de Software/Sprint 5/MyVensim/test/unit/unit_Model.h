#ifndef UNIT_MODEL
#define UNIT_MODEL

#include "../../src/ModelImpl.h"
#include "unit_Flow.h"

/**
 * @brief unit test constructor
 * 
 */
void unit_model_constructor();
/**
 * @brief unit test add system
 * 
 */
void unit_model_addSystem();
/**
 * @brief unit test remove system
 * 
 */
void unit_model_removeSystem();
/**
 * @brief unit test add flow
 * 
 */
void unit_model_addFlow();
/**
 * @brief unit test remove flow
 * 
 */
void unit_model_removeFlow();
/**
 * @brief unit test get name
 * 
 */
void unit_model_getName();
/**
 * @brief unit test set name
 * 
 */
void unit_model_setName();
/**
 * @brief unit test get time
 * 
 */
void unit_model_getTime();
/**
 * @brief unit test set time
 * 
 */
void unit_model_setTime();
/**
 * @brief unit test increment time
 * 
 */
void unit_model_incrementTime();
/**
 * @brief all unit tests
 * 
 */
void run_unit_tests_model();

#endif