#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long long gcd(long long a, long long b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

long long pollards_rho(long long n) {
	if (n % 2 == 0)
		return 2;
	long long x = rand() % (n - 2) + 2;
	long long y = x;
	long long c = rand() % (n - 1) + 1;
	long long d = 1;
	while (d == 1) {
		x = (x * x + c + n) % n;
		y = (y * y + c + n) % n;
		y = (y * y + c + n) % n;
		d = gcd(abs(x - y), n);
		if (d == n)
			return pollards_rho(n);
	}
	return d;
}

void factorize(long long n) {
	if (n == 1)
		return;
	if (n % 2 == 0) {
		printf("%lld=2*%lld\n", n, n / 2);
		return;
	}
	long long d = pollards_rho(n);
	printf("%lld=%lld*%lld\n", n, d, n / d);
}

int main(int argc, char *argv[]) {
	if (argc != 2) {
		printf("Usage: factors <file>\n");
		return 1;
	}

	FILE *file = fopen(argv[1], "r");
	if (file == NULL) {
		printf("Could not open file %s\n", argv[1]);
		return 1;
	}

	long long number;
	while (fscanf(file, "%lld", &number) == 1) {
		factorize(number);
	}

	fclose(file);
	return 0;
}
