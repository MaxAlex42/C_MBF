#include <stdio.h>
#include <time.h>
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <stdint.h>
#include <stdlib.h>
#include <cmocka.h>
#include "includes/arrays.h"

// Helper function prototypes
int generateLength();
int* generateArray(int length);
void freeArray(int* arr);

/*
 * Test cases
 */
static void test_quick_sort_i(void **state) {
    (void)state;

    int n = generateLength();
    int *arr = generateArray(n);

    qui_sort_i(arr, 0, n);

    for (int i = 1; i < n; i++) {
        assert_true(arr[i - 1] <= arr[i]);
    }

    freeArray(arr);
}

static void test_sum_i(void **state) {
    (void)state;

    int n = generateLength();
    int *arr = generateArray(n);

    int expected_sum = 0;
    for (int i = 0; i < n; i++) {
        expected_sum += arr[i];
    }

    int actual_sum = sum_i(arr, n);
    assert_int_equal(actual_sum, expected_sum);

    freeArray(arr);
}

static void test_max_i(void **state) {
    (void)state;

    int n = generateLength();
    int *arr = generateArray(n);

    int expected_max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > expected_max) {
            expected_max = arr[i];
        }
    }

    int actual_max = max_i(arr, n);
    assert_int_equal(actual_max, expected_max);

    freeArray(arr);
}

static void test_min_i(void **state) {
    (void)state;

    int n = generateLength();
    int *arr = generateArray(n);

    int expected_min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < expected_min) {
            expected_min = arr[i];
        }
    }

    int actual_min = min_i(arr, n);
    assert_int_equal(actual_min, expected_min);

    freeArray(arr);
}

/*
 * Main function to run all tests
 */
int main(void) {
    // Seed random number generator once in main
    srand((unsigned int)time(NULL));

    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_quick_sort_i),
        cmocka_unit_test(test_sum_i),
        cmocka_unit_test(test_max_i),
        cmocka_unit_test(test_min_i),
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}

/*
 * Helper functions
 */
int generateLength() {
    return (rand() % 500) + 1;
}

int* generateArray(int length) {
    int* arr = (int*)malloc(length * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    for (int i = 0; i < length; i++) {
        arr[i] = (rand() % 2000) - 999;
    }
    return arr;
}

void freeArray(int* arr) {
    free(arr);
}