#ifndef SRC_S21_MATH_H_
#define SRC_S21_MATH_H_
#include <stdio.h>
#include <stdlib.h>

#define S21_EPS 1e-12
#define S21_EPS1 1e-6
#define S21_LOG10 2.30258509299404568401799145468436421
#define S21_LOG01 -2.302585092994045684017991454684364207601101488628772976033
#define S21M_PI 3.141592653589793238462643383279502884
#define S21_E 2.718281828459
#define S21_E2 7.3890560989306495

#define S21_NAN (__builtin_nanf(""))
#define S21_INF (__builtin_inff())

#define is_nan(x) __builtin_isnan(x)
#define is_inf(x) __builtin_isinf(x)
#define is_finite(x) __builtin_isfinite(x)

//  lib func
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
long double s21_log(double x);
long double s21_pow_xm(double x, double y);
long double s21_pow_xz(double x, double y);
long double s21_pow_xl(double x, double y);
long double s21_pow(double x, double y);
long double s21_tan(double x);
long double s21_sqrt(double x);
long double s21_fmod(double x, double y);
long double s21_sin(double x);

#endif  //  SRC_S21_MATH_H_

