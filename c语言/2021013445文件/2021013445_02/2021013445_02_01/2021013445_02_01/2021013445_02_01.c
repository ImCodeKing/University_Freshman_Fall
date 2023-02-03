#include <stdio.h>
int main()
{
	int age = 0;
	scanf("%d", &age);
	const float YEAR = 3.156e7;
	float second = age * YEAR;
	printf("%e", second);
	return 0;
}