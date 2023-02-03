#include <stdio.h>
#include <stdlib.h>
int main(int argc, char* argv[])
{
	int Total = 0;
	int Each[50] = { 0 };
	int Temp[50] = { 0 };
	int Tempcount = 0;
	int Width = 0;
	int Takeout = 0;
	int count = 0;
	_Bool Isbreak = 0;
	int Realcount = 0;
	int Middle = 0;
	int Divide = 0;
	int Square = 0;
	scanf("%d%d", &Total, &Width);
	int Line = 2 * Width + 1;
	scanf("%d", &Takeout);
	for (int i = 0; i < Takeout; i++)
	{
		scanf("%d", &Each[i]);
	}
	int** Match = (int**)calloc((2 * Width + 1), sizeof(int*));
	for (int i = 0; i < (2 * Width + 1); i++)
	{
		*(Match + i) = (int*)calloc((2 * Width + 1), sizeof(int));
	}
	for (int i = 0; i < (2 * Width + 1); i++)
	{
		if (i % 2 == 0)
		{
			for (int j = 0; j < (2 * Width + 1); j++)
			{
				if (j % 2 == 0)
				{
					*(*(Match + i) + j) = 0;
				}
				else
				{
					*(*(Match + i) + j) = 1;
				}
			}
		}
		else
		{
			for (int j = 0; j < (2 * Width + 1); j++)
			{
				if (j % 2 == 0)
				{
					*(*(Match + i) + j) = 1;
				}
				else
				{
					*(*(Match + i) + j) = 0;
				}
			}
		}
	}
	for (int i = 0; i < (2 * Width + 1); i++)
	{
		for (int j = 0; j < (2 * Width + 1); j++)
		{
			printf("%d ", Match[i][j]);
			if (j == (2 * Width + 1) - 1)
			{
				printf("\n");
			}
		}
	}
	for (int k = 0; k < Takeout; k++)
	{
		for (int i = 0; i < (2 * Width + 1); i++)
		{
			if (Isbreak == 1)
			{
				Isbreak = 0;
				break;
			}
			for (int j = 0; j < (2 * Width + 1); j++)
			{
				Realcount++;
				if (*(*(Match + i) + j) == 1)
				{
					count++;
				}
				if (count == Each[k])
				{
					Temp[Tempcount] = Realcount;
					Tempcount++;
					Isbreak = 1;
					break;
				}
			}
		}
	}
	printf("\n");
	for (int i = 0; i < Takeout; i++)
	{
		Middle = Temp[i] % (2 * Width + 1);
		Divide = Temp[i] / (2 * Width + 1);
		*(*(Match + Divide) + Middle - 1) = 0;
	}
	for (int i = 0; i < (2 * Width + 1); i++)
	{
		for (int j = 0; j < (2 * Width + 1); j++)
		{
			printf("%d ", Match[i][j]);
			if (j == (2 * Width + 1) - 1)
			{
				printf("\n");
			}
		}
	}
	for (int i = 1; i < (2 * Width); i += 2)//1 * 1情况
	{
		for (int j = 0; j < (2 * Width - 1); j += 2)
		{
			if (Match[i][j] == 1)
			{
				if (Match[i - 1][j + 1] == 1 && Match[i + 1][j + 1] == 1 && Match[i][j + 2] == 1)
				{
					Square++;
				}
			}
		}
	}
	for (int i = 1; i < (2 * Width - 2); i += 2)//2 * 2情况
	{
		for (int j = 0; j < (2 * Width - 3); j += 2)
		{
			if (Match[i][j] == 1 && Match[i + 2][j] == 1)
			{
				if (Match[i - 1][j + 1] == 1 && Match[i - 1][j + 3] == 1 && Match[i + 3][j + 1] == 1 && Match[i + 3][j + 3] == 1 && Match[i][j + 4] == 1 && Match[i + 2][j + 4] == 1)
				{
					Square++;
				}
			}
		}
	}
	return 0;
}
int IsASquare()
{
	int Square = 0;
	if()
}