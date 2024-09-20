#include "includes/arrays.h"
#include <math.h>

/***************************************************************
*   Defines a macro that finds the maximum number of an array  *
*   data types supported are the standard data types           *
*   probably will be extended to fixed bit types               *
****************************************************************/

#define MAX_FUNC(type, name)         \
type name(type a[], size_t n) {      \
    type max = a[0];                 \
    for (size_t i = 1; i < n; ++i) { \
        if (a[i] > max) {            \
            max = a[i];              \
        }                            \
    }                                \
    return max;                      \
}

/***************************************************************
*   Defines a macro that finds the minimum number of an array  *
*   data types supported are the standard data types           *
*   probably will be extended to fixed bit types               *
****************************************************************/

#define MIN_FUNC(type, name)         \
type name(type a[], size_t n) {      \
    type min = a[0];                 \
    for (size_t i = 1; i < n; ++i) { \
        if (a[i] < min) {            \
            min = a[i];              \
        }                            \
    }                                \
    return min;                      \
}

/***************************************************************
*   Defines a macro that the sum of values of an array         *
*   data types supported are the standard data types           *
*   probably will be extended to fixed bit types               *
****************************************************************/

#define SUM_ARR(type, name)          \
type name(type a[], size_t n) {      \
    type sum = 0;                    \
    for (size_t i = 0; i < n; i++) { \
        sum += a[i];                 \
    }                                \
    return sum;                      \
}

/***************************************************************
*   Defines a macro that sorts an array using bubble sort      *
*   data types supported are the standard data types           *
*   probably will be extended to fixed bit types               *
****************************************************************/

#define BUBBLE_SORT(type, name)                 \
void name (type a[], size_t n) {                \
    for (size_t i = n - 1; i > 0; i--) {        \
        for (size_t j = 0; j < i; j++) {        \
            if (a[j] > a[j + 1]) {              \
                type h = a[j];                  \
                a[j] = a[j + 1];                \
                a[j + 1] = h;                   \
            }                                   \
        }                                       \
    }                                           \
}

/***************************************************************
*   Defines a macro that sorts an array using quick sort       *
*   data types supported are the standard data types           *
*   probably will be extended to fixed bit types               *
*   n is the low and k is the high (pivot's)                   *
****************************************************************/

#define QUICK_SORT(type, name)                     \
void name (type a[], size_t low, size_t high) {    \
    if (low < high) {                              \
        type pivot = a[high];                      \
        size_t i = low;                            \
                                                   \
        for (size_t j = low; j < high; j++) {      \
            if (a[j] <= pivot) {                   \
                if (i != j) {                      \
                    type temp = a[i];              \
                    a[i] = a[j];                   \
                    a[j] = temp;                   \
                }                                  \
                i++;                               \
            }                                      \
        }                                          \
        type temp = a[i];                          \
        a[i] = a[high];                            \
        a[high] = temp;                            \
        if (i > 0) {                               \
            name(a, low, i - 1);                   \
        }                                          \
        name(a, i + 1, high);                      \
    }                                              \
}

/***************************************************************
*   Defines a macro that sorts an array using insertion sort   *
*   data types supported are the standard data types           *
*   probably will be extended to fixed bit types               *
****************************************************************/

#define INSERTION_SORT(type, name)     \
void name (type a[], size_t n) {       \
    for (size_t i = 1;  i < n; i++) {  \
        type k = a[i];                 \
        size_t j = i;                  \
        while (j > 0 && k < a[j - 1]) {\
            a[j] = a[j - 1];           \
            j--;                       \
        }                              \
        a[j] = k;                      \
    }                                  \
}

/***************************************************************
*   Defines a macro that sorts an array using selection sort   *
*   data types supported are the standard data types           *
*   probably will be extended to fixed bit types               *
****************************************************************/

#define SELECTION_SORT(type, name)   \
void name (type a[], size_t n) {     \
    if (n <= 1) {                    \
        return;                      \
    }                                \
    int max_index = 0;               \
    for (size_t i = 0; i < n; i++) { \
        if (a[i] > a[max_index]) {   \
            max_index = i;           \
        }                            \
    }                                \
    type h = a[max_index];           \
    a[max_index] = a[n - 1];         \
    a[n - 1] = h;                    \
    name (a, n - 1);                 \
}

#define AVERAGE_ARR(type, name)      \
double name (type a[], size_t n) {   \
    type sum = 0;                    \
    for (int i = 0; i < n; i++) {    \
        sum += a[i];                 \
    }                                \
    return sum / n;                  \
}

MAX_FUNC(int, max_i)
MAX_FUNC(long, max_l)
MAX_FUNC(long long, max_ll)
MAX_FUNC(float, max_f)
MAX_FUNC(double, max_d)
MAX_FUNC(long double, max_ld)

MIN_FUNC(int, min_i)
MIN_FUNC(long, min_l)
MIN_FUNC(long long, min_ll)
MIN_FUNC(float, min_f)
MIN_FUNC(double, min_d)
MIN_FUNC(long double, min_ld)

SUM_ARR(int, sum_i)
SUM_ARR(long, sum_l)
SUM_ARR(long long, sum_ll)
SUM_ARR(float, sum_f)
SUM_ARR(double, sum_d)
SUM_ARR(long double, sum_ld)

BUBBLE_SORT(int, bub_sort_i)
BUBBLE_SORT(long, bub_sort_l)
BUBBLE_SORT(long long, bub_sort_ll)
BUBBLE_SORT(float, bub_sort_f)
BUBBLE_SORT(double, bub_sort_d)
BUBBLE_SORT(long double, bub_sort_ld)

QUICK_SORT(int, qui_sort_i)
QUICK_SORT(long, qui_sort_l)
QUICK_SORT(long long, qui_sort_ll)
QUICK_SORT(float, qui_sort_f)
QUICK_SORT(double, qui_sort_d)
QUICK_SORT(long double, qui_sort_ld)

INSERTION_SORT(int, ins_sort_i)
INSERTION_SORT(long, ins_sort_l)
INSERTION_SORT(long long, ins_sort_ll)
INSERTION_SORT(float, ins_sort_f)
INSERTION_SORT(double, ins_sort_d)
INSERTION_SORT(long double, ins_sort_ld)

SELECTION_SORT(int, sel_sort_i)
SELECTION_SORT(long, sel_sort_l)
SELECTION_SORT(long long, sel_sort_ll)
SELECTION_SORT(float, sel_sort_f)
SELECTION_SORT(double, sel_sort_d)
SELECTION_SORT(long double, sel_sort_ld)
