#include <stdio.h>
#include <time.h>
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <stdint.h>
#include <stdlib.h>
#include <cmocka.h>
#include "includes/arrays.h"
#include "includes/test-arrays.h"

/*
 * Main function to run all tests
 */
int main(void) {
    srand((unsigned int)time(NULL));

    run_array_tests();

    return 0;
}