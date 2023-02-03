#include <stdio.h>
#include <string.h>
#include "2021013445_01_help.h"
int main(int argc, char* argv[])
{
	char Message[201] = { '\0' };
	char Lword[201] = { '\0' };
	char Fword[201] = { '\0' };
	char Word[201] = { '\0' };
	gets(Message);
	Longest(Message, Lword);
	Freq(Message, Fword);
	Concat(Lword, Fword, Word);
	Encryption(Message, Word);
	printf("%s", Message);
	return 0;
}