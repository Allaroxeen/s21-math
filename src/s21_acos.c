#include "s21_math.h"

long double s21_acos(double x) {
    return x < 0 ? (S21_PI - s21_acos(-x)) : (S21_PI_2 - s21_asin(x));
}
