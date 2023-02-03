#include <stdio.h>
#include <stdlib.h>
void InputMatrix(int*** MatrixA, int*** MatrixB, int* m, int* n)
{
	int i;
	int Row;
	int Col;
	*MatrixA = (int**)calloc(*m, sizeof(int*));
	*MatrixB = (int**)calloc(*n, sizeof(int*));
	for (i = 0; i < *m; i++)
	{
		*(*MatrixA + i) = (int*)calloc(*n, sizeof(int));
	}
	for (i = 0; i < *n; i++)
	{
		*(*MatrixB + i) = (int*)calloc(*m, sizeof(int));
	}
	printf("ÇëÊäÈëA¾ØÕóÄÚÈÝ\n");
	for (Row = 0; Row < *m; Row++)
	{
		for (Col = 0; Col < *n; Col++)
		{
			scanf("%d", &((*MatrixA)[Row][Col]));
		}
	}
	printf("ÇëÊäÈëB¾ØÕóÄÚÈÝ\n");
	for (Row = 0; Row < *n; Row++)
	{
		for (Col = 0; Col < *m; Col++)
		{
			scanf("%d", &((*MatrixB)[Row][Col]));
		}
	}
}
void InputPosition(unsigned int* g, unsigned int* k, int m, int n)
{
	unsigned int IsRequested;
	printf("ÇëÊäÈëg¡¢k\n");
	scanf("%u%u", g, k);
	if (*g >= 0 && *g < m && *k >= 0 && *k < n)
	{
		IsRequested = 1;
	}
	else
	{
		IsRequested = 0;
	}
	while (IsRequested == 0)
	{
		printf("ÇëÖØÐÂÊäÈëg¡¢k\n");
		scanf("%u%u", g, k);
		if (*g >= 0 && *g < m && *k >= 0 && *k < n)
		{
			IsRequested = 1;
		}
		else
		{
			IsRequested = 0;
		}
	}
}
void MatrixMerge(int** MatrixA, int** MatrixB, int*** MatrixC, unsigned int g, unsigned int k, int m, int n)
{
	int Row;
	int Col;
	unsigned int MaxRow = 0;
	unsigned int MaxCol = 0;
	if (g + n < m - g)
	{
		MaxRow = m;
	}
	else
	{
		MaxRow = n + g;
	}
	if (k + m < n - k)
	{
		MaxCol = n;
	}
	else
	{
		MaxCol = m + k;
	}
	*MatrixC = (int**)calloc(MaxRow, sizeof(int*));
	for (Row = 0; Row < MaxRow; Row++)
	{
		*(*MatrixC + Row) = (int*)calloc(MaxCol + 1, sizeof(int*));
	}
	for (Row = 0; Row < m; Row++)
	{
		for (Col = 0; Col < n; Col++)
		{
			(*MatrixC)[Row][Col] = MatrixA[Row][Col];
		}
	}
	for (Row = 0; Row < MaxRow; Row++)
	{
		for (Col = 0; Col < MaxCol + 1; Col++)
		{
			printf("%d ", (*MatrixC)[Row][Col]);
		}
		printf("\n");
	}
	for (Row = g; Row < MaxRow; Row++)
	{
		for (Col = k; Col < MaxCol; Col++)
		{
			(*MatrixC)[Row][Col] += MatrixB[Row - g][Col - k];
		}
	}
}
int main(int argc, char* argv[])
{
	int m[1] = { 0 };
	int n[1] = { 0 };
	unsigned int g[1] = { 0 };
	unsigned int k[1] = { 0 };
	int** MatrixA = NULL;
	int** MatrixB = NULL;
	int** MatrixC = NULL;
	unsigned int MaxRow = 0;
	unsigned int MaxCol = 0;
	int Row = 0;
	int Col = 0;
	scanf("%d%d", m, n);
	InputMatrix(&MatrixA, &MatrixB, m, n);
	InputPosition(g, k, *m, *n);
	MatrixMerge(MatrixA, MatrixB, &MatrixC, *g, *k, *m, *n);
	if (*g + *n < *m - *g)
	{
		MaxRow = *m;
	}
	else
	{
		MaxRow = *n + *g;
	}
	if (*k + *m < *n - *k)
	{
		MaxCol = *n;
	}
	else
	{
		MaxCol = *m + *k;
	}
	for (Row = 0; Row < MaxRow; Row++)
	{
		for (Col = 0; Col < MaxCol + 1; Col++)
		{
			printf("%d ", MatrixC[Row][Col]);
		}
		printf("\n");
	}
	return 0;
}
