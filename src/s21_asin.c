#include "s21_math.h"

long double s21_asin(double x) {
    long double sum_elem = (long double)x, res = (long double)x;
    if (x >= 0 && x < 1) {
        for (long double i = 1.0; sum_elem > S21_EPSILON; i++) {
            sum_elem *= (((2.0 * i - 1) * x * (2.0 * i - 1) * x) /
                         ((2.0 * (2.0 * i + 1) * i)));  // (2*I +1)*(2*I)
            res += sum_elem;
        }
    } else if (x == 1) {
        res = 1.57079632679489655800;
    } else if (x < 0) {
        res = -s21_asin(-x);
    } else {
        res = S21_NAN;
    }
    return res;
}
