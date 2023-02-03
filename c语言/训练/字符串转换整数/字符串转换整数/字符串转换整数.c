#include <stdio.h>
#include "help.h"
#include <string.h>
int main(int argc, char* argv[])
{
	char string[201] = { '\0' };
	int returnnum = 0;
	returnnum = myAtoi(string);
	if (returnnum != 0)
	{
		printf("%d", returnnum);
	}
	return 0;
}