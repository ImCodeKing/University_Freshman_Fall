#include <stdio.h>
#include "2021013445_06_01_Convert.h"
int dig[32] = { 0 };
int count1 = -1;
int count2;
int count3;
void Convert10to2(unsigned int n)
{
	if (n == 0)
	{
		for (count2 = 31; count2 >= 0; count2--)
		{
			if (dig[count2] != 0)
			{
				break;
			}
		}
		for (int count3 = count2; count3 >= 0; count3--)
		{
			printf("%d", dig[count3]);
		}
	}
	else
	{
		count1++;
		dig[count1] = n % 2;
		Convert10to2((n - (n % 2)) / 2);
	}
}
void Convert10to8(unsigned int n)
{
	if (n == 0)
	{
		for (count2 = 31; count2 >= 0; count2--)
		{
			if (dig[count2] != 0)
			{
				break;
			}
		}
		for (count3 = count2; count3 >= 0; count3--)
		{
			printf("%d", dig[count3]);
		}
	}
	else
	{
		count1++;
		dig[count1] = n % 8;
		Convert10to8((n - (n % 8)) / 8);
	}
}
void Convert10to16(unsigned int n)
{
	if (n == 0)
	{
		for (count2 = 31; count2 >= 0; count2--)
		{
			if (dig[count2] != 0)
			{
				break;
			}
		}
		for (count3 = count2; count3 >= 0; count3--)
		{
			if (dig[count3] <= 9)
			{
				printf("%d", dig[count3]);
			}
			else
			{
				printf("%c", dig[count3]);
			}
		}
	}
	else
	{
		count1++;
		dig[count1] = n % 16;
		if (dig[count1] == 10)
		{
			dig[count1] = 65;
		}
		else if (dig[count1] == 11)
		{
			dig[count1] = 66;
		}
		else if (dig[count1] == 12)
		{
			dig[count1] = 67;
		}
		else if (dig[count1] == 13)
		{
			dig[count1] = 68;
		}
		else if (dig[count1] == 14)
		{
			dig[count1] = 69;
		}
		else if (dig[count1] == 15)
		{
			dig[count1] = 70;
		}
		Convert10to16((n - (n % 16)) / 16);
	}
}