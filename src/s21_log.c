#include "s21_math.h"

long double s21_log(double x) {
    long double result = 0;
    if (x != x || x < 0.0) {
        result = S21_NAN;
    } else if (x == S21_P_INF) {
        result = S21_P_INF;
    } else if (!x) {
        result = S21_N_INF;
    } else if (x < 2.0) {
        long double y = x - 1;
        long double ypow = y;
        for (int i = 1; s21_fabs(ypow / i) > S21_EPSILON; i++) {
            result += ypow / i * (i % 2 == 1 ? 1 : -1);
            ypow *= y;
        }
    } else {
        long double coef;
        for (coef = 0; x >= 2.0; coef++) {
            x /= 2;
        }
        result = coef * S21_LN2 + s21_log(x);
    }
    return result;
}
