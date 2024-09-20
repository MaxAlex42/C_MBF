#ifndef ARRAYS_H
#define ARRAYS_H

#include <stddef.h>
#include <math.h>

int max_i(int a[], size_t n);
long max_l(long a[], size_t n);
long long max_ll(long long a[], size_t n);
float max_f(float a[], size_t n);
double max_d(double a[], size_t n);
long double max_ld(long double a[], size_t n);

int min_i(int a[], size_t n);
long min_l(long a[], size_t n);
long long min_ll(long long a[], size_t n);
float min_f(float a[], size_t n);
double min_d(double a[], size_t n);
long double min_ld(long double a[], size_t n);

int sum_i(int a[], size_t n);
long sum_l(long a[], size_t n);
long long sum_ll(long long a[], size_t n);
float sum_f(float a[], size_t n);
double sum_d(double a[], size_t n);
long double sum_ld(long double a[], size_t n);

void bub_sort_i(int a[], size_t n);
void bub_sort_l(long a[], size_t n);
void bub_sort_ll(long long a[], size_t n);
void bub_sort_f(float a[], size_t n);
void bub_sort_d(double a[], size_t n);
void bub_sort_ld(long double a[], size_t n);
void bub_sort_i(int a[], size_t n);
void bub_sort_l(long a[], size_t n);
void bub_sort_ll(long long a[], size_t n);
void bub_sort_f(float a[], size_t n);
void bub_sort_d(double a[], size_t n);
void bub_sort_ld(long double a[], size_t n);

void qui_sort_i(int arr[], size_t n, size_t k);
void qui_sort_l(long arr[], size_t n, size_t k);
void qui_sort_ll(long long arr[], size_t n, size_t k);
void qui_sort_f(float arr[], size_t n, size_t k);
void qui_sort_d(double arr[], size_t n, size_t k);
void qui_sort_ld(long double arr[], size_t n, size_t k);

void ins_sort_i(int a[], size_t n);
void ins_sort_l(long a[], size_t n);
void ins_sort_ll(long long a[], size_t n);
void ins_sort_f(float a[], size_t n);
void ins_sort_d(double a[], size_t n);
void ins_sort_ld(long double a[], size_t n);
void ins_sort_i(int a[], size_t n);
void ins_sort_l(long a[], size_t n);
void ins_sort_ll(long long a[], size_t n);
void ins_sort_f(float a[], size_t n);
void ins_sort_d(double a[], size_t n);
void ins_sort_ld(long double a[], size_t n);

void sel_sort_i(int a[], size_t n);
void sel_sort_l(long a[], size_t n);
void sel_sort_ll(long long a[], size_t n);
void sel_sort_f(float a[], size_t n);
void sel_sort_d(double a[], size_t n);
void sel_sort_ld(long double a[], size_t n);

#endif
