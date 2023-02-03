#include<iostream>
#include<iomanip>
#include"2021013445_12_01_MyDateTime.hpp"
using namespace std;
int main(int argc, char* argv[])
{
	unsigned int TimeData[6] = { 0 };
	for (int i = 0; i < 6; i++)
	{
		cin >> *(TimeData + i);
	}
	MyDateTime* Time1 = new MyDateTime(TimeData[0], TimeData[1], TimeData[2], TimeData[3], TimeData[4], TimeData[5]);
	MyDateTime* Time2 = new MyDateTime(*Time1);
	delete Time2;
	delete Time1;
	return 0;
}