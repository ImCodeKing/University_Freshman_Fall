#include <stdio.h>
int main(int argc, char* argv[])
{
	char first[80] = { '\0' };
	char second[80] = { '\0' };
	char third[80] = { '\0' };
	gets(first);
	gets(second);
	gets(third);
	if (strcmp(first, second) > 0)
	{
		if (strcmp(first, third) > 0)
		{
			if (strcmp(second, third) > 0)
			{
				printf("%s\n%s\n%s\n", first, second, third);
			}
			else
			{
				printf("%s\n%s\n%s\n", first, third, second);
			}
		}
		else
		{
			printf("%s\n%s\n%s\n", third, first, second);
		}
	}
	else
	{
		if (strcmp(second, third) > 0)
		{
			if (strcmp(first, third) > 0)
			{
				printf("%s\n%s\n%s\n", second, first, third);
			}
			else
			{
				printf("%s\n%s\n%s\n", second, third, first);
			}
		}
		else
		{
			printf("%s\n%s\n%s\n", third, second, first);
		}
	}
	return 0;
}