#include <stdio.h>
#include "HELP.h"
int main(int argc, char* argv[])
{
	char message[201] = { '\0' };
	char lword[50] = { '\0' };
	char fword[50] = { '\0' };
	char word[50] = { '\0' };
	gets(message);
	Longest(message, lword);
	Freq(message, fword);
	Concat(lword, fword, word);
	Encryption(message, word);
	return 0;
}
