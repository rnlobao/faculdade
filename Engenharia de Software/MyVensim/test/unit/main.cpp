#ifndef MAIN_UNIT_TESTS
#define MAIN_UNIT_TESTS

#include "unit_System.h"
#include "unit_Model.h"
#include "unit_Flow.h"

int main(){
    run_unit_tests_system();
    run_unit_tests_flow();
    run_unit_tests_model();
    return 0;
}

#endif