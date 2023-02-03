#include <stdio.h>
int main(int argc, char* argv[])
{
	unsigned long long int Input = 0;
	unsigned long long int Idxmutiply = 1;
	unsigned long long int Output = 0;
	scanf("%llu", &Input);
	for (int i = 1; i <= Input; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			Idxmutiply *= j;
		}
		Output += Idxmutiply;
		Idxmutiply = 1;
	}
	printf("%llu", Output);
	return 0;
}