#include <stdio.h>
#include <stdlib.h>
int main(int argc, char* argv[])
{
	unsigned int Row = 0;
	unsigned int Col = 0;
	unsigned int Add = 0;
	scanf("%u%u%u", &Row, &Col, &Add);
	int* Matrix = (int*)calloc(Row * Col, sizeof(int));
	for (unsigned int i = 0; i < Add; i++)
	{
		unsigned int Adder = 0;
		scanf("%u", &Adder);
		Matrix[Adder]++;
	}
	for (unsigned int i = 0; i < Row; i++)
	{
		for (unsigned int j = 0; j < Col; j++)
		{
			printf("%d ", Matrix[(i * Col) + j]);
		}
		printf("\n");
	}
	return 0;
}