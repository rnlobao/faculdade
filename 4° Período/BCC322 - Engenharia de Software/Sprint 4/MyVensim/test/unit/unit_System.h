#ifndef UNIT_SYSTEM
#define UNIT_SYSTEM

#include "../../src/SystemImpl.h"


class UnitSystem{
    public:
        UnitSystem(){}
        ~UnitSystem(){}
      
        void unit_system_copy_constructor();

        void unit_system_assingmentOperator();
};

void unit_system_constructor();

void unit_system_destructor();

void unit_system_getName();

void unit_system_setName();

void unit_system_getValue();

void unit_system_setValue();

void run_unit_tests_system();

#endif