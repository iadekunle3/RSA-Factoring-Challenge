#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

uint64_t gcd(uint64_t a, uint64_t b) {
	while (b != 0) {
		uint64_t t = b;
		b = a % b;
		a = t;
	}
	return a;
}

uint64_t pollards_rho(uint64_t n) {
	if (n % 2 == 0) return 2;
	uint64_t x = rand() % (n - 2) + 2;
	uint64_t y = x;
	uint64_t c = rand() % (n - 1) + 1;
	uint64_t d = 1;
	while (d == 1) {
		x = (x * x + c + n) % n;
		y = (y * y + c + n) % n;
		y = (y * y + c + n) % n;
		d = gcd(abs(x - y), n);
	}
	return d;
}

void factorize(uint64_t n) {
	if (n == 1) return;
	if (n % 2 == 0) {
		fprintf(stdout, "%" PRIu64 "=%" PRIu64 "*%" PRIu64 "\n", n, (uint64_t)2, n / 2);
		return;
	}
	uint64_t divisor = pollards_rho(n);
	if (divisor == n) {
		fprintf(stdout, "%" PRIu64 "=%" PRIu64 "*%" PRIu64 "\n", n, (uint64_t)1, n);
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

	uint64_t n;
	while (fscanf(file, "%" SCNu64, &n) == 1) {
		factorize(n);
	}

	fclose(file);
	return 0;
}

