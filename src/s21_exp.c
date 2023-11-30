#include "s21_math.h"
long double s21_exp(double x) {
    long double res = 1;
    if (x == x && x != S21_P_INF && x != S21_N_INF) {
        double new_x = x > 0 ? x : -x;
        long double sum_elem = 1, tail_x = (long double)(new_x - (int)new_x);
        for (int i = 1; sum_elem > S21_EPSILON; i++) {
            sum_elem *= tail_x / (long double)(i * 1.0);
            res += sum_elem;
        }
        res *= s21_pow(S21_EXP, new_x - tail_x);
        x < 0 ? res = 1.0 / res : res;
    } else {
        x != x ? res = S21_NAN : 0;
        x == S21_P_INF ? res = S21_P_INF : 0;
        x == S21_N_INF ? res = 0 : 1;
    }

    return res;
}
