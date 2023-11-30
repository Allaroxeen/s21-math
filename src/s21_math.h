#ifndef SRC_S21_MATH_H_
#define SRC_S21_MATH_H_
#include <stddef.h>
#include <stdio.h>
#define S21_PI 3.1415926535897932384626433832795
#define S21_EXP 2.718281828459045235360287471352662497
#define S21_PI_2 S21_PI / 2.0
#define S21_LN2 0.693147180559945309417
#define S21_EPSILON 1.00e-16
#define S21_EPS 1e-6
#define S21_NAN (0.0 / 0.0L)
#define S21_P_INF (1.0 / 0.0L)
#define S21_N_INF (-1.0 / 0.0L)

// основные функции
int s21_abs(int x);
long double s21_acos(double x);
long double s21_asin(double x);
long double s21_atan(double x);
long double s21_ceil(double x);
long double s21_cos(double x);
long double s21_exp(double x);
long double s21_fabs(double x);
long double s21_floor(double x);
long double s21_fmod(double x, double y);
long double s21_log(double x);
long double s21_pow(double base, double exp);
long double s21_sin(double x);
long double s21_sqrt(double x);
long double s21_tan(double x);
long double s21_asin(double x);
// Дополнительные
long double factorial(long double num);
long double nature_pow(long double base, long double exp);
long double s21_pow_tail(double base, double exp);
long double s21_pow_anomalous(double exp, double base);

#endif  // SRC_S21_MATH_H_
