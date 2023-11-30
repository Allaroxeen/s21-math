#include "s21_math.h"

long double s21_pow(double base, double exp) {
    long double res = 0.0;
    if (base != base || exp != exp || base == S21_P_INF ||
        base == S21_N_INF || exp == S21_P_INF || exp == S21_N_INF) {
        res = s21_pow_anomalous(exp, base);
    } else {
        if (base == 0 && exp > 0) {
            res = 0;
        } else if (base == 0 && exp == 0) {
            res = 1;
        } else {
            long double exp_abs = exp >= 0 ? exp : -exp,
                        exp_int = (int)exp_abs, exp_tail = exp_abs - exp_int;
            res = nature_pow(base, exp_int);
            exp_tail != 0.0 ? res *= s21_pow_tail(base, exp_tail) : 0;
        }
        res = exp >= 0 ? res : 1.0 / res;
    }
    return res;
}

long double s21_pow_tail(double base, double exp) {
    long double res = 1, costyl = 1;
    while (base > -1 && base < 1 && base != 0) {
        base *= 100;
        costyl *= 100;
    }
    if (base > 0 && base < 1.7976931348623158e+308) {
        long double sum_elem = 1;
        for (long double i = 1; i < 1000 && sum_elem > S21_EPSILON; i++) {
            sum_elem *= s21_log(base) * exp * 1.0 / (i * 1.0);
            res += sum_elem;
        }
    } else if (base < 0 && base > -1.7976931348623158e+308) {
        res = S21_NAN;
    }
    return costyl != 1 ? res / s21_pow(costyl, exp) : res;
}

long double s21_pow_anomalous(double exp, double base) {
    long double res = 0;
    if (exp != exp || base != base) {
        res = S21_NAN;
    } else if (exp == S21_P_INF) {
        if (base < -1 && base != S21_N_INF) {
            res = S21_P_INF;
        } else if (base == 0) {
            res = 0;
        } else if (base == -1) {
            res = 1;
        } else if (base > -1 && base < 0) {
            res = 0;
        } else if (base == 1) {
            res = 1;
        } else if (base > 0 && base < 1) {
            res = 0;
        } else if (base > 1 && base != S21_P_INF) {
            res = S21_P_INF;
        } else if (base == S21_P_INF) {
            res = S21_P_INF;
        } else if (base == S21_N_INF) {
            res = S21_P_INF;
        }
    } else if (exp == S21_N_INF) {
        if (base < -1) {
            res = 0.0;
        } else if (base == 0) {
            res = S21_P_INF;
        } else if (base == -1) {
            res = 1;
        } else if (base > -1 && base < 0) {
            res = S21_P_INF;
        } else if (base == 1) {
            res = 1;
        } else if (base > 0 && base < 1) {
            res = S21_P_INF;
        } else if (base > 1 && base != S21_P_INF) {
            res = 0;
        } else if (base == S21_P_INF) {
            res = 0;
        }
    } else if (base == S21_P_INF) {
        if (exp < 0 && exp > -1) {
            res = 0;
        } else if (exp > 0 && exp < 1) {
            res = S21_P_INF;
        } else if (exp == 1) {
            res = S21_P_INF;
        } else if (exp == -1) {
            res = 0.0;
        } else if (exp > 1) {
            res = S21_P_INF;
        } else if (exp < -1) {
            res = 0;
        } else if (exp == 0) {
            res = 1;
        }
    } else if (base == S21_N_INF) {
        if (exp < -1) {
            res = 0;
        } else if (exp == -1) {
            res = -0.0;
        } else if (exp > -1 && exp < 0) {
            res = 0;
        } else if (exp == 0) {
            res = 1;
        } else if (exp > 0 && exp < 1) {
            res = S21_P_INF;
        } else if (exp == 1) {
            res = S21_N_INF;
        } else if (exp > 1) {
            res = S21_P_INF;
        }
    }
    return res;
}
