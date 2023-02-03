#include <stdio.h>
#include <stdlib.h>
int main(int argc, char* argv[])
{
	unsigned long long Total = 0ull;
	unsigned long long Bouns = 0ull;
	unsigned long long Price = 0ull;
	unsigned long long Cost = 0ull;
	unsigned int Type = 0u;
	unsigned long long Time = 0ull;
	unsigned long long SubCount = 0ull;
	scanf("%llu", &Total);
	unsigned long long* SubTime = calloc(Total, sizeof(unsigned long long));
	unsigned long long* SubPrice = calloc(Total, sizeof(unsigned long long));
	for (unsigned long long i = 0ull; i < Total; i++)
	{
		scanf("%u%llu%llu", &Type, &Price, &Time);
		if (Type == 0u)
		{
			Cost += Price;
			*(SubTime + SubCount) = Time;
			*(SubPrice + SubCount) = Price;
			SubCount++;
			Bouns++;
		}
		else
		{
			for (unsigned long long m = 0; m < Total; m++)
			{
				if (Bouns > 0)
				{
					if (*(SubTime + m) != 0)
					{
						if (Time - *(SubTime + m) <= 45ull && Time - *(SubTime + m) >= 0ull)
						{
							if (*(SubPrice + m) >= Price)
							{
								Bouns--;
								*(SubPrice + m) = 0ull;
								*(SubTime + m) = -1ull;
								break;
							}
						}
					}
					else
					{
						Cost += Price;
						break;
					}
				}
				else
				{
					Cost += Price;
					break;
				}
			}
		}
	}
	free(SubTime);
	free(SubPrice);
	printf("%llu", Cost);
	return 0;
}