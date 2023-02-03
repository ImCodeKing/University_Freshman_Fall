#include <stdio.h>
#include "2021013445_08_01_StrTool.h"
int main(int argc, char* argv[])
{
	char string1[81] = { '\0' };
	char string2[81] = { '\0' };
	gets(string1);
	gets(string2);
	printf("%d", Search(string2, string1));
	return 0;
}