#include <iostream>
using namespace std;
int main(int argc, char* argv[])
{
	unsigned int Number = 1;
	unsigned int Input = 0;
	cin >> Input;
	unsigned int First = (Input - 1u) / 2u;
	unsigned int** Martrix = new unsigned int*[Input]();
	for (int i = 0; i < Input; i++)
	{
		*(Martrix + i) = new unsigned int[Input]();
	}
	unsigned int* Array = new unsigned int[(Input * Input) - 1];
	for (int i = 0; i < (Input * Input) - 1; i++)
	{
		Number++;
		Array[i] = Number;
	}
	Martrix[0][First] = 1u;
	for (int i = 0; i < (Input * Input) - 1; i++)
	{
		for (int Row = 0; Row < Input; Row++)
		{
			for (int Col = 0; Col < Input; Col++)
			{
				if (Martrix[Row][Col] == (Array[i] - 1))
				{
					if (Row == 0 && Col != (Input - 1))
					{
						Martrix[Input - 1][Col + 1] = Array[i];
					}
					else if (Row != 0 && Col == (Input - 1))
					{
						Martrix[Row - 1][0] = Array[i];
					}
					else if (Row == 0 && Col == (Input - 1))
					{
						Martrix[Row + 1][Col] = Array[i];
					}
					else if (Row != 0 && Col != (Input - 1))
					{
						if (Martrix[Row - 1][Col + 1] == 0)
						{
							Martrix[Row - 1][Col + 1] = Array[i];
						}
						else
						{
							Martrix[Row + 1][Col] = Array[i];
						}
					}
				}
			}
		}
	}
	for (int i = 0; i < Input; i++)
	{
		for (int j = 0; j < Input; j++)
		{
			cout << Martrix[i][j] << ' ';
			if (j == (Input - 1))
			{
				cout << '\n';
			}
		}
	}
	for (int i = 0; i < Input; i++)
	{
		delete[] * (Martrix + i);
	}
	delete[] Martrix;
	delete[] Array;
	return 0;
}