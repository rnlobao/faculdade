#ifndef UNIT_SYSTEM
#define UNIT_SYSTEM

#include "../../src/SystemImpl.h"

/**
 * @brief class to unit system
 * 
 */
class UnitSystem{
    public:
        /**
         * @brief Construct a new Unit System object
         * 
         */
        UnitSystem(){}
        /**
         * @brief Destroy the Unit System object
         * 
         */
        ~UnitSystem(){}
};
/**
 * @brief unit test constructor
 * 
 */
void unit_system_constructor();
/**
 * @brief unit test get name
 * 
 */
void unit_system_getName();
/**
 * @brief unit test set name
 * 
 */
void unit_system_setName();
/**
 * @brief unit test get value
 * 
 */
void unit_system_getValue();
/**
 * @brief unit test set value
 * 
 */
void unit_system_setValue();
/**
 * @brief all unit tests
 * 
 */
void run_unit_tests_system();

#endif