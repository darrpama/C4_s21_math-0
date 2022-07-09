#ifndef SRC_S21_MATH_H_
#define SRC_S21_MATH_H_
#include <stdio.h>
#include <stdlib.h>

#define S21_EPS 1e-12
#define S21_LOG10 2.30258509299404568401799145468436421
#define S21_NAN 0.0/0.0
#define S21_INF 1.0/0.0
#define S21M_PI 3.141592653589793238462643383279502884
#define S21_E 2.718281828459

int s21_abs(int x);
long double s21_fabs(double x);
int s21_nan(long double x);
long double s21_asin(double x);
long double s21_acos(double x);
long double s21_atan(double x);
long double s21_atan_calc(double x);
long double s21_ceil(double x);
long double s21_floor(double x);
long double s21_cos(double x);
long double x_cutter(long double x);
long double s21_exp(double x);
long double s21_log (double x);
long double s21_pow_xm(double x, double y);
long double s21_pow_xz(double x, double y);
long double s21_pow_xl (double x, double y);
long double s21_pow (double x, double y);
long double s21_tan(double x);
long double s21_sqrt (double x);
long double s21_fmod(double x, double y);
long double s21_sin(double x);

#endif  //  SRC_S21_MATH_H_

