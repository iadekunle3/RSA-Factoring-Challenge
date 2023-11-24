#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

long long unsigned int gcd(long long unsigned int a, long long unsigned int b) {
	while (b != 0) {
		long long unsigned int t = b;
		b = a % b;
		a = t;
	}
	return a;
}

long long unsigned int pollards_rho(long long unsigned int n) {
	if (n % 2 == 0) return 2;
	long long unsigned int x = rand() % (n - 2) + 2;
	long long unsigned int y = x;
	long long unsigned int c = rand() % (n - 1) + 1;
	long long unsigned int d = 1;
	while (d == 1) {
		x = (x * x + c + n) % n;
		y = (y * y + c + n) % n;
		y = (y * y + c + n) % n;
		d = gcd(abs(x - y), n);
	}
	return d;
}

void factorize(long long unsigned int n) {
	if (n == 1) return;
	if (n % 2 == 0) {
		fprintf(stdout, "%" PRIu64 "=%" PRIu64 "*%" PRIu64 "\n", n, (long long unsigned int)2, n / 2);
		return;
	}
	long long unsigned int divisor = pollards_rho(n);
	if (divisor == n) {
		fprintf(stdout, "%" PRIu64 "=%" PRIu64 "*%" PRIu64 "\n", n, (long long unsigned int)1, n);
	} else {
		fprintf(stdout, "%" PRIu64 "=%" PRIu64 "*%" PRIu64 "\n", n, divisor, n / divisor);
	}
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

	long long unsigned int n;
	while (fscanf(file, "%" SCNu64, &n) == 1) {
		factorize(n);
	}

	fclose(file);
	return 0;
}

