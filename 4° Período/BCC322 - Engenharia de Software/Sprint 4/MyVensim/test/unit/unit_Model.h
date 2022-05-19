#ifndef UNIT_MODEL
#define UNIT_MODEL

#include "../../src/ModelImpl.h"
#include "unit_Flow.h"

void unit_model_constructor();

void unit_model_destructor();

void unit_model_addSystem();

void unit_model_removeSystem();

void unit_model_addFlow();

void unit_model_removeFlow();

void unit_model_getName();

void unit_model_setName();

void unit_model_getTime();

void unit_model_setTime();

void unit_model_incrementTime();

void run_unit_tests_model();

#endif