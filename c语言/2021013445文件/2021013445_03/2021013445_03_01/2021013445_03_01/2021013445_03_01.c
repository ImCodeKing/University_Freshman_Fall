#include <stdio.h>
int main() {
	unsigned long int m = 0;
	unsigned long int n = 0;
	scanf("%lu%lu", &m, &n);
	unsigned long int left = m << n;
	unsigned long int right = m >> (32 - n);
	unsigned long int solve = left | right;
	printf("%lu\n", solve);
	return 0;
}