#include <stdio.h>
int main()
{
	unsigned long m = 0;
	unsigned long n = 0;
	unsigned long k = 0;
	unsigned long int value = 1;
	scanf("%lu%lu%lu", &m, &n, &k);
	if (k == 1)
	{
		unsigned long int transform = value << n;
		unsigned long int solve = transform | m;
		printf("%lu\n", solve);
	}
	else
	{
		unsigned long int transform = value << n;
		unsigned long int negetive = ~m;
		unsigned long int solve = transform | negetive;
		unsigned long int result = ~solve;
		printf("%lu\n", result);
	}
	return 0;
}
