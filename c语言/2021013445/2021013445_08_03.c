#include <stdio.h>
#include <stdlib.h>
int main(int argc, char* argv[])
{
	unsigned int j = 0;
	unsigned int i = 0;
	unsigned int N = 0;
	unsigned int M = 0;
	int* Pointer1 = NULL;
	int* Pointer2 = NULL;
	int* Pointer3 = NULL;
	scanf("%u%u", &N, &M);
	Pointer1 = (int*)malloc(N * sizeof(int));
	Pointer2 = (int*)malloc(M * sizeof(int));
	Pointer3 = (int*)malloc((M + N + 2) * sizeof(int));
	for (i = 0; i < N; i++)
	{
		scanf("%d", (Pointer1 + i));
	}
	for (i = 0; i < M; i++)
	{
		scanf("%d", (Pointer2 + i));
	}
	for (i = 1, j = 1; j <= M && i <= N;)
	{
		if (*(Pointer1 + i - 1) > *(Pointer2 + j - 1))
		{
			*(Pointer3 + i + j) = *(Pointer2 + j - 1);
			j++;
		}
		else
		{
			*(Pointer3 + i + j) = *(Pointer1 + i - 1);
			i++;
		}
	}
	if (i > N && j <= M)
	{
		free(Pointer1);
		for (; j <= M; j++)
		{
			*(Pointer3 + i + j) = *(Pointer2 + j - 1);
		}
		free(Pointer2);
	}
	else if (i <= N && j > M)
	{
		free(Pointer2);
		for (; i <= N; i++)
		{
			*(Pointer3 + i + j) = *(Pointer1 + i - 1);
		}
		free(Pointer1);
	}
	for (i = 2; i < M + N + 1; i++)
	{
		printf("%d", *(Pointer3 + i));
		printf(" ");
	}
	printf("%d", *(Pointer3 + i));
	return 0;
}