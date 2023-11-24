#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to check if a number is prime
int is_prime(int n) {
    if (n <= 1) {
        return 0;
    }
    if (n == 2) {
        return 1;
    }
    if (n % 2 == 0) {
        return 0;
    }
    for (int i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

// Function to find the factor base
int *find_factor_base(int n) {
    int *factor_base = (int*) malloc(n * sizeof(int));
    int count = 0;
    int i = 2;
    
    while (count < n) {
        if (is_prime(i)) {
            factor_base[count] = i;
            count++;
        }
        i++;
    }
    return factor_base;
}

int base(void) {
    int n = 10;
    int* factor_base = find_factor_base(n);
    printf("Factor base: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", factor_base[i]);
    }
    printf("\n");
    free(factor_base);
    return 0;
}
