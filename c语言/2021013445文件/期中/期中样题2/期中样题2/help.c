#include <stdio.h>
#include "help.h"
int** InputMatrix(int m, int n)
{
	int** p;
	p = (int**)malloc(sizeof(int*) * m);
	for (int i = 0; i < m; i++)
		*(p + i) = (int*)malloc(sizeof(int) * n);
	return p;
}
int PrintMatrix(int** matrix, int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d ", *(*(matrix + i) + j));
		}
		printf("\n");
	}
}
void Rotation180(int** matrix, int m, int n)
{
	if (m == n)
	{
		int temp1 = 0;
		int temp2 = 0;
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (i < j)
				{
					temp1 = *(*(matrix + i) + j);
					temp2 = *(*(matrix + j) + i);
					*(*(matrix + i) + j) = temp2;
					*(*(matrix + j) + i) = temp1;
				}
			}
		}
		for (int k = 0; k < m; k++)
		{
			if (k < (m / 2))
			{
				temp1 = *(*(matrix + k) + k);
				*(*(matrix + k) + k) = *(*(matrix + (n - k - 1)) + (n - k - 1));
				*(*(matrix + (n - k - 1)) + (n - k - 1)) = temp1;
			}
		}
	}
	if (m != n)
	{
		;
	}
}
int** Corr2(int** matrix1, int** matrix2, int m1, int n1, int m2, int n2)
{
	int** roll = InputMatrix((m1 - m2 + 1), (n1 - n2 + 1));
	int num = 0;
	int num1 = 0;
	int num2 = 0;
	for (int i = 0; i < (m1 - m2 + 1); i++)
	{
		for (int j = 0; j < (n1 - n2 + 1); j++)
		{
			for (int k = 0; k < m2; k++)
			{
				for (int l = 0; l < n2; l++)
				{
					num1 = *(*(matrix1 + i + k) + j + l);
					num2 = *(*(matrix2 + k) + l);
					num += num1 * num2;
				}
			}
			*(*(roll + i) + j) = num;
			num = 0;
		}
	}
	PrintMatrix(roll, m1 - m2 + 1, n1 - n2 + 1);
	return roll;
}