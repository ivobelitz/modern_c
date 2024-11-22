#include <math.h>
#include <stdio.h>
#include <stdlib.h>

static double const eps = 1.0e-7;
static double const PI = 3.14159265;

double derivative(double F(double), double x) {
    double x_p = x + eps;
    double x_m = x - eps;
    return (F(x_p) - F(x_m)) / (x_p - x_m);
}

int main(void) {
    double sin_d_0 = derivative(sin, 0.0);
    printf("The derivative of sin(%f) = %f\n", 0.0, sin_d_0);
    double cos_d_pi_over_2 = derivative(cos, PI / 2);
    printf("The derivative of cos(PI / 2) = %f\n", cos_d_pi_over_2);
    return EXIT_SUCCESS;
}