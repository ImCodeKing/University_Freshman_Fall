#include <stdio.h>
#include <stdlib.h>
int main(int argc, char* argv[])
{
	char** martrix = NULL;
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
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			scanf("%c", *(martrix + i) + j);
		}
	}
	getchar();
	scanf("%c", &type);
	//?
	if (type == 'R')
	{
		for (int i = 0; i < col; i++)
		{
			for (int j = 0; j < row; j++)
			{
				printf("%c", *(*(martrix + row - j - 1) + i));
				if (j == row - 1)
				{
					printf("\n");
				}
			}
		}
	}
	else
	{
		for (int i = 0; i < col; i++)
		{
			for (int j = 0; j < row; j++)
			{
				printf("%c", *(*(martrix + j) + col - i - 1));
				if (j == row - 1)
				{
					printf("\n");
				}
			}
		}
	}
	for (int i = 0; i < row; i++)
	{
		free(*(martrix + i));
	}
	free(martrix);
	martrix = NULL;
	return 0;
}