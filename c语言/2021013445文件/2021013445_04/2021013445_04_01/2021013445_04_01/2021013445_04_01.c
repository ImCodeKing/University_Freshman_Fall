#include <stdio.h>
int main()
{
	unsigned int first = 0;
	unsigned int second = 0;
	unsigned int temp = 0;
	scanf("%u%u", &first, &second);
	while (first % second != 0)
	{
		temp = first % second;
		first = second;
		if (temp != 0)
		{
			second = temp;
		}
		else
		{
			break;
		}
	}
	printf("%u\n", second);
	return 0;
}