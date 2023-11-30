#include "s21_math.h"
long double s21_ceil(double x) {
    return (x != x) ? S21_NAN : (x < 0 && x > -1) ? -0
                            : (x > (long int)x)   ? (long int)x + 1
                                                  : (long int)x;
}
