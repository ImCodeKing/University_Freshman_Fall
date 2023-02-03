#include <stdio.h>
int main()
{
	int in = 0;
	scanf("%d", &in);
	int thousand = in / 1000;
	int hundred = (in / 100) % 10;
	int ten = (in / 10) % 10;
	int bit = in % 10;
	int change = 1000 * bit + 100 * ten + 10 * hundred + thousand;
	printf("%d", change);
	return 0;
}