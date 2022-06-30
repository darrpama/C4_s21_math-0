#include <math.h>
#include <stdio.h>
#define S21M_PI 3.141592653589793238462643383279502884
long double s21_asin (double x);
long double s21_acos (double x);

int main () {
    printf("right result is %lf\n", acos(1e-5));
    printf("our result is %Lf\n", s21_acos(1e-5));
    return 0;
}

long double s21_asin(double x) {
    long double part = 0, sum = 0;
    if (fabs(x) > 1)
        sum = 0.0/0.0;
    else {
        for (int n = 0; n <= 100; n++) {
            if (n == 0)
                part = x;
            else
                part = part * x * x * (2 * n - 1) * (2 * n) * (2 * n - 1) / ((2 * n + 1) * 4 * n * n);
            sum += part;  
        }
    }
    return sum;
}

long double s21_acos(double x) {
    return (S21M_PI/2 - s21_asin(x));
}
