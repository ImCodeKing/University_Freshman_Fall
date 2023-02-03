#include <stdio.h>
#include "2021013445_50_04_Sort.h"
void Sort(float Array[], unsigned int From, unsigned int To)
{
	int temp = 0;
	if (From == To)
	{
		return;
	}
	float maxi = 0;
	for (int i = From; i <= To; i++)
	{
		if (Array[i] >= maxi)
		{
			maxi = Array[i];
		}
	}
	for (int i = From; i <= To; i++)
	{
		if (Array[i] == maxi)
		{
			temp = Array[i];
			Array[i] = Array[To];
			Array[To] = temp;
		}
	}
	printf("%f", maxi);
	Sort(Array, From, To - 1);
}