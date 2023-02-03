#include <stdio.h>
#include <stdlib.h>
int main(int argc, char* argv[])
{
	unsigned int numN = 0;
	unsigned int numM = 0;
	scanf("%u%u", &numN, &numM);
	int* space = (int*)calloc((numM + numN), sizeof(int));
	for (unsigned int count1 = 0u; count1 < numM + numN; count1++)
	{
		scanf("%d", (space + count1));
	}
	for (unsigned int i = 0; i < numN + numM - 1; i++)
	{
		unsigned int Min = i;
		for (unsigned int j = i + 1; j < numN + numM; j++)
		{
			if (space[Min] > space[j])
			{
				Min = j;
			}
		}
		if (Min != i)
		{
			int temp = *(space + i);
			*(space + i) = *(space + Min);
			*(space + Min) = temp;
		}
	}
	for (unsigned int k = 0; k < (numN + numM - 1); k++)
	{
		printf("%d ", *(space + k));
	}
	printf("%d", *(space + numN + numM - 1));
	free(space);
	space = NULL;
	return 0;
}