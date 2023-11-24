#include <stdio.h>
#include <stdlib.h>
#include "head.h"

Polynomial *create_poly(int degree, double *coeffs) {
    Polynomial *poly = (Polynomial*) malloc(sizeof(Polynomial));
    poly->degree = degree;
    poly->coeffs = coeffs;
    return poly;
}
double *find_roots(Polynomial *poly) {
    int degree = poly->degree;
    double *roots = (double*) malloc(degree * sizeof(double));
    return roots;
}

NumberField *create_number_field(Polynomial *poly) {
    NumberField *nf = (NumberField*) malloc(sizeof(NumberField));
    nf->poly = poly;
    nf->roots = find_roots(poly);
    return nf;
}
int mains(void) {
    double coeffs[] = {1, 0, -1};  // x^2 - 1
    Polynomial* poly = create_polynomial(2, coeffs);
    NumberField* nf = create_number_field(poly);
    // Do something with the number field
    free(nf);
    free(poly);
    return 0;
}
