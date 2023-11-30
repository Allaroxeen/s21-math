
#include "s21_math.h"

long double s21_cos(double x) {
    long double result = 1;
    x = (x < 0) ? -x : x;
    if ((x != x) || (x == S21_P_INF) || (x == S21_N_INF)) {
        result = S21_NAN;
    } else {
        while (x >= 2 * S21_PI) {
            x -= 2 * S21_PI;
        }
        long double next = 1.0;
        size_t iter_limit = 1000000000;
        for (size_t count = 1; count < iter_limit; count++) {
            long double n = (long double)count;

            next *= -s21_pow(x, 2) / ((2.0 * n - 1) * 2.0 * n);
            result += next;

            // printf("n: %ld result %+.12Lf\n", count, result);

            if (s21_fabs(next) < S21_EPSILON) {  // Если достигли необходимой точности
                // printf("%.10Lf < %.10Lf\n", next, precision_limit);
                break;  // прерываем
            }
        }
    }
    return result;
}
