#ifndef HEAD_H
#define HEAD_H

#include <stdio.h>
#include <complex.h>
#include <math.h>
#include <stdlib.h>

#define MAX_ITER 1000
#define EPSILON 1e-6

typedef struct {
    int degree;
    double *coeffs;
} Polynomial;

typedef struct {
    Polynomial *poly;
    double *roots;
} NumberField;

int linear(void);
int **find_relations(int *factor_base, int size);
int base(void);
double complex *aberth_method(double complex *coeffs, int degree);
double complex eval_poly(double complex *coeffs, int degree, double complex x);
NumberField *create_number_field(Polynomial *poly);
void gnfs(double n);
int is_prime(int n);
int *find_factor_base(int n);
int is_in_factor_base(int *factor_base, int n, int size);
void swap_rows(double **matrix, int r1, int r2, int cols);
double *solve_linear_system(double **matrix, int rows, int cols);
Polynomial *choose_polynomial(int degree);
double dot_product(double* vec1, double* vec2, int size);
double *conjugate_gradient(double **matrix, double *b, int size);
double *mat_vec_mul(double **matrix, double *vec, int size);
long long gcd(long long a, long long b);
Polynomial *create_polynomial(int degree, double* coeffs);
Polynomial *create_poly(int degree, double* coeffs);
long long pollards_rho(long long n);
void factorize_file(const char* filename);
double *lu_solve(double **LU, double *b, int size);
void lu_decomposition(double **matrix, int size);
void factorize(long long n);
int main(int argc, char** argv);
double *find_roots(Polynomial *poly);
int mains(void);
int find(void);
int relation(void);
#endif
