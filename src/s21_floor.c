#include "s21_math.h"
long double s21_floor(double x) {
    return (x != x) ? S21_NAN : (x >= 0) ? (long int)x
                                         : (long int)x - 1;
}
