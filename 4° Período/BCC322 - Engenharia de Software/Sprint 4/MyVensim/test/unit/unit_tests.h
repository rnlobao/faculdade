#include "../../src/systemImpl.h"

#define RESET "\033[0m"  /* Escape sequence to reset color output to default. */
#define GREEN "\033[32m" /* Escape sequence to a green color output. */

/*!
  Function prototype for the System class' "+" global operator unit test.
*/
void unit_test_global_sumOperator();

/*!
  Function prototype for the System class' "-" global operator unit test.
*/
void unit_test_global_minusOperator();

/*!
  Function prototype for the System class' "*" global operator unit test.
*/
void unit_test_global_timesOperator();

/*!
  Function prototype for the System class' "/" global operator unit test.
*/
void unit_test_global_divisionOperator();

/*!
  Function prototype for the function that runs all the global unit tests.
*/
void run_unit_tests_globals();