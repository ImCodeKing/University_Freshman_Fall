#include <stdio.h>
int main()
{
	float a = 0;
	float b = 0;
	float c = 0;
	scanf("%f%f%f", &a, &b, &c);
	if (a > b)
	{
		if (a > c)
		{
			printf("%f\n", a);
		}
		else
		{
			if (b > c)
			{
				printf("%f\n", b);
			}
			else
			{
				printf("%f\n", c);
			}
		}
	}
	else if (a < b)
	{
		if (a > c)
		{
			printf("%f\n", b);
		}
		else
		{
			if (b > c)
			{
				printf("%f\n", b);
			}
			else
			{
				printf("%f\n", c);
			}
		}
	}
	return 0;
}