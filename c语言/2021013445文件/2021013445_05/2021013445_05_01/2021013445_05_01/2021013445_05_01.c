#include <stdio.h>
#include <stdlib.h>
#include "2021013445_05_01_GameCore.h"
int main(int argc, char* argv[])
{
	int iTarget = 0;
	if (argc == 2)
	{
		scanf("%d", &iTarget);
	}
	else
	{
		iTarget = MakeRandomTarget();
	}
	int iNumber = 0;
	int realinput = 0;
	int countAB[2] = { 0 };
	while (countAB[0] != 4)
	{
		countAB[0] = 0;
		countAB[1] = 0;
		realinput = Judge(iNumber);
		GetABCount(iTarget, realinput, countAB);
		if (countAB[0] == 4)
		{
			printf("Bingo!");
		}
		else
		{
			printf("%dA%dB\n", countAB[0], countAB[1]);
		}

	}
	return 0;
}
