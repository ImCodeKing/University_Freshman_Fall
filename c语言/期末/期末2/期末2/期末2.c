#include <stdio.h>
#include <stdlib.h>
void input(int m, int n, int** Matrix)
{
	int Row = 0;
	int Col = 0;
	for (Row = 0; Row < m; Row++)
	{
		*(Matrix + Row) = (int*)calloc(n, sizeof(int));
	}
	for (Row = 0; Row < m; Row++)
	{
		printf("请输入第%d行的值\n", Row);
		for (Col = 0; Col < n; Col++)
		{
			scanf("%d", &Matrix[Row][Col]);
		}
	}
}
void RowSort(int** Matrix, int m, int n)
{
	int k = 0;
	int i = 0;
	int j = 0;
	int Max = 0;
	int Temp;
	for (k = 0; k < m; k++)
	{
		for (i = 0; i < n; i++)
		{
			Max = i;
			for (j = i + 1; j < n; j++)
			{
				if (Matrix[k][j] > Matrix[k][Max])
				{
					Max = j;
				}
			}
			if (Max != i)
			{
				Temp = Matrix[k][Max];
				Matrix[k][Max] = Matrix[k][i];
				Matrix[k][i] = Temp;
			}
		}
	}
}
void MatrixSort(int** Matrix, int m, int n)
{
	int i = 0;
	int j = 0;
	int Max;
	int Temp;
	int* TempP = NULL;
	int* Add = (int*)calloc(m, sizeof(int));
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			*(Add + i) += Matrix[i][j];
		}
	}
	for (i = 0; i < m; i++)
	{
		Max = i;
		for (j = i + 1; j < m; j++)
		{
			if (Add[j] >Add[Max])
			{
				Max = j;
			}
		}
		if (Max != i)
		{
			Temp = Add[Max];
			TempP = Matrix[Max];
			Add[Max] = Add[i];
			Matrix[Max] = Matrix[i];
			Add[i] = Temp;
			Matrix[i] = TempP;
		}
	}
}
void print(int** Matrix, int m, int n)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%d ", Matrix[i][j]);
		}
		printf("\n");
	}
}
int main(int argc, char* argv[])
{
	char IsContinue = 'm';
	int** Matrix = NULL;
	int Row = 0;
	int Col = 0;
	while (IsContinue != '@')
	{
		scanf("%d%d", &Row, &Col);
		Matrix = (int**)calloc(Row, sizeof(int*));
		input(Row, Col, Matrix);
		RowSort(Matrix, Row, Col);
		MatrixSort(Matrix, Row, Col);
		print(Matrix, Row, Col);
		printf("是否继续？\n");
		getchar();
		scanf("%c", &IsContinue);
	}
	return 0;
}