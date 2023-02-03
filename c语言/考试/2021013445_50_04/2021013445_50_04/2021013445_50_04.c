#include <stdio.h>
#include"2021013445_50_04_Sort.h"
int main(int argc, char* argv[])
{
	int size = 0;
	int From = 0;
	int To = 0;
	scanf("%d%d%d", &size,&From,&To);
	int* array = (int*)calloc(size, sizeof(int));
	for (int i = 0; i < 210000000; i++)
	{
		scanf("%d", &array[i]);
	}
	Sort(array, From, To);
	return 0;
}