#include <stdio.h>
#include "help.h"
int main(int argc, char* argv[])
{
	int m1 = 0;
	int n1 = 0;
	printf("输入图像矩阵的行数和列数:");
	scanf("%d%d", &m1, &n1);
	int** MatrixA = InputMatrix(m1, n1);
	printf("请依次输入矩阵的元素\n");
	for (int i = 0; i < m1; i++)
	{
		for (int j = 0; j < n1; j++)
		{
			scanf("%d", *(MatrixA + i) + j);
		}
	}
	int m2 = 0;
	int n2 = 0;
	printf("输入卷积核矩阵的行数和列数:");
	scanf("%d%d", &m2, &n2);
	int** MatrixB = InputMatrix(m2, n2);
	printf("请依次输入矩阵的元素\n");
	for (int i = 0; i < m2; i++)
	{
		for (int j = 0; j < n2; j++)
		{
			scanf("%d", *(MatrixB + i) + j);
		}
	}
	printf("旋转后的卷积核矩阵为\n");
	Rotation180(MatrixB, m2, n2);
	PrintMatrix(MatrixB, m2, n2);
	//Rotation180(MatrixB, m2, n2);
	int** Matrixroll = InputMatrix((m1 - m2 + 1), (n1 - n2 + 1));
	printf("卷积结果为\n");
	Matrixroll = Corr2(MatrixA, MatrixB, m1, n1, m2, n2);
	free(MatrixA);
	MatrixA = NULL;
	free(MatrixB);
	MatrixB = NULL;
	free(Matrixroll);
	Matrixroll = NULL;
	return 0;
}