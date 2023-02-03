#include <stdio.h>
#include "2021013445_08_01_StrTool.h"
int StrLen(const char* Str)
{
	int count2 = 0;
	for (int count1 = 0; count1 < 80; count1++)
	{
		if (*(Str + count1) != '\0')
		{
			count2++;
		}
		else
		{
			break;
		}
	}
	return count2;
}
int SubString(const char* Str, char* Sub, unsigned int BeginIdx, unsigned int Len)
{
	for (int i = 0; i < Len; i++)
	{
		if (*(Str + i) != '\0')
		{
			*(Sub + i) = *(Str + BeginIdx + i);
		}
		else
		{
			return -1;
		}
	}
	return 0;
}
int Search(const char* Str, const char* Sub)
{
	int lenth = StrLen(Str);
	int reallenth = StrLen(Sub);
	int begin = -1;
	char* orgstring = Str;
	char sub1[81] = { '\0' };
	SubString(Sub, sub1, begin, lenth);
	for (int j = 0; j < reallenth; j++)
	{
		begin++;
		int real = SubString(Sub, sub1, begin, lenth);
		if (real == 0)
		{
			if (strcmp(orgstring, sub1) == 0)
			{
				return j;
			}
			else
			{
				continue;
			}
		}
		else
		{
			return -1;
		}
	}
	return -1;
}