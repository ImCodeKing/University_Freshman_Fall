#ifndef _2021013445_12_01_MYDATETIME_HPP_
#define _2021013445_12_01_MYDATETIME_HPP_
#include <iostream>
#include <iomanip>
using namespace std;
class MyDateTime
{
public:
	bool SetDateTime(unsigned int Year, unsigned int Month, unsigned int Day, unsigned int Hour, unsigned int Minute, unsigned int Second);
	MyDateTime(unsigned int Year = 1999u, unsigned int Month = 1u, unsigned int Day = 1u, unsigned int Hour = 0u, unsigned int Minute = 0u, unsigned int Second = 0u);
	MyDateTime(const MyDateTime& MyTime);
	~MyDateTime();
private:
	unsigned int MyYear;
	unsigned int MyMonth;
	unsigned int MyDay;
	unsigned int MyHour;
	unsigned int MyMinute;
	unsigned int MySecond;
};
#endif
