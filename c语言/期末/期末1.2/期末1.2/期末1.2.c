#include <stdio.h>
#include <stdlib.h>
void Input(int*** MatrixA, int*** MatrixB,int* CounterA,int* CounterB)
{
	int i = 0;
	int j = 0;
	int ZeroLineData = 0;
	int FirstLineData = 0;
	printf("«Î ‰»ÎMatrixA\n");
	scanf("%d%d", &ZeroLineData, &FirstLineData);
	for (j = 0; j < 2; j++)
	{
		*(*MatrixA + j) = (int*)calloc(1, sizeof(int));
		*(*MatrixB + j) = (int*)calloc(1, sizeof(int));
	}
	for (i = 0; ZeroLineData != 0; i++)
	{
		(*CounterA)++;
		if (i != 0)
		{
			for (j = 0; j < 2; j++)
			{
				*(*MatrixA + j) = (int*)realloc(*(*MatrixA + j), (i + 1) * sizeof(int));
			}
		}
		(*MatrixA)[0][i] = ZeroLineData;
		(*MatrixA)[1][i] = FirstLineData;
		scanf("%d%d", &ZeroLineData, &FirstLineData);
	}
	printf("«Î ‰»ÎMatrixB\n");
	scanf("%d%d", &ZeroLineData, &FirstLineData);
	for (i = 0; ZeroLineData != 0; i++)
	{
		(*CounterB)++;
		if (i != 0)
		{
			for (j = 0; j < 2; j++)
			{
				*(*MatrixB + j) = (int*)realloc(*(*MatrixB + j), (i + 1) * sizeof(int));
			}
		}
		(*MatrixB)[0][i] = ZeroLineData;
		(*MatrixB)[1][i] = FirstLineData;
		scanf("%d%d", &ZeroLineData, &FirstLineData);
	}
}
void Sort(int*** Matrix,int Counter)
{
	int i = 0;
	int j = 0;
	int Min;
	int Temp = 0;
	for (i = 0; i < Counter - 1; i++)
	{
		Min = i;
		for (j = i + 1; j < Counter; j++)
		{
			if ((*Matrix)[0][j] < (*Matrix)[0][Min])
			{
				Min = j;
			}
		}
		if (Min != i)
		{
			Temp = (*Matrix)[0][i];
			(*Matrix)[0][i] = (*Matrix)[0][Min];
			(*Matrix)[0][Min] = Temp;
			Temp = (*Matrix)[1][i];
			(*Matrix)[1][i] = (*Matrix)[1][Min];
			(*Matrix)[1][Min] = Temp;
		}
	}
}
void Merge(int** MatrixA, int** MatrixB, int*** MatrixC, int CounterA, int CounterB)
{
	int i = 0;
	int j = 0;
	int ToDelete = 0;
	for (j = 0; j < 2; j++)
	{
		*(*MatrixC + j) = (int*)calloc((CounterA + CounterB), sizeof(int));
	}
	for (j = 0; j < CounterA; j++)
	{
		(*MatrixC)[0][j] = MatrixA[0][j];
		(*MatrixC)[1][j] = MatrixA[1][j];
	}
	for (i = 0; i < CounterB; i++, j++)
	{
		(*MatrixC)[0][j] = MatrixB[0][i];
		(*MatrixC)[1][j] = MatrixB[1][i];
	}
	for (i = 0; i < (CounterA + CounterB); i++)
	{
		for (j = i; j < (CounterA + CounterB - i); j++)
		{
			if ((*MatrixC)[0][i] == (*MatrixC)[0][j])
			{
				(*MatrixC)[1][j] = ((*MatrixC)[1][i] + (*MatrixC)[1][j]) / 2;
				(*MatrixC)[0][i] = 0;
				(*MatrixC)[1][i] = 0;
				ToDelete++;
			}
		}
	}
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			printf("%d ", (*MatrixC)[j][i]);
		}
		printf("\n");
	}
	for (i = 0; i < 2; i++)
	{
		*(*MatrixC + i) = (int*)realloc(*(*MatrixC + i), (CounterA + CounterB - ToDelete) * sizeof(int));
	}
	Sort(MatrixC, CounterA + CounterB - ToDelete);
}
int main(int argc, char* argv[])
{
	int** MatrixA;
	int** MatrixB;
	int** MatrixC;
	int CounterA = 0;
	int CounterB = 0;
	MatrixA = (int**)calloc(2, sizeof(int*));
	MatrixB = (int**)calloc(2, sizeof(int*));
	MatrixC = (int**)calloc(2, sizeof(int*));
	Input(&MatrixA, &MatrixB, &CounterA, &CounterB);
	Sort(&MatrixA, CounterA);
	Sort(&MatrixB, CounterB);
	Merge(MatrixA, MatrixB, &MatrixC, CounterA, CounterB);
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			printf("%d ", MatrixC[j][i]);
		}
		printf("\n");
	}
	return 0;
}


/*
7 4
4 5
9 2
1 3
0 1
4 5
2 3
8 1
3 5
5 2
0 1
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			printf("%d ", MatrixA[j][i]);
		}
		printf("\n");
	}
*/