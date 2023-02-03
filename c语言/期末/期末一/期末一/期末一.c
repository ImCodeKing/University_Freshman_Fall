#include <stdio.h>
#include <string.h>
void Input(char* Str1, char* Str2, int* g, int* k)
{
	int LenthStr1;
	int LenthStr2;
	unsigned int IsRequested;
	gets(Str1);
	gets(Str2);
	scanf("%d%d", g, k);
	LenthStr1 = strlen(Str1);
	LenthStr2 = strlen(Str2);
	if (*g < 0 || *g >= LenthStr1 || *k <= 1 || *k > LenthStr2)
	{
		IsRequested = 0;
	}
	else
	{
		IsRequested = 1;
	}
	while (IsRequested == 0)
	{
		printf("请重新输入两个整数\n");
		scanf("%d%d", g, k);
		if (*g < 0 || *g >= LenthStr1 || *k <= 1 || *k > LenthStr2)
		{
			IsRequested = 0;
		}
		else
		{
			IsRequested = 1;
		}
	}
}
void Combine(char* Str1, char* Str2, char* Str3, int g)
{
	int i = 0;
	int LenthStr1;
	int LenthStr2;
	for (i = 0; i <= g; i++)
	{
		*(Str3 + i) = *(Str1 + i);
	}
	strcat(Str3, Str2);
	LenthStr1 = strlen(Str1);
	LenthStr2 = strlen(Str2);
	for (i = g + 1; i < LenthStr1; i++)
	{
		*(Str3 + LenthStr2 + i) = *(Str1 + i);
	}
}
void KReverse(char* Str3, int k)
{
	int i;
	int j;
	char Temp;
	int Count = 0;
	int LenthStr3;
	LenthStr3 = strlen(Str3);
	for (i = 0; LenthStr3 - (i * k) > k; i++)
	{
		Count = 0;
		if (k % 2 == 0)
		{
			for (j = i * k; j < j + (((i + 1) * k - j) / 2); j++)
			{
				Temp = *(Str3 + j);
				*(Str3 + j) = *(Str3 + (i + 1) * k - Count - 1);
				*(Str3 + (i + 1) * k - Count - 1) = Temp;
				Count++;
			}
		}
		else
		{
			for (j = i * k; j < j + ((((i + 1) * k) - j) / 2); j++)
			{
				Temp = *(Str3 + j);
				*(Str3 + j) = *(Str3 + (i + 1) * k - Count - 1);
				*(Str3 + (i + 1) * k - Count - 1) = Temp;
				Count++;
			}
		}
	}
}
int main(int argc, char* argv[])
{
	int g[1] = { 0 };
	int k[1] = { 0 };
	char Str1[101] = { '\0' };
	char Str2[101] = { '\0' };
	char Str3[201] = { '\0' };
	Input(Str1, Str2, g, k);
	Combine(Str1, Str2, Str3, *g);
	KReverse(Str3, *k);
	printf("%s", Str3);
	return 0;
}