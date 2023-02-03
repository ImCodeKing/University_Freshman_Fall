#include <iostream>
using namespace std;
int Swap(int &Left, int &Right)
{
	if (Left > Right)
	{
		int Temp = Left;
		Left = Right;
		Right = Temp;
		return 1;
	}
	else
	{
		return 0;
	}
}
int main(int argc, char* argv[])
{
	unsigned int TotalPoint = 0;
	unsigned int TotalRectangle = 0;
	int IsSwaped = 0;
	int Area = 0;
	cin >> TotalPoint >> TotalRectangle;
	int* XPoint = new int[TotalPoint];
	int* YPoint = new int[TotalPoint];
	for (int i = 0; i < TotalPoint; i++)
	{
		cin >> XPoint[i] >> YPoint[i];
	}
	if (TotalRectangle == 1)
	{
		for (int i = 0; i < TotalPoint - 1; i++)
		{
			for (int j = 0; j < TotalPoint - i - 1; j++)
			{
				Swap(XPoint[j], XPoint[j + 1]);
				Swap(YPoint[j], YPoint[j + 1]);
			}
		}
		Area = (XPoint[TotalPoint - 1] - XPoint[0]) * (YPoint[TotalPoint - 1] - YPoint[0]);
		cout << Area << endl;
	}
	return 0;
}