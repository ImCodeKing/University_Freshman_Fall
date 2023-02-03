#include <stdio.h>
int main(int argc, char* argv[])
{
	char str[80] = { '0' };
	gets(str);
	for (int i = 0; i <= 79; i++)
	{
		if (str[i] != 0)
		{
			if (str[i] <= 90)
			{
				str[i] = str[i] + 32;
			}
			else
			{
				str[i] = str[i] - 32;
			}
		}
	}
	printf("%s", str);
	return 0;
}