#include <stdlib.h>
#include <stdio.h>
#include <setjmp.h>
#include <cmocka.h>
#include "includes/arrays.h"

int generateLength();
int* generateArray_int(int length);
float* generateArray_float(int length);
void freeArray(void* arr);

/*
 * Test cases
 */
static void test_quick_sort_i(void **state) {
    (void)state;

    int n = generateLength();
    int *arr = generateArray_int(n);

    qui_sort_i(arr, 0, n);

    for (int i = 1; i < n; i++) {
        assert_true(arr[i - 1] <= arr[i]);
    }

    freeArray(arr);
}

static void test_bubble_sort_i(void **state) {
    (void)state;

    int n = generateLength();
    int *arr = generateArray_int(n);

    bub_sort_i(arr, n);

    for (int i = 1; i < n; i++) {
        assert_true(arr[i -1] <= arr[i]);
    }

    freeArray(arr);
}

static void test_insertion_sort_i(void **state) {
    (void)state;

    int n = generateLength();
    int *arr = generateArray_int(n);

    ins_sort_i(arr, n);

    for (int i = 1; i < n; i++) {
        assert_true(arr[i -1] <= arr[i]);
    }

    freeArray(arr);
}

static void test_selection_sort_i(void **state) {
    (void)state;

    int n = generateLength();
    int *arr = generateArray_int(n);

    sel_sort_i(arr, n);

    for (int i = 1; i < n; i++) {
        assert_true(arr[i - 1] <= arr[i]);
    }
    freeArray(arr);
}

static void test_sum_i(void **state) {
    (void)state;

    int n = generateLength();
    int *arr = generateArray_int(n);

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
    int *arr = generateArray_int(n);

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
    int *arr = generateArray_int(n);

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

static void test_quick_sort_f(void **state) {
    (void)state;

    int n = generateLength();
    float *arr = generateArray_float(n);
    qui_sort_f(arr, 0, n);
    for (int i = 1; i < n; i++) {
        assert_true(arr[i -1] <= arr[i]);
    }
    freeArray(arr);
}

static void test_bubble_sort_f(void **state) {
    (void)state;

    int n = generateLength();
    float *arr = generateArray_float(n);
    bub_sort_f(arr, n);
    for (int i = 1; i < n; i++) {
        assert_true(arr[i -1] <= arr[i]);
    }
    freeArray(arr);
}

/*
 * Helper functions
 */
int generateLength() {
    return (rand() % 500) + 1;
}

int* generateArray_int(int length) {
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

float* generateArray_float(int length) {
   float* arr = (float*)malloc(length * sizeof(float));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    for (int i = 0; i < length; i++) {
        arr[i] = ((float)rand() / (float)(RAND_MAX)) * 1998.0 - 999.0;
    }

    return arr;
}

void freeArray(void* arr) {
    free(arr);
}

void run_array_tests(void) {
    const struct CMUnitTest array_tests[] = {
        cmocka_unit_test(test_quick_sort_i),
        cmocka_unit_test(test_bubble_sort_i),
        cmocka_unit_test(test_insertion_sort_i),
        cmocka_unit_test(test_selection_sort_i),
        cmocka_unit_test(test_sum_i),
        cmocka_unit_test(test_max_i),
        cmocka_unit_test(test_min_i),
        cmocka_unit_test(test_quick_sort_f),
        cmocka_unit_test(test_bubble_sort_f),
    };
    cmocka_run_group_tests(array_tests, NULL, NULL);
}