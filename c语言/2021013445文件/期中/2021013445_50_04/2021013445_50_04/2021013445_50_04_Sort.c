#include <stdio.h>
#include <stdlib.h>
#include "2021013445_50_04_Sort.h"
void Sort(float Array[], unsigned int From, unsigned int To)
{
	if (To == From)
	{
		printf("%f", Array[To]);
	}
	else
	{
		float max = -100000;
		for (int i = From; i <= To; i++)
		{
			if (Array[i] > max)
			{
				max = Array[i];
			}
		}
		for (int i = From; i <= To; i++)
		{
			if (Array[i] == max)
			{
				Array[i] = Array[To];
			}
		}
		printf("%f\n", max);
		Sort(Array, From, To - 1);
	}
}