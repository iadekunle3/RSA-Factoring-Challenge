#include <stdio.h>
#include <stdlib.h>
#include "head.h"

// Function to create a polynomial
Polynomial *create_polynomial(int degree, double *coeffs) {
    Polynomial* poly = (Polynomial*) malloc(sizeof(Polynomial));
    poly->degree = degree;
    poly->coeffs = coeffs;
    return poly;
}

// Function to choose a polynomial
Polynomial *choose_polynomial(int degree) {
    double *coeffs = (double*) malloc((degree + 1) * sizeof(double));
    for (int i = 0; i <= degree; i++) {
        coeffs[i] = 1.0;
    }
    return create_polynomial(degree, coeffs);
}
