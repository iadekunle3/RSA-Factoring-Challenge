#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
#include "head.h"

double complex eval_poly(double complex *coeffs, int degree, double complex x) {
	double complex y = 0;
	for (int i = 0; i <= degree; i++) {
		y += coeffs[i] * cpow(x, i);
	}
	return y;
}

double complex *aberth_method(double complex *coeffs, int degree) {
	double complex *roots = malloc(degree * sizeof(double complex));
	// Initialize the roots with some values
	for (int i = 0; i < degree; i++) {
		roots[i] = i + 1;
	}
	for (int iter = 0; iter < MAX_ITER; iter++) {
		for (int i = 0; i < degree; i++) {
			double complex g = eval_poly(coeffs, degree, roots[i]) / cpow(roots[i], degree);
			double complex h = cpow(g, 2) - (eval_poly(coeffs, degree - 1, roots[i]) / roots[i]);
			double complex r = 0;
			for (int j = 0; j < degree; j++) {
				if (j != i) {
					r += 1 / (roots[i] - roots[j]);
				}
			}
			double complex a = (-g + csqrt((degree - 1) * ((degree * h) - cpow(g, 2)))) / (degree * r);
			roots[i] -= a;
			if (cabs(a) < EPSILON) {
				return roots;
			}
		}
	}
	return roots;
}
int find(void) {
    int degree = 2;
    double complex coeffs[] = {1, 0, -1};  // x^2 - 1
    double complex* roots = aberth_method(coeffs, degree);
    for (int i = 0; i < degree; i++) {
        printf("Root %d: %f + %fi\n", i, creal(roots[i]), cimag(roots[i]));
    }
    free(roots);
    return 0;
}
