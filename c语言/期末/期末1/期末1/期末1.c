#include <stdio.h>
#include <string.h>
void inputStr(char* Input)
{
	gets(Input);
}
unsigned int inputSeq(char* Str, char* SeqStr)
{
	unsigned int IsRequested = 1;
	unsigned int LenthInput;
	unsigned int LenthSeqstr;
	int i = 0;
	int j = 0;
	int Count = 0;
	gets(SeqStr);
	LenthInput = strlen(Str);
	LenthSeqstr = strlen(SeqStr);
	if (LenthInput != LenthSeqstr)
	{
		IsRequested = 0;
		printf("重新输入\n");
		return IsRequested;
	}
	for (i = 0; i < LenthInput; i++)
	{
		Count = 0;
		for (j = 0; j < LenthSeqstr; j++)
		{
			if (SeqStr[j] - '0' >= LenthInput || SeqStr[j] - '0' < 0)
			{
				IsRequested = 0;
				printf("重新输入\n");
				return IsRequested;
			}
			if (SeqStr[j] - '0' == i)
			{
				Count++;
			}
			if (Count > 1)
			{
				IsRequested = 0;
				printf("重新输入\n");
				return IsRequested;
			}
		}
		if (Count == 0)
		{
			IsRequested = 0;
			printf("重新输入\n");
			return IsRequested;
		}
	}
	return IsRequested;
}
void mapping(char* Str, char* StrSeq, char* new_s)
{
	int i = 0; 
	int Temp;
	int j = 0;
	for (i = 0; Str[i] != '\0'; i++)
	{
		Temp = StrSeq[i] - '0';
		new_s[Temp] = Str[i];
	}
	for (j = 0; j < i; j++)
	{
		printf("%c", new_s[j]);
	}
}
int main(int argc, char* argv[])
{
	char Str[10] = { '\0' };
	char StrSeq[10] = { '\0' };
	char new_s[10] = { '\0' };
	char FirstInput = '.';
	unsigned int IsRequested = 1;
	while (FirstInput != '@')
	{
		Str[0] = FirstInput;
		inputStr(Str);
		IsRequested = inputSeq(Str, StrSeq);
		while (IsRequested == 0)
		{
			IsRequested = inputSeq(Str, StrSeq);
		}
		mapping(Str, StrSeq, new_s);
		printf("\n是否需要继续输入？\n");
		FirstInput = getchar();
	}
	return 0;
}