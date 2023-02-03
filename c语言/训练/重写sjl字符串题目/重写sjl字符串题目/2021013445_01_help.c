#include <stdio.h>
#include <string.h>
#include "2021013445_01_help.h"
void Longest(char message[], char lword[])
{
	int CountMax = 0;
	for (int i = 0; message[i + 1] != '\0'; i++)
	{
		int Count = 0;
		for (int j = i; message[j] != ' ' && message[j] != '.' && message[j] != ','; j++)
		{
			Count++;
		}
		if (Count >= CountMax)
		{
			for (int k = 0; k < Count; k++)
			{
				lword[k] = message[i];
				i++;
			}
			CountMax = Count;
		}
		else
		{
			i += Count;
		}
	}
	printf("%s\n", lword);
}
void Freq(char message[], char fword[])
{
	char totalword[50][50] = { '\0' };
	int wordtimes[200] = { 0 };
	int i = 0;
	int k = -1;
	int count = -1;
	for (i = 0; i < 50; i++)
	{
		k = -1;
		for (int j = 0; j < 50; j++)
		{
			count++;
			if (message[count] != ',' && message[count] != '.' && message[count] != ' ' && message[count] != '\0')
			{
				k++;
				totalword[i][k] = message[count];
			}
			else if (message[count] == ',' || message[count] == '.' || message[count] == ' ')
			{
				if (count != 0)
				{
					break;
				}
			}
			else if (message[count] == '\0')
			{
				break;
			}
		}
	}
	for (int m = 0; m < i; m++)
	{
		for (int n = 0; n < i; n++)
		{
			if (*(totalword + m) + n == '\0')
			{
				break;
			}
			int real = -1;
			if (**(totalword + m) != '\0')
			{
				real = strcmp(*(totalword + m), *(totalword + m + n));
			}
			if (real == 0)
			{
				wordtimes[m]++;
			}
		}
		if (*(totalword + m) == '\0')
		{
			break;
		}
	}
	for (int p = 0; p < 50; p++)
	{
		for (int q = 0; q < 50; q++)
		{
			if (wordtimes[p] >= wordtimes[q])
			{
				int temp = 0;
				temp = wordtimes[p];
				wordtimes[p] = wordtimes[q];
				wordtimes[q] = temp;
				char tempword[50] = { '\0' };
				for (int s = 0; s < 50; s++)
				{
					tempword[s] = totalword[p][s];
					totalword[p][s] = totalword[q][s];
					totalword[q][s] = tempword[s];
				}
			}
		}
	}
	for (int y = 0; y < 50; y++)
	{
		fword[y] = totalword[0][y];
	}
	printf("%s\n", fword);
}
void Concat(char lword[], char fword[], char word[])
{
	int Count = 0;
	strcat(lword, fword);
	for (int i = 0; lword[i] != '\0'; i++)
	{
		for (int j = i; lword[j] != '\0'; j++)
		{
			if (lword[i] == lword[j] && i != j)
			{
				lword[j] = '.';
			}
		}
	}
	for (int i = 0; lword[i] != '\0'; i++)
	{
		if (lword[i] != '.')
		{
			word[Count] = lword[i];
			Count++;
		}
	}
}
void Encryption(char message[], char word[])
{
	char CodeOrg[27] = { '\0' };
	char Code[27] = { '\0' };
	int Count = 0;
	for (int i = 0; i < 26; i++)
	{
		CodeOrg[i] = 'a' + i;
	}
	strcpy(Code, word);
	for (int i = 0; word[i] != '\0'; i++)
	{
		for (int j = 0; j < 26; j++)
		{
			if (word[i] == CodeOrg[j])
			{
				CodeOrg[j] = '.';
			}
		}
	}
	for (int i = 0; i < 26; i++)
	{
		if (Code[i] == '\0')
		{
			if (CodeOrg[Count] != '.')
			{
				Code[i] = CodeOrg[Count];
				Count++;
			}
			else
			{
				for (int j = 0; CodeOrg[j + 1] != '.' && CodeOrg[j] == '.'; Count++, j++);
				{
					Count++;
					Code[i] = CodeOrg[Count];
					Count++;
				}
			}
		}
	}
	for (int i = 0; message[i] != '\0'; i++)
	{
		if (message[i] != ' ' && message[i] != ',' && message[i] != '.')
		{
			int Num = message[i] - 'a';
			message[i] = Code[Num];
		}
	}
	for (int i = 0; i < 26; i++)
	{
		printf("%c ", Code[i]);
	}
	printf("\n");
}