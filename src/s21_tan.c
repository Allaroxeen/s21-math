#include "s21_math.h"

long double s21_tan(double x) {
    long double result = 0;
    if ((x != x) || (x == S21_P_INF) || (x == S21_N_INF)) {
        result = S21_NAN;
    } else {
        if ((x > S21_PI / 2.0) || (x < -S21_PI / 2)) {
            while (x > (S21_PI / 2)) {
                x -= S21_PI;
            }

            while (x < (-S21_PI / 2)) {
                x += S21_PI;
            }
        }

        if (s21_fabs(s21_fabs(x) - S21_PI / 2) < S21_EPSILON) {
            result = (x > 0) ? 16331239353195370.0 : -16331239353195370.0;
        } else {
            result = s21_sin(x) / s21_cos(x);
        }
    }
    return result;
}
