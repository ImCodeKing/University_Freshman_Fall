#include <stdio.h>
int main()
{
	int year = 0;
	scanf("%d", &year);
	int leap = year % 4;
	int hundred = year % 100;
	int century = year % 400;
	_Bool yes1 = leap;
	_Bool yes2 = hundred;
	_Bool yes3 = century;
	if (yes1 == 0)
	{
		if (yes2 == 0)
		{
			if (yes3 == 0)
			{
				printf("Is a leap year\n");
			}
			else
			{
				printf("Is not a leap year\n");
			}
		}
		else
		{
			printf("Is a leap year\n");
		}

	}
	else
	{
		printf("Is not a leap year\n");
	}
	return 0;
}