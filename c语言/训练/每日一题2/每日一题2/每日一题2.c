#include <stdio.h>
#include <stdlib.h>
int main(int argc, char* argv[])
{
	unsigned int Total = 0;
	unsigned int Count = 0;
	scanf("%u", &Total);
	int** Point = (int**)calloc(Total, sizeof(int*));
	for (unsigned int i = 0; i < Total; i++)
	{
		*(Point + i) = (int*)calloc(2, sizeof(int));
	}
	for (unsigned int i = 0; i < Total; i++)
	{
		scanf("%d%d", &Point[i][0], &Point[i][1]);
	}
	for (unsigned int i = 0; i < Total - 1; i++)
	{
		if (Point[i][0] < Point[i + 1][0] && Point[i][1] < Point[i + 1][1])
		{
			for (unsigned int j = 0; Point[i][0] != Point[i + 1][0] && Point[i][1] != Point[i + 1][1]; j++)
			{
				Count++;
				Point[i][0]++;
				Point[i][1]++;
			}
			if (Point[i][0] != Point[i + 1][0])
			{
				for (unsigned int j = 0; Point[i][0] != Point[i + 1][0]; j++)
				{
					Count++;
					Point[i][0]++;
				}
			}
			else if (Point[i][1] != Point[i + 1][1])
			{
				for (unsigned int j = 0; Point[i][1] != Point[i + 1][1]; j++)
				{
					Count++;
					Point[i][1]++;
				}
			}
			else
			{
				continue;
			}
		}
		else if (Point[i][0] > Point[i + 1][0] && Point[i][1] < Point[i + 1][1])
		{
			for (unsigned int j = 0; Point[i][0] != Point[i + 1][0] && Point[i][1] != Point[i + 1][1]; j++)
			{
				Count++;
				Point[i][0]--;
				Point[i][1]++;
			}
			if (Point[i][0] != Point[i + 1][0])
			{
				for (unsigned int j = 0; Point[i][0] != Point[i + 1][0]; j++)
				{
					Count++;
					Point[i][0]--;
				}
			}
			else if (Point[i][1] != Point[i + 1][1])
			{
				for (unsigned int j = 0; Point[i][1] != Point[i + 1][1]; j++)
				{
					Count++;
					Point[i][1]++;
				}
			}
			else
			{
				continue;
			}
		}
		else if (Point[i][0] > Point[i + 1][0] && Point[i][1] > Point[i + 1][1])
		{
			for (unsigned int j = 0; Point[i][0] != Point[i + 1][0] && Point[i][1] != Point[i + 1][1]; j++)
			{
				Count++;
				Point[i][0]--;
				Point[i][1]--;
			}
			if (Point[i][0] != Point[i + 1][0])
			{
				for (unsigned int j = 0; Point[i][0] != Point[i + 1][0]; j++)
				{
					Count++;
					Point[i][0]--;
				}
			}
			else if (Point[i][1] != Point[i + 1][1])
			{
				for (unsigned int j = 0; Point[i][1] != Point[i + 1][1]; j++)
				{
					Count++;
					Point[i][1]--;
				}
			}
			else
			{
				continue;
			}
		}
		else if (Point[i][0] < Point[i + 1][0] && Point[i][1] > Point[i + 1][1])
		{
			for (unsigned int j = 0; Point[i][0] != Point[i + 1][0] && Point[i][1] != Point[i + 1][1]; j++)
			{
				Count++;
				Point[i][0]++;
				Point[i][1]--;
			}
			if (Point[i][0] != Point[i + 1][0])
			{
				for (unsigned int j = 0; Point[i][0] != Point[i + 1][0]; j++)
				{
					Count++;
					Point[i][0]++;
				}
			}
			else if (Point[i][1] != Point[i + 1][1])
			{
				for (unsigned int j = 0; Point[i][1] != Point[i + 1][1]; j++)
				{
					Count++;
					Point[i][1]--;
				}
			}
			else
			{
				continue;
			}
		}
	}
	printf("%u", Count);
	return 0;
}