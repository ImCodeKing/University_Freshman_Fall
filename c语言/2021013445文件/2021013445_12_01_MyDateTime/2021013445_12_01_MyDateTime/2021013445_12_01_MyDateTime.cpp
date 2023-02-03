#include <iostream>
#include <iomanip>
#include "2021013445_12_01_MyDateTime.hpp"
using namespace std;
bool MyDateTime::SetDateTime(unsigned int Year, unsigned int Month, unsigned int Day, unsigned int Hour, unsigned int Minute, unsigned int Second)
{
	if (Year >= 0 && Year <= 9999)
	{
		if (Month >= 1 && Month <= 12)
		{
			if (Month == 1 || Month == 3 || Month == 5 || Month == 7 || Month == 8 || Month == 10 || Month == 12)
			{
				if (Day >= 1 && Day <= 31)
				{
					if (Hour >= 0 && Hour <= 23 && Minute >= 0 && Minute <= 59 && Second >= 0 && Second <= 59)
					{
						return true;
					}
					else
					{
						return false;
					}
				}
				else
				{
					return false;
				}
			}
			else if (Month == 2)
			{
				if ((Year % 400) == 0 || ((Year % 4) == 0 && (Year % 100) != 0))
				{
					if (Day >= 1 && Day <= 29)
					{
						if (Hour >= 0 && Hour <= 23 && Minute >= 0 && Minute <= 59 && Second >= 0 && Second <= 59)
						{
							return true;
						}
						else
						{
							return false;
						}
					}
					else
					{
						return false;
					}
				}
				else
				{
					if (Day >= 1 && Day <= 28)
					{
						if (Hour >= 0 && Hour <= 23 && Minute >= 0 && Minute <= 59 && Second >= 0 && Second <= 59)
						{
							return true;
						}
						else
						{
							return false;
						}
					}
					else
					{
						return false;
					}
				}
			}
			else if (Month == 4 || Month == 6 || Month == 9 || Month == 11)
			{
				if (Day >= 1 && Day <= 30)
				{
					if (Hour >= 0 && Hour <= 23 && Minute >= 0 && Minute <= 59 && Second >= 0 && Second <= 59)
					{
						return true;
					}
					else
					{
						return false;
					}
				}
				else
				{
					return false;
				}
			}
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}
MyDateTime:: MyDateTime(unsigned int Year, unsigned int Month, unsigned int Day, unsigned int Hour, unsigned int Minute, unsigned int Second)
{
	if (SetDateTime(Year, Month, Day, Hour, Minute, Second))
	{
		    MyYear = Year;
			MyMonth = Month;
			MyDay = Day;
			MyHour = Hour;
			MyMinute = Minute;
			MySecond = Second;
	}
	else
	{
		MyYear = 1999;
		MyMonth = 1;
		MyDay = 1;
		MyHour = 0;
		MyMinute = 0;
		MySecond = 0;
	}
}
MyDateTime::MyDateTime(const MyDateTime& MyTime)
{
	MyYear = MyTime.MyYear;
	MyMonth = MyTime.MyMonth;
	MyDay = MyTime.MyDay;
	MyHour = MyTime.MyHour;
	MyMinute = MyTime.MyMinute;
	MySecond = MyTime.MySecond;
}
MyDateTime::~MyDateTime()
{
	cout << setfill('0') << setw(4) << MyYear << '/' << setfill('0') << setw(2) << MyMonth << '/' << setfill('0') << setw(2) << MyDay << ' ' << setfill('0') << setw(2) << MyHour << ':' << setfill('0') << setw(2) << MyMinute << ':' << setfill('0') << setw(2) << MySecond << endl;
}