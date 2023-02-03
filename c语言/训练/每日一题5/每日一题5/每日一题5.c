#include <stdio.h>
#include <stdlib.h>
#include "help.h"
int main(int argc, char* argv[])
{
	unsigned int Row1 = 0;
	unsigned int Col1 = 0;
	unsigned int Col2 = 0;
	scanf("%u%u%u", &Row1, &Col1, &Col2);
	float* Matrix1 = NULL;
	float* Matrix2 = NULL;
	int MatrixTimes1 = Create2DMatrix(&Matrix1, Row1, Col1);
	int MatrixTimes2 = Create2DMatrix(&Matrix2, Col1, Col2);
	float Total = 0;
	printf("%u %u\n", Row1, Col2);
	for (unsigned int i = 0; i < Row1; i++)
	{
		for (unsigned int k = 0; k < Col2; k++)
		{
			for (unsigned int j = 0; j < Col1; j++)
			{
				Total += *(Matrix1 + i * Col1 + j) * *(Matrix2 + j * Col2 + k);
			}
			printf("%f ", Total);
			Total = 0;
		}
		printf("\n");
	}
	return 0;
}