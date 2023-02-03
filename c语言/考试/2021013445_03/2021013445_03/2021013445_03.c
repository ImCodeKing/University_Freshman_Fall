#include <stdio.h>
int main(int argc, char* argv[])
{
	int row = 0;
	int col = 0;
	char type = '\0';
	char temp = '\0';
	scanf("%d%d", &row, &col);
	char** array = (char**)calloc(row, sizeof(char*));
	for (int i = 0; i < row; i++)
	{
		*(array + i) = (char*)calloc(col, sizeof(char));
	}
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			scanf("%c",array[i][j]);
		}
	}
	scanf("%c", &type);
	if (type == 'L')
	{
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				temp = *(*(array + i) + j);
				*(*(array + i) + j) = *(*(array + row - j - 1) + i);
				*(*(array + row - j - 1) + i) = temp;
			}
		}
	}
	else
	{
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				temp = *(*(array + i) + j);
				*(*(array + i) + j) = *(*(array + j) + col - i - 1);
				*(*(array + j) + col - i - 1) = temp;
			}
		}
	}
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf("%c", *(*(array + i) + j));
		}
		printf("\n");
	}
	for (int i = 0; i < row; i++) 
	{
		free(*(array + i));
	}
	free(array);
	return 0;
}
