#include <stdio.h>
#include <stdlib.h>
#include "2021013445_50_04_Sort.h"
int main(int argc, char* argv[])
{
	unsigned int size = 0;
	scanf("%u", &size);
	float* array = NULL;
	array = (float*)calloc(size, sizeof(float));
	for (int i = 0; i < size; i++)
	{
		scanf("%f", (array + i));
	}
	//0需不需要强制转unsigned int？
	Sort(array, 0, size - 1);
	return 0;
}