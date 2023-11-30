
#include "s21_math.h"

long double nature_pow(long double base, long double exp) {
    long double exp1 = exp >= 0 ? exp : -exp, res = (long double)base;
    if (res == 0) {
        res = exp >= 0 ? 0 : S21_P_INF;
    } else {
        if (exp == 0) {
            res = 1;
        } else {
            for (long double i = 1; i < exp1; i++) res *= (long double)base;
        }
        res = exp > 0 ? res : 1 / res;
    }
    return res;
}

long double factorial(long double num) {
    long double num2 = 1;
    if (num == 0 || num == 1.0) {
    } else {
        for (long double i = 1.0; i <= num; i++) {
            num2 *= i;
        }
    }
    return num2;
}
