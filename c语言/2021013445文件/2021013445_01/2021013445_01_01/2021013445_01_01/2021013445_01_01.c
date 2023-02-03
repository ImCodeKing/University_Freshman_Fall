#include <stdio.h>
int main(int argc, char* argv[]) 
{
	int Min = 0;
	printf("Input the min number:\n");
	scanf("%d", &Min);
	int Max = 0;
	printf("Input the max number:\n");
	scanf("%d", &Max);
	int Sum = 0;
	int Count = Max - Min + 1;
	Sum = Count * Min + Count * (Count - 1) / 2;
	printf("Sum is %d\n", Sum);
	return 0;
}