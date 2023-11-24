#include <stdio.h>
#include <stdlib.h>

// Function to perform LU decomposition
void lu_decomposition(double **matrix, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i; j < size; j++) {
            double sum = 0;
            for (int k = 0; k < i; k++) {
                sum += (matrix[i][k] * matrix[k][j]);
            }
            matrix[i][j] -= sum;
        }
        for (int j = i + 1; j < size; j++) {
            double sum = 0;
            for(int k = 0; k < i; k++) {
                sum += (matrix[j][k] * matrix[k][i]);
            }
            matrix[j][i] = (matrix[j][i] - sum) / matrix[i][i];
        }
    }
}

// Function to solve a linear system using LU decomposition
double *lu_solve(double **LU, double *b, int size) {
    double *x = (double*) malloc(size * sizeof(double));
    double *y = (double*) malloc(size * sizeof(double));
    // Forward substitution
    for (int i = 0; i < size; i++) {
        double sum = 0;
        for (int k = 0; k < i; k++) {
            sum += LU[i][k] * y[k];
        }
        y[i] = b[i] - sum;
    }
    // Backward substitution
    for (int i = size - 1; i >= 0; i--) {
        double sum = 0;
        for (int k = i + 1; k < size; k++) {
            sum += LU[i][k] * x[k];
        }
        x[i] = (y[i] - sum) / LU[i][i];
    }
    free(y);
    return x;
}

int linear(void) {
    int size = 3;
    double **matrix = (double**) malloc(size * sizeof(double*));
    for (int i = 0; i < size; i++) {
        matrix[i] = (double*) malloc(size * sizeof(double));
        for (int j = 0; j < size; j++) {
            matrix[i][j] = i + j;
        }
    }
    double *b = (double*) malloc(size * sizeof(double));
    for (int i = 0; i < size; i++) {
        b[i] = i + 1;
    }
    lu_decomposition(matrix, size);
    double *x = lu_solve(matrix, b, size);
    printf("Solution: ");
    for (int i = 0; i < size; i++) {
        printf("%f ", x[i]);
    }
    printf("\n");
    for (int i = 0; i < size; i++) {
        free(matrix[i]);
    }
    free(matrix);
    free(b);
    free(x);
    return 0;
}

