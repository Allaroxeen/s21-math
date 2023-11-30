#include "s21_math.h"

long double s21_sin(double x) {
    long double sum_elem = 0, res = 0;
    int i = 0;
    while (x > 2 * S21_PI) {
        x -= 2 * S21_PI;
    }
    while (x < 0) {
        x += 2 * S21_PI;
    }
    do {
        sum_elem = s21_pow(-1.0, i + 0.0) * (s21_pow(x, (2.0 * i + 1)) / factorial((2.0 * i + 1)));
        res += sum_elem;
        i++;
        sum_elem = sum_elem > 0 ? sum_elem : -sum_elem;
    } while (sum_elem > S21_EPSILON);
    return res;
}
