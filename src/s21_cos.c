#include <math.h>
#include <stdio.h>
#define S21M_PI 3.141592653589793238462643383279502884

// int cos_fact(int n); 
long double s21_cos(double x); 
// long double cos_x_pow(long double x, int n); 
long double x_cutter (long double x); 

int main() {
printf("right result is %lf\n", cos(100));
printf("our result is %Lf\n", s21_cos(100));
return 0;
}

long double s21_cos(double x) {
    long double part = 0, sum = 0;
    x = x_cutter(x);
    for (int n = 0; n <= 100; n++) {
        if (n == 0)
            part = 1;
        else
            part = part * ((-1) * x * x) / (2*n * (2*n - 1)); 
        sum += part;
    }
    return sum;
}

long double x_cutter(long double x) {
    int minus = 0;
    if (x < 0) {
        minus = 1;
        x = x * (-1);
    }
    while (x > 2 * S21M_PI) {
         x -= (2 * S21M_PI);
    }
    if (minus == 1)
        x = x * (-1);
    return x;
}

