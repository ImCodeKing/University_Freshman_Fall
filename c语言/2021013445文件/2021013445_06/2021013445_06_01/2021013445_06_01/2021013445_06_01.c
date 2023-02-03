#include <stdio.h>
#include "2021013445_06_01_Convert.h"
int main(int argc, char* argv[])
{
	int input = 0;
	int type;
	scanf("%d%d", &input, &type);
	if (input == 0)
	{
		printf("0");
		exit(0);
	}
	if (type == 2)
	{
		Convert10to2(input);
	}
	else if (type == 8)
	{
		Convert10to8(input);
	}
	else if (type == 16)
	{
		Convert10to16(input);
	}
	return 0;
}
