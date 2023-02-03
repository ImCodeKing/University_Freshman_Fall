#include <stdio.h>
#include <stdlib.h>
unsigned int MaxDivide(unsigned int Left, unsigned int Right)
{
	if (Right == 0)
	{
		return Left;
	}
	else
	{
		return MaxDivide(Right, Left % Right);
	}
}
int main(int argc, char* argv[])
{
	unsigned int TypeTotal = 0;
	scanf("%u", &TypeTotal);
	unsigned long long Tube[2] = { 0 };
	scanf("%llu%llu", &Tube[0], &Tube[1]);
	unsigned long long* Split = calloc(TypeTotal, sizeof(unsigned long long));
	long long* Times = calloc(TypeTotal, sizeof(long long));
	int Flag = 0;
	unsigned long long Temp = 1;
	unsigned long long TubeTotal = 1;
	for (unsigned int i = 0; i < TypeTotal; i++)
	{
		scanf("%llu", &Split[i]);
	}
	for (unsigned long long i = 0; i < Tube[1]; i++)
	{
		TubeTotal *= Tube[0];
	}
	for (unsigned int i = 0; i < TypeTotal; i++)
	{
		unsigned int GCD = MaxDivide(Split[i], Tube[0]);
		if (Split[i] % (Tube[0] / GCD) != 0)
		{
			Times[i] = -1;
		}
		else
		{
			if (Split[i] % TubeTotal == 0)
			{
				*(Times + i) = 0;
			}
			else
			{
				for (unsigned int j = 0; Flag != -1; j++)
				{
					Temp *= Split[i];
					(*(Times + i))++;
					if (Temp % TubeTotal == 0)
					{
						Flag = -1;
					}
				}
			}
		}
	}
	if (Temp == -1)
	{
		printf("-1");
	}
	else
	{
		printf("%llu", Temp);
	}
	return 0;
}








































	/*Flag = 0;
	Temp = 1;
	

Temp = -1;
for (int i = 0; i < TypeTotal; i++)
{
	if (Temp == -1)
	{
		Temp = Times[i];
	}
	else
	{
		if (Times[i] < Temp && Times[i] != -1)
		{
			Temp = Times[i];
		}
	}
}
if (Temp == -1)
{
	printf("-1");
}
else
{
	printf("%llu", Temp);
}*/