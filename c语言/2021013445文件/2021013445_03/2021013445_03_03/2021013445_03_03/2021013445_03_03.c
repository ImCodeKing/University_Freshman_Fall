#include <stdio.h>
int main()
{
	unsigned long int m = 0;
	unsigned long int n = 0;
	scanf("%lu%lu", &m, &n);
	unsigned long int left = m << (31 - n);
	unsigned long int solve = left >> 31;
	printf("%lu\n", solve);
	return 0;
}