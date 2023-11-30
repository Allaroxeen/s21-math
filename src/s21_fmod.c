#include "s21_math.h"

long double s21_fmod(double x, double y) {
    long double res = 0;
    if (y != S21_P_INF && y != S21_N_INF && x != S21_P_INF && x != S21_N_INF) {
        if (y != 0 && x != 0) {
            long double k = 1;
            if (x < 0) {
                x = -x;
                k = -1;
            }
            if (y < 0) {
                y = -y;
            }
            long double a = x;
            long double b = y;
            long double i = 0;
            while (a >= 0.0) {
                a = x - (i * b);
                i++;
                // printf("x = %f\n", a);
            }
            i -= 2;
            res = k * (x - (i * y));
        } else {
            res = 0 / y;
        }
    } else {
        y == S21_P_INF || y == S21_N_INF ? res = x : 0;
        x == S21_P_INF || x == S21_N_INF ? res = S21_NAN : 0;
    }
    return res;
}
