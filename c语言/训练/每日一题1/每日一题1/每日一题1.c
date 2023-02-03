#include <stdio.h>
#include <stdlib.h>
int main(int argc, char* argv[])
{
	unsigned int M = 0;
	unsigned int N = 0;
	scanf("%u%u", &M, &N);
	int* Array1 = (int*)calloc(M, sizeof(int));
	int* Array2 = (int*)calloc(N, sizeof(int));
	int* ArrayOutput = (int*)calloc(M + N, sizeof(int));
	unsigned long long Count = 0;
	for (unsigned int i = 0; i < M; i++)
	{
		scanf("%d", &Array1[i]);
	}
	for (unsigned int i = 0; i < N; i++)
	{
		scanf("%d", &Array2[i]);
	}
	for (unsigned int i = 0; i < M; i++)
	{
		for (unsigned int j = 0; j < N; j++)
		{
			if (Array1[i] == Array2[j])
			{
				ArrayOutput[Count] = Array1[i];
				Count++;
				break;
			}
		}
	}
	for (unsigned long long i = 0; i < Count; i++)
	{
		int Min = i;
		for (unsigned long long j = i + 1; j < Count; j++)
		{
			if (ArrayOutput[j] < ArrayOutput[Min])
			{
				Min = j;
			}
		}
		if (Min != i)
		{
			int Temp = ArrayOutput[i];
			ArrayOutput[i] = ArrayOutput[Min];
			ArrayOutput[Min] = Temp;
		}
	}
	for (unsigned long long i = 0; i < Count; i++)
	{
		printf("%d", ArrayOutput[i]);
	}
	return 0;
}