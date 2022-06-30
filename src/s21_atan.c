#include <math.h>
#include <stdio.h>
#define S21M_PI 3.14159265358979323846

long double s21_atan(double x); 
long double s21_atan_calc(double x);

int main() {
    printf("right result is %lf\n", atan(1));
    printf("our result is %Lf\n", s21_atan(1));
    return 0;
}

long double s21_atan(double x) {
    long double sum = 0;
    if (x > -1 && x < 1) {
        sum = s21_atan_calc(x);
    } else if (x < -1) {
        sum = S21M_PI/2 - s21_atan_calc(1/x);
    } else if (x > 1) {
        sum = -S21M_PI/2 - s21_atan_calc(1/x);
    } else if (x == 0) {
        sum = 0;
    } else if (x == 1.0) {
        sum = S21M_PI / 4;
    } else if (x == -1.0) {
        sum = -S21M_PI / 4;
    }
    return sum;
}

long double s21_atan_calc(double x) {
    long double part = 0, sum = 0;
    for (int n = 0; n <= 100; n++) {
        if (n == 0)
            part = x;
        else
            part = part * (-1) * x * x * (2 * n - 1) / (2 * n + 1);
        sum += part;
    }
    return sum;
}
