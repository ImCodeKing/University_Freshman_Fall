#include <iostream>
#include "2021013445_13_01_Student.hpp"
#include <string>
using namespace std;
int main(int argc, char* argv[])
{
	int Total = 0;
	cin >> Total;
	Students* Student = new Students[Total];
	for (int i = 0; i < Total; i++)
	{
		cin >> Student[i];
	}
	for (int i = 0; i < Total - 1; i++)
	{
		int Max = i;
		for (int j = i + 1; j < Total; j++)
		{
			if (!(Student[Max] > Student[j]))
			{
				Max = j;
			}
		}
		if (Max != i)
		{
			Students Temp = Student[i];
			Student[i] = Student[Max];
			Student[Max] = Temp;
		}
	}
	for (int i = 0; i < Total; i++)
	{
		cout << Student[i];
	}
	return 0;
}