#include <stdio.h>
#include <stdlib.h>
int main(int argc, char* argv[])
{
	char** martrix = NULL;
	char** transpost = NULL;
	unsigned int row = 0;
	unsigned int col = 0;
	char type = '\0';
	//这之后不是应该没有空格了吗？scanf不会消除读入数据后的第一个white space？
	scanf("%u%u", &row, &col);
	getchar();
	martrix = (char**)calloc(row, sizeof(char*));
	for (int i = 0; i < row; i++)
	{
		*(martrix + i) = (char*)calloc(col, sizeof(char));
	}
	transpost = (char**)calloc(col, sizeof(char*));
	for (int i = 0; i < col; i++)
	{
		*(transpost + i) = (char*)calloc(row, sizeof(char));
	}
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			scanf("%c", *(martrix + i) + j);
		}
	}
	getchar();
	scanf("%c", &type);
	if (type == 'L')
	{
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				*(*(transpost + col - j - 1) + i) = *(*(martrix + i) + j);
			}
		}
	}
	else
	{
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				*(*(transpost + j) + row - i - 1) = *(*(martrix + i) + j);
			}
		}
	}
	for (int i = 0; i < col; i++)
	{
		for (int j = 0; j < row; j++)
		{
			printf("%c", *(*(transpost + i) + j));
			if (j == row - 1)
			{
				printf("\n");
			}
		}
	}
	for (int i = 0; i < row; i++)
	{
		free(*(martrix + i));
	}
	free(martrix);
	martrix = NULL;
	for (int i = 0; i < col; i++)
	{
		free(*(transpost + i));
	}
	free(transpost);
	transpost = NULL;
	return 0;
}