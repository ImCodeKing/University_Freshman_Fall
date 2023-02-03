#include <stdio.h>
#include "2021013445_06_03_Split.h"
int count = 0;
int count1;//用于计数XO总位数
int count2;
int countX = 0;
int countO = 0;
void Split(char input[])
{
	for (count1 = 0; count1 <= 10000; count1++)
	{
		if (input[count1] == 0)
		{
			break;
		}
	}
	if (count1 == 0)
	{
		count++;
		printf("%d", count);
	}
	else
	{
		if (countX == 0 || countO == 0 || countX != countO)
		{
			if (input[0] == 'X')
			{
				countX++;
				for (int j = 0; j <= count1; j++)
				{
					input[j] = input[j + 1];
				}
				Split(input);
			}
			else
			{
				countO++;
				for (int j = 0; j <= count1; j++)
				{
					input[j] = input[j + 1];
				}
				Split(input);
			}
		}
		else
		{
			count++;
			countO = 0;
			countX = 0;
			Split(input);
		}
	}
}