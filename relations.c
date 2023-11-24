#include <stdio.h>
#include <stdlib.h>

// Function to check if a number is in the factor base
int is_in_factor_base(int *factor_base, int n, int size) {
    for (int i = 0; i < size; i++) {
        if (factor_base[i] == n) {
            return 1;
        }
    }
    return 0;
}

// Function to find relations
int **find_relations(int *factor_base, int size) {
    int **relations = (int**) malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        relations[i] = (int*) malloc(size * sizeof(int));
        for (int j = 0; j < size; j++) {
            relations[i][j] = is_in_factor_base(factor_base, i * j, size);
        }
    }
    return relations;
}

int relation(void) {
    int size = 10;
    int *factor_base = (int*) malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        factor_base[i] = i + 1;
    }
    int **relations = find_relations(factor_base, size);
    // Do something with the relations
    for (int i = 0; i < size; i++) {
        free(relations[i]);
    }
    free(relations);
    free(factor_base);
    return 0;
}
