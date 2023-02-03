#include <stdio.h>
int main()
{
	int cup = 0;
	scanf("%d", &cup);
	float pint = 0.5 * cup;
	int oz_av = 8 * cup;
	int tablespoon = 16 * cup;
	int teaspoon = 48 * cup;
	printf("%f pint\n%d oz.av\n%d tablespoon\n%d teaspoon\n", pint, oz_av, tablespoon, teaspoon);
	return 0;
}