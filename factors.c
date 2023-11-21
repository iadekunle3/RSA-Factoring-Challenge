#include <stdio.h>
#include <stdlib.h>

void factorize(unsigned long n) {
    unsigned long p, q;
    for (p = 2; p * p <= n; p++) {
        if (n % p == 0) {
            q = n / p;
            printf("%lu=%lu*%lu\n", n, p, q);
            return;
        }
    }
    printf("%lu=%lu*%lu\n", n, 1UL, n);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: factors <file>\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    unsigned long n;
    while (fscanf(file, "%lu", &n) == 1) {
        factorize(n);
    }

    fclose(file);
    return 0;
}

