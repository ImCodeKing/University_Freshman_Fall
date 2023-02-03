#include <stdio.h>
#include <stdlib.h>
int Search(int** Matrix, int Total, int StartX, int StartY, int Count, int StartNum)
{
	if (StartNum != Matrix[StartX][StartY] || (StartX == Total - 1 && StartY == Total - 1))
	{
		return Count;
	}
	else
	{
		if (StartNum == Matrix[StartX][StartY])
		{
			Count++;
		}
		if (StartX == Total - 1)
		{
			return Search(Matrix, Total, StartX, StartY + 1, Count, StartNum);
		}
		else if (StartY == Total - 1)
		{
			return Search(Matrix, Total, StartX + 1, StartY, Count, StartNum);
		}
		else
		{
			return (Search(Matrix, Total, StartX, StartY + 1, Count, StartNum) + Search(Matrix, Total, StartX + 1, StartY, Count, StartNum));	
		}
	}
}
int main(int argc, char* argv[])
{
	int Total = 0;
	int Count = 0;
	int Counter = 0;
	scanf("%d", &Total);
	int** Map = (int**)calloc(Total, sizeof(int*));
	int* CountList = (int*)calloc(Total * Total, sizeof(int));
	for (int i = 0; i < Total; i++)
	{
		*(Map + i) = (int*)calloc(Total, sizeof(int));
	}
	for (int i = 0; i < Total; i++)
	{
		for (int j = 0; j < Total; j++)
		{
			scanf("%d", &Map[i][j]);
		}
	}
	for (int i = 0; i < Total; i++)
	{
		for (int j = 0; j < Total; j++)
		{
			CountList[Counter] = Search(Map, Total, i, j, Count, Map[i][j]);
			Counter++;
		}
	}
	int Max = CountList[0];
	for (int i = 0; i < Total * Total; i++)
	{
		if (Max < CountList[i])
		{
			Max = CountList[i];
		}
	}
	for (int i = 0; i < Total * Total; i++)
	{
		printf("%d ", CountList[i]);
	}
	printf("\n%d", Max);
	return 0;
}