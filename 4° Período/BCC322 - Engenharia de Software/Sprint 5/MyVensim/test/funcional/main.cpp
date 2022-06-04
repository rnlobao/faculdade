#ifndef MAIN_FUNCIONAL_TESTS
#define MAIN_FUNCIONA_TESTS

#include "funcional_tests.h"
#include "../../src/Model.h"
#include "../../src/System.h"
#include "../../src/Flow.h"

int main(){
    exponentialFuncionalTest();
    logisticalFuncionalTest();
    complexFuncionalTest();
    return 0;
}

#endif