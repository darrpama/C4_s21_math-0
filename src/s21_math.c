#include "s21_math.h"

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

int s21_nan(long double x) {
    return x != x ? 1 : 0;
}

long double s21_asin(double x) {
    long double part = x, sum = x, n = 1;
    if (x > 1 || x < -1)
        sum = 0.0/0.0;
    else if (x == 1) {
        sum = S21M_PI / 2;
    } else if (x == -1) {
        sum = - S21M_PI / 2;
    } else {
        while (s21_fabs(part) > S21_EPS)  {
            part *= x * x * (2 * n - 1) * (2 * n) * (2 * n - 1) / ((2 * n + 1) * 4 * n * n);
            n++;
            sum += part;  
        }
    }
    return sum;
}

long double s21_acos(double x) {
    return (S21M_PI/2 - s21_asin(x));
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
    long double part = x, sum = x, n = 1;
    while (s21_fabs(part) > S21_EPS) {
        part = part * (-1) * x * x * (2 * n - 1) / (2 * n + 1);
        n++;
        sum += part;
    }
    return sum;
}

long double s21_ceil(double x) {
    long double answer = 0.0;
    if (!is_finite(x) || s21_fabs(x) >= 0x1.0p52) {
        answer = x;
    } else {
        if (x >= 0) {
            if ((int)x - x != 0) {
                answer = (long double)(int)x + 1.0;
            } else {
                answer = x;
            }
        } else if (x < -1) {
            if ((int)x - x != 0) {
                answer = (long double)(int)x;
            } else {
                answer = x;
            }
        } else {
            answer = -0.0;
        }
    }

    return answer;
}

long double s21_floor(double x) {
    long double result = x;
    if (!is_finite(x) || s21_fabs(x) >= 0x1.0p52) {
        result = x;
    } else {
        if (x >= 0) {
            if ((int)x - x != 0) {
                result = (long double)(int)x;
            } else {
                result = x;
            }
        } else if (x < -0) {
            if ((int)x - x != 0) {
                result = (long double)(int)x - 1;
            } else {
                result = x;
            }
        }
    }
    return result;
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

long double s21_exp(double x) {
    long double part = 1, sum = 1;
    int n = 1;
    if (s21_nan(x)) {
        sum = 0.0/0.0;
    } else if (x == S21_INF) {
        sum = S21_INF;
    } else if (x == -S21_INF) {
        sum = 0;
    } else {
        while (s21_fabs(part) > S21_EPS) {
            part = part * x / n;
            n++;
            sum += part;
        }
    }
    return sum;
}

long double s21_log (double x) {
    long double res = 0;
    int counter = 0;
    if (x < 0) {
        res = 0.0/0.0;
    } else if (x == 0) {
        res = -S21_INF;
    } else if (x == S21_INF) {
        res = S21_INF;
    } else if (x > 2) {
        while (x > 2) {
            x /= 10;
            counter++;
        }
        res = counter * S21_LOG10 + s21_log(x);
    } else {
        x--;
        long double part = -1, part2 = 1;
        int n = 1;
        while (s21_fabs(part2) > S21_EPS) {
            part = part * (-1) * x;
            part2 = part / n;
            n++;
            res += part2;
        }
    }
    return res;
}

long double s21_pow_xm(double x, double y) {
    long double res = 0;
    if (y == S21_INF) {
        if (x == 1) {
            res = 1;
        } else if (x < 1) {
            res = 0;
        } else {
            res = S21_INF;
        }
    } else if (y == -S21_INF) {
        if (x == 1) {
            res = 1;
        } else if (x < 1) {
            res = S21_INF;
        } else {
            res = 0;
        }
    } else {
        res = s21_exp(s21_log(x) * y);
    }
    return res;
}

long double s21_pow_xz(double x, double y) {
    long double res = 0;
    if (y == 0) {
        res = 1;
    } else {
        res = s21_exp(s21_log(x) * y);
    }
    return res;
}

long double s21_pow_xl (double x, double y) {
    long double sum = 0;
    if (y == S21_INF) {
        if (x > -1) {
            sum = 0;
        } else if (x == -1) {
            sum = 1;
        } else {
            sum = -S21_INF;
        }
    } else if (y == -S21_INF) {
        if (x > -1) {
            sum = -S21_INF;
        } else if (x == -1) {
            sum = 1;
        } else {
            sum = 0;
        }
    } else if ((long int)y == y) {
        if (y > 0) {
            x = -x;
            sum = 1;
            for (int k = 0; k < (long int)y; k++)
                sum *= x;
            if ((long int)y % 2 != 0)
                sum = -sum;
            x = -x;
        }
        if (y == 0) sum = 1;
        if (y < 0) {
            y = -y;
            long double tmp = 1;
            for (int k = 0; k < (long int)y; k++)
                tmp *= x;
            sum = 1 / tmp;
            y = -y;
        }
    } else {
        sum = s21_exp(s21_log(x) * y);
    }
    return sum;
}

long double s21_pow (double x, double y) {
    long double sum = 0;
    if (s21_nan(x))
        sum = S21_NAN;
    if (x > 0) {
        sum = s21_pow_xm(x, y);
    } else if (x == 0) {
        sum = s21_pow_xz(x, y);
    } else if (x < 0) {
        
    }
    return sum;
}

long double s21_tan(double x) {
    return s21_sin(x)/s21_cos(x);
}

long double s21_sqrt (double x) {
    long double xn1 = 10, xn = 0;
    if (s21_nan(x) || x < 0) {
        xn1 = S21_NAN;
    } else if (x == S21_INF) {
        xn1 = S21_INF;
    } else {
        while (s21_fabs(xn1 - xn) > S21_EPS) {
            xn = xn1;
            xn1 = (xn + x/xn) / 2;
        }
    }
    return xn1;
}

long double s21_fmod(double x, double y) {
    long double n = 0;
    int minus_flag = 0;
    y = s21_fabs(y);
    if (x < 0) {
        minus_flag = 1;
        x = s21_fabs(x);
    }
    long double difference = x;
    if (y == 0 || s21_nan(x) || s21_nan(y)) {
        difference = 0.0/0.0;
    } else {
    while (difference > y) {
        n++;
        difference = x - n * y;
    }
    }
    if (minus_flag == 1)
        difference = -difference;
    return difference;
}

long double s21_sin(double x) {
    long double part = 0, sum = 0;
    x = x_cutter(x);
    for (int n = 0; n <= 100; n++) {
        if (n == 0)
            part = x;
        else
            part = part * ((-1) * x * x) / (2 * n * (2 * n + 1)); 
        sum += part;
    }
    return sum;
}