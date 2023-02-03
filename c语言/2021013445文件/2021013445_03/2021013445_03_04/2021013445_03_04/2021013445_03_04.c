#include <stdio.h>
int main() {
	unsigned long int m = 0;
	unsigned long int n = 0;
	scanf("%lu%lu", &m, &n);
	unsigned long int value = 1;
	unsigned long int transform = value << n;
	unsigned long int solve = transform | m;
	printf("%lu\n", solve);
	return 0;
}