#ifndef _2021013445_12_01_MYDATETIME_HPP_
#define _2021013445_12_01_MYDATETIME_HPP_
#include <iostream>
#include "2021013445_12_01_MyDateTime.hpp"
using namespace std;
class MyDateTime
{
public:
	MyDateTime(unsigned int Year = 1999, unsigned int Month = 1, unsigned int Date = 1, unsigned int Hour = 0, unsigned int Minute = 0, unsigned int Second = 0);
	MyDateTime(const MyDateTime& Source);
	bool SetDateTime(unsigned int Year, unsigned int Month, unsigned int Date, unsigned int Hour, unsigned int Minute, unsigned int Second);
	virtual ~MyDateTime();
private:
	unsigned int Year;
	unsigned int Month;
	unsigned int Date;
	unsigned int Hour;
	unsigned int Minute;
	unsigned int Second;
};
#endif