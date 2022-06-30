#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int s21_abs(int x);
long double s21_fabs(double x);

int main() {
    printf("right result is %lf\n", fabs(-4.5));
    printf("our result is %Lf\n", s21_fabs(-4.5));
    return 0;
}

int s21_abs(int x) {
    if (x < 0)
        x *= -1;
    return x;
}

long double s21_fabs(double x) {
    if (x < 0)
        x *= -1;
    return x;
}
