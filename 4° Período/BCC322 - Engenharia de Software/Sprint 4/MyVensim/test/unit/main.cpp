#ifndef MAIN_UNIT_TESTS
#define MAIN_UNIT_TESTS

#include "./unit_system.h"
#include "./unit_model.h"
#include "./unit_tests.h"

int main(){
    run_unit_tests_system();
    run_unit_tests_flow();
    run_unit_tests_model();
    run_unit_tests_globals();
    return 0;
}

#endif