#include <stdio.h>
#include "HELP.h"
void Longest(char message[], char lword[])
{
	int countlast = 0;
	int countnew = 0;
	int count = -1;
	char lastword[50] = { '\0' };
	char newword[50] = { '\0' };
	for (int i = 0; i < 200; i++)
	{
		if (message[i] != ' ' && message[i] != ',' && message[i] != '.')
		{
			count++;
			newword[count] = message[i];
			countnew++;
		}
		else
		{
			if (countlast <= countnew)
			{
				for (int j = 0; j < countnew; j++)
				{
					lastword[j] = newword[j];
					newword[j] = '\0';
				}
				countlast = countnew;
				countnew = 0;
				count = -1;
			}
			else
			{
				countnew = 0;
				count = -1;
			}
		}
		if (message[i] == '.' && message[i + 1] == '\0')
		{
			break;
		}
	}
	for (int k = 0; k < countlast; k++)
	{
		lword[k] = lastword[k];
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
			/*if (*(totalword + m) + n == '\0')
			{
				break;
			}*/
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
	strcat(lword, fword);
	for (int i = 0; i < 50; i++)
	{
		if (lword[i] == '\0')
		{
			break;
		}
		for (int j = 0; j < 50; j++)
		{
			if (lword[i] == lword[j] && i != j)
			{
				lword[j] = '0';
			}
		    else if (lword[j] == '\0')
		    {
				break;
			}
		}
	}
	int count = -1;
	for (int k = 0; k < 50; k++)
	{
		if (lword[k] != '0')
		{
			count++;
			word[count] = lword[k];
		}
		else if (lword[k] == '\0')
		{
			break;
		}
	}
	printf("%s\n", word);
}
void Encryption(char message[], char word[])
{
	int count = 0;
	int count1 = -1;
	int count2 = 0;
	char aph[27] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
	char code[27] = { '\0' };
	for (count = 0; count < 27; count++)
	{
		if (word[count] != '\0')
		{
			code[count] = word[count];
		}
		else
		{
			break;
		}
	}
	for (int i = 0; i < 26; i++)
	{
		for (int j = 0; j < 26; j++)
		{
			if (code[i] == aph[j])
			{
				aph[j] = '0';
				break;
			}
		}
		if (code[i] == '\0')
		{
			break;
		}
	}
	for (int k = 0; k < 26; k++)
	{
		if (aph[k] != '0')
		{
			count1++;
			code[count + count1] = aph[k];
		}
	}
	for (int m = 0; m < 26; m++)
	{
		printf("%c ", code[m]);
	}
	for (int n = 0; n < 200; n++)
	{
		if (message[n] != ',' && message[n] != '.' && message[n] != ' ')
		{
			count2 = message[n] - 97;
			if (count2 < 0)
			{
				break;
			}
			message[n] = code[count2];
		}
	}
	printf("\n");
	printf("%s\0", message);
}